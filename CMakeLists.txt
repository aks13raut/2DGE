cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

project(2dge)

#Add the files
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Add libraries

#sfml
set(SFML_DIR "external/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML REQUIRED graphics network audio window system)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

#spdlog
add_subdirectory(external/spdlog)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

#yaml-cpp
add_subdirectory(external/yaml-cpp)
target_link_libraries(${PROJECT_NAME} yaml-cpp)

#tmxlite
add_subdirectory(external/tmxlite/tmxlite)
target_link_libraries(${PROJECT_NAME} tmxlite)

#Copy resources
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})
