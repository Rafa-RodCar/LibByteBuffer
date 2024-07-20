cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(ByteBuffer)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 11)

# Agregar el directorio de los headers
include_directories(include)

# Crear la librería estática
add_library(ByteBuffer STATIC src/ByteBuffer.cpp)
