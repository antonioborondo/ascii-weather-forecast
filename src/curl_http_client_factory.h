#ifndef CURL_HTTP_CLIENT_FACTORY_H_
#define CURL_HTTP_CLIENT_FACTORY_H_

#include <memory>

#include "http_client.h"
#include "http_client_factory.h"

class CurlHttpClientFactory : public HttpClientFactory {
 public:
  ~CurlHttpClientFactory() noexcept override = default;

  std::unique_ptr<HttpClient> CreateHttpClient() const override;
};

#endif
