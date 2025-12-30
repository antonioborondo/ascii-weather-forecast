#ifndef URL_BUILDER_H_
#define URL_BUILDER_H_

#include <string>

class UrlBuilder {
 public:
  virtual ~UrlBuilder() noexcept = default;

  virtual std::string GetUrl() noexcept = 0;
};

#endif
