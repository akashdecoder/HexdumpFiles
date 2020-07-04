cmake_minimum_required(VERSION 3.16)
project(HexdumpFiles C)

set(CMAKE_C_STANDARD 99)

add_executable(HexdumpFiles main.c HexConverter/hexConverter.h HexConverter/hexConverter.c FileOperations/fileOperations.h FileOperations/fileOperations.c hex.h)