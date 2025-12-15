#include "wttrin_wrapper.h"

#include <string>
#include <string_view>

#include "http.h"
#include "http_exception.h"
#include "wttrin_wrapper_exception.h"

namespace {

std::string BuildUrl(std::string_view wttrin_options) {
  char url[256];
  sprintf(url, "https://wttr.in/%s", wttrin_options.data());
  return std::string{url};
}

}  // namespace

namespace wttrin_wrapper {

std::string GetWeatherForecast(std::string_view wttrin_options) {
  const auto url{BuildUrl(wttrin_options)};

  try {
    const auto weather_forecast{http::GetUrl(url)};
    return weather_forecast;
  } catch (const HttpException& e) {
    throw WttrinWrapperException(
        "failed to fetch weather forecast information from wttr.in");
  }
}

}  // namespace wttrin_wrapper
