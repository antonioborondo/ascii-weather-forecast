#ifndef MOCK_HTTP_CLIENT_H_
#define MOCK_HTTP_CLIENT_H_

#include "http_client.h"

#include <gmock/gmock.h>

class MockHttpClient : public HttpClient {
 public:
  MOCK_METHOD(std::string, GetUrl, (std::string_view), (override));
};

#endif
