cmake_minimum_required (VERSION 3.0)

SET (CMAKE_MODULE_PATH "./")


PROJECT (BIKE)



file (GLOB SOURCES "src/*.c" "src/*.h")

SET ( GCC_COVERAGE_LINK_FLAGS "-lbluetooth -lpthread")

SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

SET ( CMAKE_EXE_LINKER_FLAGS "${GCC_COVERAGE_LINK_FLAGS}" )

add_executable (Bike ${SOURCES})
target_link_libraries (Bike ${POCKETSPHINX_LIBRARIES} ${SPHINXBASE_LIBRARIES})
