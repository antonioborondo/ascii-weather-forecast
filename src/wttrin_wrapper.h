#ifndef WTTRIN_WRAPPER_H_
#define WTTRIN_WRAPPER_H_

#include <string>
#include <string_view>

namespace wttrin_wrapper {

std::string GetWeatherForecast(std::string_view wttrin_options);

}

#endif
