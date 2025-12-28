#ifndef HTTP_CLIENT_H_
#define HTTP_CLIENT_H_

#include <string>
#include <string_view>

class HttpClient {
 public:
  virtual ~HttpClient() = default;

  virtual std::string GetUrl(std::string_view url) = 0;
};

#endif
