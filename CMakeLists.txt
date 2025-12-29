cmake_minimum_required(VERSION 3.10)

project(RoadCrackDetection VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)

add_executable(RoadCrackDetection
    src/main.cpp
    src/preprocessing.cpp
    src/utils.cpp
    src/visualization.cpp
    src/crack_detection.cpp
    )

target_include_directories(RoadCrackDetection PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
    )


target_link_libraries(RoadCrackDetection ${OpenCV_LIBS})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)