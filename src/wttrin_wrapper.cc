#include "wttrin_wrapper.h"

#include <memory>
#include <string>
#include <string_view>

#include "http_client.h"
#include "http_client_exception.h"
#include "wttrin_wrapper_exception.h"

namespace {

std::string BuildUrl(std::string_view wttrin_options) {
  char url[256];
  sprintf(url, "https://wttr.in/%s", wttrin_options.data());
  return std::string{url};
}

}  // namespace

WttrinWrapper::WttrinWrapper(
    std::unique_ptr<HttpClientFactory> http_client_factory) noexcept
    : http_client_factory_{std::move(http_client_factory)} {}

std::string WttrinWrapper::GetWeatherForecast(
    std::string_view wttrin_options) const {
  const auto url{BuildUrl(wttrin_options)};
  try {
    auto http_client{http_client_factory_->CreateHttpClient()};
    const auto weather_forecast{http_client->GetUrl(url)};
    return weather_forecast;
  } catch (const HttpClientException& e) {
    throw WttrinWrapperException(
        "failed to fetch weather forecast information from wttr.in");
  }
}
