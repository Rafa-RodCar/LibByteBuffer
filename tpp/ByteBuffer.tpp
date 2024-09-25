#ifndef BYTEBUFFER_TPP
#define BYTEBUFFER_TPP

#include "ByteBuffer.h"
#include <cstring>
#include <iostream>
#include <string>
#include <limits>

template<typename T>
ByteBuffer& ByteBuffer::operator << (const T& data) {

    size_t dataSize = sizeof(T);

    if (HasSpaceFor(dataSize))
        AppendBytes(&data, dataSize);
    else // TODO: LogInfo
        std::cout << "Error on: operator << (const T& data)" << std::endl;

    return *this;
}

template<typename T>
ByteBuffer& ByteBuffer::operator >> (T& data) {

    size_t dataSize = sizeof(T);
    
    if (HasBytesFor(dataSize))
        ExtractBytes(&data, dataSize);
    else // TODO: LogInfo
        std::cout << "Error on: operator >> (T& data)" << std::endl;

    return *this;
}

inline ByteBuffer& ByteBuffer::operator << (const std::string& data) {

    size_t length = data.size();

    if (length < std::numeric_limits<uint16_t>::max()) {

        size_t totalSize = sizeof(uint16_t) + length;

        if (HasSpaceFor(totalSize)) {

            AppendBytes(&length, sizeof(uint16_t));
            AppendBytes(data.data(), length);
        }
        else // TODO: LogInfo
            std::cout << "Error on: operator << (const std::string& data)" << std::endl;
    }
    else // TODO: LogInfo
        std::cout << "Error on: operator << (const std::string& data)" << std::endl;

    return *this;
}

inline ByteBuffer& ByteBuffer::operator >> (std::string& data) {

    uint16_t length;

    if (HasBytesFor(sizeof(uint16_t))) {

        ExtractBytes(&length, sizeof(uint16_t));

        if (HasBytesFor(length)) {

            data.resize(length);
            ExtractBytes(&data[0], length);
        }
        else // TODO: LogInfo
            std::cout << "Error on: operator >> (std::string& data):length" << std::endl;
    }
    else // TODO: LogInfo
        std::cout << "Error on: operator >> (std::string& data):sizeof(size_t)" << std::endl;

    return *this;
}

#endif // BYTEBUFFER_TPP