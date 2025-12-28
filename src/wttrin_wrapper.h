#ifndef WTTRIN_WRAPPER_H_
#define WTTRIN_WRAPPER_H_

#include <memory>
#include <string>
#include <string_view>

#include "http_client.h"

class WttrinWrapper {
 public:
  WttrinWrapper(std::unique_ptr<HttpClient> http_client);

  std::string GetWeatherForecast(std::string_view wttrin_options) const;

 public:
  std::unique_ptr<HttpClient> http_client_;
};

#endif
