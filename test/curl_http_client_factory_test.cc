#include "curl_http_client_factory.h"

#include "curl_http_client.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(CurlHttpClientFactory, CreateHttpClientReturnsRightType) {
  CurlHttpClientFactory curl_http_client_factory;
  auto http_client{curl_http_client_factory.CreateHttpClient()};

  ASSERT_THAT(dynamic_cast<CurlHttpClient*>(http_client.get()), Not(IsNull()));
}
