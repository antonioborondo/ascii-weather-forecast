#ifndef CURL_HTTP_CLIENT_H_
#define CURL_HTTP_CLIENT_H_

#include <string>
#include <string_view>

#include "http_client.h"

class CurlHttpClient : public HttpClient {
 public:
  std::string GetUrl(std::string_view url) override;
};

#endif
