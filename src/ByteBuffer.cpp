#include "ByteBuffer.h"
#include <cstring>
#include <iostream>

// Buffer: [0 to 1]---------->[HEADER:     16bits], 
//         [2 to 3]---------->[ActualSize: 16bits],
//         [4 to bufferSize]->[Data:        8bits];

ByteBuffer::ByteBuffer(HeaderType header) 
    : bufferSize(headerSizeMap.at(header)) {
    
    buffer.resize(bufferSize);

    uint16_t headerValue = static_cast<uint16_t>(header);

    (*this) << headerValue; // Guardamos el valor del HEADER al principio del buffer
    (*this) << (uint16_t)0; // Reservamos espacio para bufferActualSize y guardamos el valor
}

void ByteBuffer::AppendBytes(const void* data, size_t size) {

    std::memcpy(&buffer[pointer], data, size);

    SaveStatus(size, true);
}

void ByteBuffer::ExtractBytes(void* data, size_t size) {

    std::memcpy(data, &buffer[pointer], size);

    SaveStatus(size);
}

void ByteBuffer::ResetPointer() {
    pointer = sizeof(uint16_t)  // Avanzamos hasta después del HEADER
            + sizeof(uint16_t); // Avanzamos hasta después del ActualSize
}

void ByteBuffer::CopyTo(ByteBuffer& other) const {

    other.buffer           = buffer;
    other.bufferSize       = bufferSize;
    other.bufferActualSize = bufferActualSize;
    other.ResetPointer();
}

void ByteBuffer::SaveActualSize() {

    std::memcpy(&buffer[2], &bufferActualSize, sizeof(uint16_t));
}

void ByteBuffer::SaveStatus(size_t size, bool bActualSize) {

    pointer += size;

    if (bActualSize) {
    
        bufferActualSize += size;

        SaveActualSize();
    }
}
