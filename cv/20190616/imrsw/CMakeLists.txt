cmake_minimum_required(VERSION 2.8)

# 引入 OpenCV 包
find_package(OpenCV REQUIRED)

# 头文件
include_directories(${OpenCV_INCLUDE_DIRS})


# 库文件
link_directories(${OpenCV_LIBRARY_DIRS})


project(untitled)
add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
