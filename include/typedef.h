#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <cstddef>
#include <cstdint>
#include <unordered_map>

typedef uint8_t byte;

typedef enum HeaderType : uint16_t {
    NO_HEAD_16, 
    NO_HEAD_32, 
    NO_HEAD_64, 
    NO_HEAD_128, 
    NO_HEAD_256,
    NO_HEAD_512, 
    NO_HEAD_1024, 
    NO_HEAD_2048, 
    NO_HEAD_4096, 
    NO_HEAD_8192, 
    HEADER_1, 
    HEADER_2, 
    HEADER_3, 
    HEADER_4, 
    HEADER_5,
    HEADER_6, 
    HEADER_7, 
    HEADER_8, 
    HEADER_9, 
    HEADER_10, 
    HEADER_COUNT
} HEADER_TYPE;

typedef enum BufferSize : uint16_t {
    SIZE_16   = 0x0010, 
    SIZE_32   = 0x0020, 
    SIZE_64   = 0x0040, 
    SIZE_128  = 0x0080, 
    SIZE_256  = 0x0100,
    SIZE_512  = 0x0200, 
    SIZE_1024 = 0x0400, 
    SIZE_2048 = 0x0800, 
    SIZE_4096 = 0x1000, 
    SIZE_8192 = 0x2000
} BUFFER_SIZE;

const std::unordered_map<HeaderType, BufferSize> headerSizeMap = {
    {NO_HEAD_16,    SIZE_16}, 
    {NO_HEAD_32,    SIZE_32}, 
    {NO_HEAD_64,    SIZE_64}, 
    {NO_HEAD_128,   SIZE_128},
    {NO_HEAD_256,   SIZE_256}, 
    {NO_HEAD_512,   SIZE_512}, 
    {NO_HEAD_1024,  SIZE_1024}, 
    {NO_HEAD_2048,  SIZE_2048},
    {NO_HEAD_4096,  SIZE_4096}, 
    {NO_HEAD_8192,  SIZE_8192},
    {HEADER_1,      SIZE_1024}, 
    {HEADER_2,      SIZE_1024}, 
    {HEADER_3,      SIZE_1024}, 
    {HEADER_4,      SIZE_1024},
    {HEADER_5,      SIZE_1024}, 
    {HEADER_6,      SIZE_1024}, 
    {HEADER_7,      SIZE_1024}, 
    {HEADER_8,      SIZE_1024},
    {HEADER_9,      SIZE_1024}, 
    {HEADER_10,     SIZE_1024}
};

#endif // TYPEDEF_H
