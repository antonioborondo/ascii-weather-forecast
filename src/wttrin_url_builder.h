#ifndef WTTRIN_URL_BUILDER_H_
#define WTTRIN_URL_BUILDER_H_

#include <string>
#include <string_view>

#include "url_builder.h"

class WttrinUrlBuilder : public UrlBuilder {
 public:
  explicit WttrinUrlBuilder(std::string_view wttrin_options) noexcept;

  ~WttrinUrlBuilder() noexcept override = default;

  std::string GetUrl() noexcept override;

 private:
  std::string wttrin_options_;
};

#endif
