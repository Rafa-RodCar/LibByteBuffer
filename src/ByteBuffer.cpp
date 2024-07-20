#include "ByteBuffer.h"
#include <cstring>
#include <iostream>

ByteBuffer::ByteBuffer(HeaderType header) {
    if (headerSizeMap.find(header) == headerSizeMap.end()) {
        throw std::invalid_argument("Invalid header type");
    }
    bufferSize = headerSizeMap.at(header);
    buffer.resize(bufferSize);
    uint32_t headerValue = static_cast<uint32_t>(header);
    std::memcpy(buffer.data(), &headerValue, sizeof(headerValue));
    pointer = 0;  // Mantener el puntero al inicio
    std::cout << "Constructor: Writing header value: " << headerValue << std::endl;
}

void ByteBuffer::CopyTo(ByteBuffer& other) const {
    other.buffer = buffer;
    other.pointer = 0;
    other.bufferSize = bufferSize;
}

void ByteBuffer::ResetPointer() {
    pointer = sizeof(uint32_t);  // Reiniciar al inicio de los datos, después del header
}

void ByteBuffer::AppendBytes(const void* data, size_t size) {
    std::memcpy(&buffer[pointer], data, size);
    pointer += size;
}

void ByteBuffer::ExtractBytes(void* data, size_t size) {
    std::memcpy(data, &buffer[pointer], size);
    pointer += size;
}