#ifndef HTTP_CLIENT_FACTORY_H_
#define HTTP_CLIENT_FACTORY_H_

#include <memory>

#include "http_client.h"

template <typename T>
std::unique_ptr<HttpClient> CreateHttpClient() {
  return std::make_unique<T>();
}

#endif
