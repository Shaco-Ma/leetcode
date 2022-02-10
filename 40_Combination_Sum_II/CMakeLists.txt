cmake_minimum_required(VERSION 3.5)

project(40)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

#add_subdirectory(class_base)
#add_subdirectory(class_derived)

aux_source_directory(./ PROJECT_SRCS)
add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

#include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/class_base/include ${PROJECT_SOURCE_DIR}/class_derived/include)

#target_link_libraries(${PROJECT_NAME} class_base class_derived)
#link_directories(class_base class_derived)
