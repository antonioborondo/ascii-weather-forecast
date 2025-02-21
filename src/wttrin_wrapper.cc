#include "wttrin_wrapper.h"

#include <curl/curl.h>

void wttrin_wrapper::GetWeatherForecast(const std::string& wttrin_options) {
  char url[256];
  sprintf(url, "https://wttr.in/%s", wttrin_options.c_str());

  const auto curl_handle{curl_easy_init()};
  if (curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_perform(curl_handle);
    curl_easy_cleanup(curl_handle);
  }
}
