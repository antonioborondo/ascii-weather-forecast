#include "wttrin_wrapper.h"

#include <memory>

#include "http_client_exception.h"
#include "mock_http_client.h"
#include "wttrin_url_builder.h"
#include "wttrin_wrapper_exception.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(WttrinWrapperTest, GetWeatherForecast) {
  const std::string wttrin_options{""};
  auto url_builder{std::make_unique<WttrinUrlBuilder>(wttrin_options)};

  const auto weather_forecast{"Sunny"};
  auto mock_http_client_factory = [&weather_forecast]() {
    auto mock_http_client{std::make_unique<MockHttpClient>()};
    EXPECT_CALL(*mock_http_client, GetUrl(_))
        .WillOnce(Return(weather_forecast));
    return mock_http_client;
  };

  WttrinWrapper wttrin_wrapper{std::move(url_builder),
                               mock_http_client_factory};

  ASSERT_EQ(weather_forecast, wttrin_wrapper.GetWeatherForecast());
}

TEST(WttrinWrapperTest, GetWeatherForecastThrowsException) {
  const std::string wttrin_options{""};
  auto url_builder{std::make_unique<WttrinUrlBuilder>(wttrin_options)};

  auto mock_http_client_factory = []() {
    auto mock_http_client{std::make_unique<MockHttpClient>()};
    const std::string exception_message{""};
    EXPECT_CALL(*mock_http_client, GetUrl(_))
        .WillOnce(Throw(HttpClientException(exception_message)));
    return mock_http_client;
  };

  WttrinWrapper wttrin_wrapper{std::move(url_builder),
                               mock_http_client_factory};

  ASSERT_THROW(wttrin_wrapper.GetWeatherForecast(), WttrinWrapperException);
}
