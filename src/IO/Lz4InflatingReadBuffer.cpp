#include "Lz4InflatingReadBuffer.h"

namespace DB
{
namespace ErrorCodes
{
    extern const int LZ4_DECODER_FAILED;
}

Lz4InflatingReadBuffer::Lz4InflatingReadBuffer(std::unique_ptr<ReadBuffer> in_, size_t buf_size, char * existing_memory, size_t alignment)
    : BufferWithOwnMemory<ReadBuffer>(buf_size, existing_memory, alignment), in(std::move(in_))
{
    input = std::make_shared<const char *>();
}

Lz4InflatingReadBuffer::~Lz4InflatingReadBuffer() = default;


bool Lz4InflatingReadBuffer::nextImpl()
{
    if (eof)
        return false;

    if (in_pos >= in_size)
    {
        in->nextIfAtEnd();
        input = reinterpret_cast<std::shared_ptr<const char *> &>(in->position());
        in_size = in->buffer().end() - in->position();
    }

    /// TODO: Create shared_ptr in constructor, similar to how it's done for input
    output = std::make_shared<char *>(reinterpret_cast<char *>(internal_buffer.begin()));
    out_size = internal_buffer.size();
    out_pos = 0;

    const int decompressed_size = LZ4_decompress_safe(*input, *output, in_size, out_size);

    if (decompressed_size < 0)
        throw Exception(ErrorCodes::LZ4_DECODER_FAILED, "Lz4 stream decoding failed", ErrorCodes::LZ4_DECODER_FAILED);

    in->position() = in->buffer().begin() + in_pos;
    working_buffer.resize(out_pos);

    if (in->eof())
    {
        eof = true;
        return !working_buffer.empty();
    }

    return true;
}

}
