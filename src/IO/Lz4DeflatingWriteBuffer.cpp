#include "Lz4DeflatingWriteBuffer.h"
#include <Common/Exception.h>
#include <Common/MemoryTracker.h>


namespace DB
{
namespace ErrorCodes
{
    extern const int LZ4_ENCODER_FAILED;
}

Lz4DeflatingWriteBuffer::Lz4DeflatingWriteBuffer(
    std::unique_ptr<WriteBuffer> out_, int /*compression_level*/, size_t buf_size, char * existing_memory, size_t alignment)
    : BufferWithOwnMemory<WriteBuffer>(buf_size, existing_memory, alignment), out(std::move(out_))
{
    lz4_stream = LZ4_createStream();
    src = nullptr;
    src_size = 0;
    dst = nullptr;
    dst_size = 0;
}

Lz4DeflatingWriteBuffer::~Lz4DeflatingWriteBuffer()
{
    MemoryTracker::LockExceptionInThread lock(VariableContext::Global);
    finish();

    LZ4_freeStream(lz4_stream);
}


void Lz4DeflatingWriteBuffer::nextImpl()
{
    if (!offset())
        return;

    src = reinterpret_cast<const char *>(working_buffer.begin());
//    src = "hello";
    src_size = offset();

    try
    {
//        do
//        {
            out->nextIfAtEnd();
            dst = reinterpret_cast<char *>(out->position());
            dst_size = out->buffer().end() - out->position();

            const int compressed_bytes = LZ4_compress_continue(lz4_stream, src, reinterpret_cast<char *>(out->position()), LZ4_COMPRESSBOUND(src_size));
            out->position() = out->buffer().end() - dst_size;

            std::cerr << " >>>>   after called compress"
                      << " src_size : " << src_size << " dst_size : " << dst_size <<  " src_pos : "  << " dst_pos: "  << " compressed bytes is : " << compressed_bytes <<  std::endl;
            if (compressed_bytes <= 0)
            {
                throw Exception(ErrorCodes::LZ4_ENCODER_FAILED, "Lz4 stream encoding failed", ErrorCodes::LZ4_ENCODER_FAILED);
            }

//        } while (out->position() == nullptr);
    }
    catch (...)
    {
        out->position() = out->buffer().begin();
        throw;
    }
}


void Lz4DeflatingWriteBuffer::finish()
{
    if (finished)
        return;

    try
    {
        finishImpl();
        out->finalize();
        finished = true;
    }
    catch (...)
    {
        out->position() = out->buffer().begin();
        finished = true;
        throw;
    }
}

void Lz4DeflatingWriteBuffer::finishImpl()
{
    next();

//    do
//    {
        out->nextIfAtEnd();

        //    src = reinterpret_cast<const char *>(working_buffer.begin());
        //    src_size = offset();
        //    src_pos = 0;

        dst = reinterpret_cast<char *>(out->position());
        dst_size = out->buffer().end() - out->position();

        out->position() = out->buffer().end() - dst_size;

        const int compressed_data_size = LZ4_compress_default(src,  reinterpret_cast<char *>(out->position()), src_size, dst_size);
        if (compressed_data_size < 0)
        {
            throw Exception(ErrorCodes::LZ4_ENCODER_FAILED, "Lz4 stream encoding failed", ErrorCodes::LZ4_ENCODER_FAILED);
        }

//    } while(dst_size == 0);
}

}
