#ifndef WTTRIN_WRAPPER_H_
#define WTTRIN_WRAPPER_H_

#include <functional>
#include <memory>
#include <string>
#include <string_view>

#include "http_client.h"

class WttrinWrapper {
 public:
  explicit WttrinWrapper(std::function<std::unique_ptr<HttpClient>()>
                             http_client_factory) noexcept;

  std::string GetWeatherForecast(std::string_view wttrin_options) const;

 public:
  std::function<std::unique_ptr<HttpClient>()> http_client_factory_;
};

#endif
