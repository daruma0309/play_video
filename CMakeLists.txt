cmake_minimum_required(VERSION 3.0.2)
project(play_video CXX)
add_compile_options(-std=c++11)

add_executable(play_video src/main.cpp)

find_package(OpenCV REQUIRED)

message(STATUS ${OpenCV_INCLUDE_DIRS})

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
  ${OpenCV_LIBRARIES}
)
