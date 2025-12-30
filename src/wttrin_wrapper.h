#ifndef WTTRIN_WRAPPER_H_
#define WTTRIN_WRAPPER_H_

#include <functional>
#include <memory>
#include <string>

#include "http_client.h"
#include "url_builder.h"

class WttrinWrapper {
 public:
  explicit WttrinWrapper(std::unique_ptr<UrlBuilder> url_builder,
                         std::function<std::unique_ptr<HttpClient>()>
                             http_client_factory) noexcept;

  std::string GetWeatherForecast() const;

 private:
  std::unique_ptr<UrlBuilder> url_builder_;
  std::function<std::unique_ptr<HttpClient>()> http_client_factory_;
};

#endif
