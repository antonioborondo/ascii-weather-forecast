#ifndef CURL_HTTP_CLIENT_H_
#define CURL_HTTP_CLIENT_H_

#include <string>
#include <string_view>

#include <curl/curl.h>

#include "http_client.h"

class CurlHttpClient : public HttpClient {
 public:
  CurlHttpClient();

  ~CurlHttpClient() noexcept;

  std::string GetUrl(std::string_view url) override;

 private:
  CURL* curl_handle_;
};

#endif
