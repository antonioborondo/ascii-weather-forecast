#include "curl_http_client.h"

#include <string>
#include <string_view>

#include <curl/curl.h>

#include "http_client_exception.h"

namespace {

size_t WriteToString(void* ptr, [[maybe_unused]] size_t size, size_t nmemb,
                     void* userdata) {
  auto response{static_cast<std::string*>(userdata)};
  response->append(static_cast<char*>(ptr), nmemb);
  return nmemb;
}

}  // namespace

std::string CurlHttpClient::GetUrl(std::string_view url) {
  struct CurlWrapper {
    CURL* handle{curl_easy_init()};

    ~CurlWrapper() noexcept { curl_easy_cleanup(handle); }
  } curl_wrapper;

  if (!curl_wrapper.handle) {
    throw HttpClientException("failed to initialize HTTP client");
  }

  curl_easy_setopt(curl_wrapper.handle, CURLOPT_URL, url.data());
  curl_easy_setopt(curl_wrapper.handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  curl_easy_setopt(curl_wrapper.handle, CURLOPT_WRITEFUNCTION, WriteToString);
  std::string response;
  curl_easy_setopt(curl_wrapper.handle, CURLOPT_WRITEDATA, &response);

  if (const auto curl_result{curl_easy_perform(curl_wrapper.handle)};
      curl_result != CURLE_OK) {
    throw HttpClientException("HTTP GET request failed");
  }

  return response;
}
