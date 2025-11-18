cmake_minimum_required(VERSION 3.25.1)

project(ascii-weather-forecast VERSION 1.2.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(
  src/version.h.in
  src/version.h
)

add_executable(ascii-weather-forecast
  src/main.cc
  src/options.cc
  src/wttrin_wrapper.cc
)

target_include_directories(ascii-weather-forecast
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/src
)

find_package(Boost COMPONENTS program_options REQUIRED)
find_package(CURL REQUIRED)

add_subdirectory(third_party/inifile-cpp)

target_link_libraries(ascii-weather-forecast
  PRIVATE
  Boost::program_options
  CURL::libcurl
  inicpp
)

include(GNUInstallDirs)

install(TARGETS ascii-weather-forecast DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CPack)
