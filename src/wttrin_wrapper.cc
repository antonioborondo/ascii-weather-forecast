#include "wttrin_wrapper.h"

#include <functional>
#include <memory>
#include <string>

#include "http_client.h"
#include "http_client_exception.h"
#include "url_builder.h"
#include "wttrin_wrapper_exception.h"

WttrinWrapper::WttrinWrapper(
    std::unique_ptr<UrlBuilder> url_builder,
    std::function<std::unique_ptr<HttpClient>()> http_client_factory) noexcept
    : url_builder_{std::move(url_builder)},
      http_client_factory_{std::move(http_client_factory)} {}

std::string WttrinWrapper::GetWeatherForecast() const {
  const auto url{url_builder_->GetUrl()};
  try {
    auto http_client{http_client_factory_()};
    const auto weather_forecast{http_client->GetUrl(url)};
    return weather_forecast;
  } catch (const HttpClientException& e) {
    throw WttrinWrapperException(
        "failed to fetch weather forecast information from wttr.in");
  }
}
