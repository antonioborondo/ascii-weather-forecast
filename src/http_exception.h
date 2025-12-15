#ifndef HTTP_EXCEPTION_H_
#define HTTP_EXCEPTION_H_

#include <exception>
#include <string>
#include <string_view>

class HttpException : public std::exception {
 public:
  explicit HttpException(std::string_view message) noexcept;

  const char* what() const noexcept override;

 private:
  std::string message_;
};

#endif
