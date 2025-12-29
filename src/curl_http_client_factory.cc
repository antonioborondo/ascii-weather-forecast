#include "curl_http_client_factory.h"

#include <memory>

#include "curl_http_client.h"
#include "http_client.h"

std::unique_ptr<HttpClient> CurlHttpClientFactory::CreateHttpClient() const {
  return std::make_unique<CurlHttpClient>();
}
