#ifndef HTTP_H_
#define HTTP_H_

#include <string>
#include <string_view>

namespace http {

std::string GetUrl(std::string_view url);

}

#endif
