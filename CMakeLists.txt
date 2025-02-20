cmake_minimum_required(VERSION 3.22.1)

project(ascii-weather-forecast VERSION 0.0.0)

find_package(CURL REQUIRED)

add_executable(ascii-weather-forecast src/main.cc)

target_link_libraries(ascii-weather-forecast PRIVATE CURL::libcurl)
