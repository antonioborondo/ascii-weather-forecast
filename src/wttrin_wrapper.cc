#include "wttrin_wrapper.h"

#include <string>
#include <string_view>

#include <curl/curl.h>

#include "wttrin_wrapper_exception.h"

namespace {

size_t WriteDataToString(void* ptr, [[maybe_unused]] size_t size, size_t nmemb,
                         void* userdata) {
  auto response{static_cast<std::string*>(userdata)};
  response->append(static_cast<char*>(ptr), nmemb);
  return nmemb;
}

}  // namespace

namespace wttrin_wrapper {

std::string GetWeatherForecast(std::string_view wttrin_options) {
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
  curl_easy_setopt(curl_wrapper.handle, CURLOPT_WRITEFUNCTION,
                   WriteDataToString);
  std::string response;
  curl_easy_setopt(curl_wrapper.handle, CURLOPT_WRITEDATA, &response);

  if (const auto curl_result{curl_easy_perform(curl_wrapper.handle)};
      curl_result != CURLE_OK) {
    throw WttrinWrapperException(
        "failed to fetch weather forecast information");
  }

  return response;
}

}  // namespace wttrin_wrapper
