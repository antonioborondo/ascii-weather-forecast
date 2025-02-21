#include <string>

#include "wttrin_wrapper.h"

int main(int argc, char** argv) {
  std::string options;
  if (argc > 1) {
    options = argv[1];
  }

  wttrin_wrapper::GetWeatherForecast(options);

  return 0;
}
