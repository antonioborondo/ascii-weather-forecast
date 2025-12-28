#ifndef HTTP_CLIENT_EXCEPTION_H_
#define HTTP_CLIENT_EXCEPTION_H_

#include <exception>
#include <string>
#include <string_view>

class HttpClientException : public std::exception {
 public:
  explicit HttpClientException(std::string_view message) noexcept;

  const char* what() const noexcept override;

 private:
  std::string message_;
};

#endif
