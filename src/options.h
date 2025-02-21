#ifndef OPTIONS_H_
#define OPTIONS_H_

#include <string>

namespace options {

void Set(const std::string& section, const std::string& key,
         const std::string& value);
std::string Get(const std::string& section, const std::string& key);

}  // namespace options

#endif
