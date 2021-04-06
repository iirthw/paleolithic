cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 14)
project(mini_json)

# Group CMake predefined targets in one VS folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#set(HEADER_FILES src/public/foo.h)
#set(IMPL_FILES src/main.cpp src/impl/foo.cpp)
set(SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES})

add_executable(${CMAKE_PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} 
                        PUBLIC
                        ${CMAKE_CURRENT_SOURCE_DIR}/public
                        )