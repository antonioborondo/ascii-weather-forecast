#include "wttrin_wrapper_exception.h"

WttrinWrapperException::WttrinWrapperException(
    std::string_view message) noexcept
    : message_{message} {}

const char* WttrinWrapperException::what() const noexcept {
  return message_.c_str();
}
