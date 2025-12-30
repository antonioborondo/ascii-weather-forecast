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
)

target_include_directories(ascii-weather-forecast
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/src
)

find_package(Boost COMPONENTS program_options REQUIRED)

target_link_libraries(ascii-weather-forecast
  PRIVATE
  ascii-weather-forecast-common
  Boost::program_options
)

add_library(ascii-weather-forecast-common
  src/curl_http_client.cc
  src/http_client_exception.cc
  src/options.cc
  src/wttrin_url_builder.cc
  src/wttrin_wrapper_exception.cc
  src/wttrin_wrapper.cc
)

find_package(CURL REQUIRED)

add_subdirectory(third_party/inifile-cpp)

target_link_libraries(ascii-weather-forecast-common
  PRIVATE
  CURL::libcurl
  inicpp
)

add_executable(ascii-weather-forecast-test
  test/curl_http_client_test.cc
  test/wttrin_url_builder_test.cc
  test/wttrin_wrapper_test.cc
)

target_include_directories(ascii-weather-forecast-test
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

find_package(GTest REQUIRED)

target_link_libraries(ascii-weather-forecast-test
  PRIVATE
  ascii-weather-forecast-common
  GTest::gmock
  GTest::gtest
  GTest::gtest_main
)

enable_testing()

add_test(NAME ascii-weather-forecast-test COMMAND ascii-weather-forecast-test)

include(GNUInstallDirs)

install(TARGETS ascii-weather-forecast DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CPack)
