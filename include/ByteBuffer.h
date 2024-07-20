#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H

#include <vector>
#include <string>
#include <stdexcept>
#include "typedef.h"
#include <iostream>

class ByteBuffer {
public:
    ByteBuffer(HeaderType header);

    template<typename T>
    ByteBuffer& operator<<(const T& data);
    ByteBuffer& operator<<(const std::string& data);

    template<typename T>
    ByteBuffer& operator>>(T& data);
    ByteBuffer& operator>>(std::string& data);

    void ResetPointer();
    void CopyTo(ByteBuffer& other) const;

    size_t GetSize() const { return bufferSize; }
    size_t GetPointerPosition() const { return pointer; }

    byte GetByte(size_t index) const { 
        if (index >= bufferSize) {
            throw std::out_of_range("Index out of range");
        }
        return buffer[index]; 
    }

private:
    std::vector<byte> buffer;
    size_t pointer = 0;
    size_t bufferSize;
    size_t bufferActualSize;

    void AppendBytes(const void* data, size_t size);
    void ExtractBytes(void* data, size_t size);

    bool HasSpaceFor(size_t size) const { return pointer + size <= bufferSize; }
};

#include "../tpp/ByteBuffer.tpp"

#endif // BYTEBUFFER_H