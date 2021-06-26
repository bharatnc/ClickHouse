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
}

Lz4DeflatingWriteBuffer::~Lz4DeflatingWriteBuffer() = default;


void Lz4DeflatingWriteBuffer::nextImpl()
{
    if (!offset())
        return;

    input = std::make_shared<const char *>(reinterpret_cast<const char *>(working_buffer.begin()));
    in_size = offset();
    in_pos = 0;
    try
    {
        bool ended = false;
        do
        {
            out->nextIfAtEnd();

            output = std::make_shared<char *>(reinterpret_cast<char *>(out->buffer().begin()));
            out_size = out->buffer().size();
            out_pos = out->offset();

            const int compressed_data_size = LZ4_compress_default(*input, *output, in_size, out_size);
            if (compressed_data_size <= 0)
            {
                throw Exception(ErrorCodes::LZ4_ENCODER_FAILED, "Lz4 stream encoding failed", ErrorCodes::LZ4_ENCODER_FAILED);
            }
            out->position() = out->buffer().begin() + out_pos;
            ended = (in_pos == in_size);
        } while (!ended);
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

    out->nextIfAtEnd();

    input = std::make_shared<const char *>(reinterpret_cast<const char *>(working_buffer.begin()));
    in_size = offset();
    in_pos = 0;

    output = std::make_shared<char *>(reinterpret_cast<char *>(out->buffer().begin()));
    out_size = out->buffer().size();
    out_pos = out->offset();

    const int compressed_data_size = LZ4_compress_default(*input, *output, in_size, out_size);
    if (compressed_data_size <= 0)
    {
        throw Exception(ErrorCodes::LZ4_ENCODER_FAILED, "Lz4 stream encoding failed", ErrorCodes::LZ4_ENCODER_FAILED);
    }

    out->position() = out->buffer().begin() + out_pos;
}

}
