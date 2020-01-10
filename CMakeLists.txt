cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

project(2dge)

#Add the files
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(framework ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Add libraries

#sfml
find_package(SFML REQUIRED graphics network audio window system)
target_link_libraries(framework ${SFML_LIBRARIES})

#spdlog
add_subdirectory(external/spdlog)
target_link_libraries(framework spdlog::spdlog)

#yaml-cpp
add_subdirectory(external/yaml-cpp)
target_link_libraries(framework yaml-cpp)


#Copy resources
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})
