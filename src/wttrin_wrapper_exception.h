#ifndef WTTRIN_WRAPPER_EXCEPTION_H_
#define WTTRIN_WRAPPER_EXCEPTION_H_

#include <exception>
#include <string>
#include <string_view>

class WttrinWrapperException : public std::exception {
 public:
  explicit WttrinWrapperException(std::string_view message) noexcept;

  const char* what() const noexcept override;

 private:
  std::string message_;
};

#endif
