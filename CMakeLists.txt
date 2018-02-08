cmake_minimum_required (VERSION 3.0)

SET (CMAKE_MODULE_PATH "./")

include(FindPocketSphinx.cmake)
include(FindSphinxBase.cmake)

PROJECT (BIKE)

find_package(SphinxBase REQUIRED)
find_package(PocketSphinx REQUIRED)
find_package(PkgConfig)
find_package(SWIG 3.0.7 REQUIRED)

include_directories(include)
include_directories(
	${SPHINXBASE_INCLUDE_DIRS}
	${POCKETSPHINX_INCLUDE_DIRS}
)

pkg_check_modules(SB REQUIRED sphinxbase>=5prealpha)
pkg_check_modules(PS REQUIRED pocketsphinx>=5prealpha)

add_subdirectory(sphinxbase)
add_subdirectory(pocketsphinx)

file (GLOB SOURCES "src/*.c" "src/*.h")

SET ( GCC_COVERAGE_LINK_FLAGS "-lbluetooth -lpthread")

SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

SET ( CMAKE_EXE_LINKER_FLAGS "${GCC_COVERAGE_LINK_FLAGS}" )

add_executable (Bike ${SOURCES})
target_link_libraries (Bike ${POCKETSPHINX_LIBRARIES} ${SPHINXBASE_LIBRARIES})
