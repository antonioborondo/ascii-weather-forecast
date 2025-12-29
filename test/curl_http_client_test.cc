#include "curl_http_client.h"

#include <string_view>

#include "http_client_exception.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std::literals;
using namespace testing;

TEST(CurlHttpClientTest, GetExistingUrlReturnsUrlContent) {
  CurlHttpClient curl_http_client;
  constexpr auto url{"http://example.com"sv};

  const auto actual_url_content{curl_http_client.GetUrl(url)};

  constexpr auto expected_url_content{"Example Domain"sv};
  ASSERT_THAT(actual_url_content, HasSubstr(expected_url_content));
}

TEST(CurlHttpClientTest, GetUnexistingUrlThrowsException) {
  CurlHttpClient curl_http_client;
  constexpr auto url{"http://domain.invalid"sv};

  ASSERT_THROW(curl_http_client.GetUrl(url), HttpClientException);
}
