cmake_minimum_required(VERSION 3.28)

project(dns_client_app VERSION 1.0 LANGUAGES CXX)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC)