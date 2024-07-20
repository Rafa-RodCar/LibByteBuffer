#ifndef BYTEBUFFER_TPP
#define BYTEBUFFER_TPP

#include "ByteBuffer.h"
#include <cstring>
#include <iostream>

template<typename T>
ByteBuffer& ByteBuffer::operator<<(const T& data) {
    size_t dataSize = sizeof(T);
    if (!HasSpaceFor(dataSize)) {
        throw std::overflow_error("Buffer overflow");
    }
    std::cout << "Writing data of size " << dataSize << " at position " << pointer << std::endl;
    AppendBytes(&data, dataSize);
    return *this;
}

template<typename T>
ByteBuffer& ByteBuffer::operator>>(T& data) {
    size_t dataSize = sizeof(T);
    if (pointer + dataSize > bufferSize) {
        throw std::underflow_error("Buffer underflow");
    }
    std::cout << "Reading data of size " << dataSize << " from position " << pointer << std::endl;
    ExtractBytes(&data, dataSize);
    return *this;
}

inline ByteBuffer& ByteBuffer::operator<<(const std::string& data) {
    size_t length = data.size();
    size_t totalSize = sizeof(size_t) + length;
    if (!HasSpaceFor(totalSize)) {
        throw std::overflow_error("Buffer overflow");
    }
    std::cout << "Writing string length " << length << " at position " << pointer << std::endl;
    AppendBytes(&length, sizeof(size_t));
    std::cout << "Writing string data of length " << length << " at position " << pointer << std::endl;
    AppendBytes(data.data(), length);
    return *this;
}

inline ByteBuffer& ByteBuffer::operator>>(std::string& data) {
    size_t length;
    if (pointer + sizeof(size_t) > bufferSize) {
        throw std::underflow_error("Buffer underflow when reading string length");
    }
    std::cout << "Reading string length from position " << pointer << std::endl;
    ExtractBytes(&length, sizeof(size_t));
    std::cout << "String length read: " << length << std::endl;
    if (pointer + length > bufferSize) {
        throw std::underflow_error("Buffer underflow when reading string data");
    }
    data.resize(length);
    std::cout << "Reading string data of length " << length << " from position " << pointer << std::endl;
    ExtractBytes(&data[0], length);
    return *this;
}

#endif // BYTEBUFFER_TPP