#include "ByteBuffer.h"
#include <cstring>
#include <iostream>

ByteBuffer::ByteBuffer(HeaderType header) 
    : bufferSize(headerSizeMap.at(header)) {
    
    buffer.resize(bufferSize);

    uint32_t headerValue = static_cast<uint32_t>(header);

    (*this) << headerValue; // Guardamos el HEADER al principio del buffer
    (*this) << (short)0;    // Reservamos espacio para bufferAltualSize

    SaveActualSize();
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
    pointer = sizeof(uint32_t)  // Avanzamos hasta después del HEADER
            + sizeof(uint16_t); // Avanzamos hasta después del ActrualSize
}

void ByteBuffer::CopyTo(ByteBuffer& other) const {

    other.buffer           = buffer;
    other.bufferSize       = bufferSize;
    other.bufferActualSize = bufferActualSize;
    other.ResetPointer();
}

void ByteBuffer::SaveActualSize() {

    std::memcpy(&buffer[4], &bufferActualSize, sizeof(uint16_t));
}

void ByteBuffer::SaveStatus(size_t size, bool bAltualSize) {

    pointer += size;

    if (bAltualSize) {
    
        bufferActualSize += size;

        SaveActualSize();
    }
}
