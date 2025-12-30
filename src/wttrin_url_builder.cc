#include "wttrin_url_builder.h"

#include <string>
#include <string_view>

WttrinUrlBuilder::WttrinUrlBuilder(std::string_view wttrin_options) noexcept
    : wttrin_options_{wttrin_options} {}

std::string WttrinUrlBuilder::GetUrl() noexcept {
  char url[256];
  sprintf(url, "https://wttr.in/%s", wttrin_options_.c_str());
  return std::string{url};
}
