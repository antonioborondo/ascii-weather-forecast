cmake_minimum_required(VERSION 3.22.1)

project(ascii-weather-forecast VERSION 1.0.0)

find_package(Boost COMPONENTS program_options REQUIRED)
find_package(CURL REQUIRED)

configure_file(
  src/version.h.in
  src/version.h
)

add_executable(ascii-weather-forecast
  src/main.cc
  src/wttrin_wrapper.cc
)

target_include_directories(ascii-weather-forecast
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/src
)

target_link_libraries(ascii-weather-forecast
  PRIVATE
  Boost::program_options
  CURL::libcurl
)

install(TARGETS ascii-weather-forecast DESTINATION bin)

include(CPack)
