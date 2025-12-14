#include "wttrin_wrapper.h"

#include <string_view>

#include <curl/curl.h>

#include "wttrin_wrapper_exception.h"

void wttrin_wrapper::GetWeatherForecast(std::string_view wttrin_options) {
  char url[256];
  sprintf(url, "https://wttr.in/%s", wttrin_options.data());

  struct CurlWrapper {
    CURL* handle{curl_easy_init()};

    ~CurlWrapper() noexcept { curl_easy_cleanup(handle); }
  } curl_wrapper;

  if (!curl_wrapper.handle) {
    throw WttrinWrapperException("failed to initialize query");
  }

  curl_easy_setopt(curl_wrapper.handle, CURLOPT_URL, url);
  curl_easy_setopt(curl_wrapper.handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

  if (const auto curl_result{curl_easy_perform(curl_wrapper.handle)};
      curl_result != CURLE_OK) {
    throw WttrinWrapperException(
        "failed to fetch weather forecast information");
  }
}
