#include "wttrin_wrapper.h"

#include <memory>

#include "http_client_exception.h"
#include "mock_http_client.h"
#include "wttrin_wrapper_exception.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;

TEST(WttrinWrapperTest, GetWeatherForecast) {
  const auto weather_forecast{"Sunny"};
  auto mock_http_client_factory = [&weather_forecast]() {
    auto mock_http_client{std::make_unique<MockHttpClient>()};
    EXPECT_CALL(*mock_http_client, GetUrl(_))
        .WillOnce(Return(weather_forecast));
    return mock_http_client;
  };

  WttrinWrapper wttrin_wrapper{mock_http_client_factory};
  const std::string wttrin_options{""};
  ASSERT_EQ(weather_forecast,
            wttrin_wrapper.GetWeatherForecast(wttrin_options));
}

TEST(WttrinWrapperTest, GetWeatherForecastThrowsException) {
  auto mock_http_client_factory = []() {
    auto mock_http_client{std::make_unique<MockHttpClient>()};
    const std::string exception_message{""};
    EXPECT_CALL(*mock_http_client, GetUrl(_))
        .WillOnce(Throw(HttpClientException(exception_message)));
    return mock_http_client;
  };

  WttrinWrapper wttrin_wrapper{mock_http_client_factory};

  const std::string wttrin_options{""};
  ASSERT_THROW(wttrin_wrapper.GetWeatherForecast(wttrin_options),
               WttrinWrapperException);
}
