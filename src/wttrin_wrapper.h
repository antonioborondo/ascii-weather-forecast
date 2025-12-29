#ifndef WTTRIN_WRAPPER_H_
#define WTTRIN_WRAPPER_H_

#include <memory>
#include <string>
#include <string_view>

#include "http_client_factory.h"

class WttrinWrapper {
 public:
  explicit WttrinWrapper(
      std::unique_ptr<HttpClientFactory> http_client_factory) noexcept;

  std::string GetWeatherForecast(std::string_view wttrin_options) const;

 public:
  std::unique_ptr<HttpClientFactory> http_client_factory_;
};

#endif
