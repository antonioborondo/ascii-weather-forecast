#include "http_client_exception.h"

HttpClientException::HttpClientException(std::string_view message) noexcept
    : message_{message} {}

const char* HttpClientException::what() const noexcept {
  return message_.c_str();
}
