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

WttrinWrapper::WttrinWrapper(std::unique_ptr<HttpClient> http_client)
    : http_client_{std::move(http_client)} {}

std::string WttrinWrapper::GetWeatherForecast(
    std::string_view wttrin_options) const {
  const auto url{BuildUrl(wttrin_options)};
  try {
    const auto weather_forecast{http_client_->GetUrl(url)};
    return weather_forecast;
  } catch (const HttpClientException& e) {
    throw WttrinWrapperException(
        "failed to fetch weather forecast information from wttr.in");
  }
}
