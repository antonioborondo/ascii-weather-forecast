#include "http_exception.h"

HttpException::HttpException(std::string_view message) noexcept
    : message_{message} {}

const char* HttpException::what() const noexcept { return message_.c_str(); }
