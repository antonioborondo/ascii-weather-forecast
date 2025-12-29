#ifndef HTTP_CLIENT_FACTORY_H_
#define HTTP_CLIENT_FACTORY_H_

#include <memory>

#include "http_client.h"

class HttpClientFactory {
 public:
  virtual ~HttpClientFactory() noexcept = default;

  virtual std::unique_ptr<HttpClient> CreateHttpClient() const = 0;
};

#endif
