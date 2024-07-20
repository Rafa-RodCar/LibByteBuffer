#ifndef BYTEBUFFER_TPP
#define BYTEBUFFER_TPP

#include "ByteBuffer.h"
#include <cstring>
#include <iostream>
#include <string>

template<typename T>
ByteBuffer& ByteBuffer::operator << (const T& data) {

    size_t dataSize = sizeof(T);

    if (HasSpaceFor(dataSize))
        AppendBytes(&data, dataSize);
    else // TODO: LogError
        std::cout << "Error on: operator << (const T& data)" << std::endl;

    return *this;
}

template<typename T>
ByteBuffer& ByteBuffer::operator >> (T& data) {

    size_t dataSize = sizeof(T);
    
    if (HasBytesFor(dataSize))
        ExtractBytes(&data, dataSize);
    else // TODO: LogError
        std::cout << "Error on: operator >> (T& data)" << std::endl;

    return *this;
}

inline ByteBuffer& ByteBuffer::operator << (const std::string& data) {

    size_t length = data.size();
    size_t totalSize = sizeof(size_t) + length;

    if (HasSpaceFor(totalSize)) {

        AppendBytes(&length, sizeof(size_t));
        AppendBytes(data.data(), length);
    }
    else // TODO: LogError
        std::cout << "Error on: operator << (const std::string& data)" << std::endl;

    return *this;
}

inline ByteBuffer& ByteBuffer::operator >> (std::string& data) {

    size_t length;

    if (HasBytesFor(sizeof(size_t))) {

        ExtractBytes(&length, sizeof(size_t));

        if (HasBytesFor(length)) {

            data.resize(length);
            ExtractBytes(&data[0], length);
        }
        else // TODO: LogError
            std::cout << "Error on: operator >> (std::string& data):length" << std::endl;
    }
    else // TODO: LogError
        std::cout << "Error on: operator >> (std::string& data):sizeof(size_t)" << std::endl;

    return *this;
}

#endif // BYTEBUFFER_TPP