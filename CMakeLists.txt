cmake_minimum_required (VERSION 3.0)

PROJECT (BIKE)

file (GLOB SOURCES "src/*.c" "src/*.h")

SET ( GCC_COVERAGE_LINK_FLAGS	"-lbluetooth")

SET ( CMAKE_EXE_LINKER_FLAGS "${GCC_COVERAGE_LINK_FLAGS}" )

add_executable (Bike ${SOURCES})
