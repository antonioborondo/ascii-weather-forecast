#include "wttrin_wrapper.h"

#include <memory>

#include "http_client_factory.h"
#include "mock_http_client.h"

#include <gtest/gtest.h>

using namespace testing;

TEST(WttrinWrapperTest, GetWeatherForecast) {
  auto mock_http_client_factory = []() {
    auto mock_http_client{std::make_unique<MockHttpClient>()};
    EXPECT_CALL(*mock_http_client, GetUrl(_)).WillOnce(Return("Sunny"));
    return mock_http_client;
  };

  WttrinWrapper wttrin_wrapper{mock_http_client_factory};
  ASSERT_EQ("Sunny", wttrin_wrapper.GetWeatherForecast(""));
}
