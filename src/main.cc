#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "wttrin_wrapper.h"

namespace po = boost::program_options;

int main(int argc, char** argv) {
  po::options_description options_description("Options");
  options_description.add_options()
      // clang-format off
      ("wttrin-options,w", po::value<std::string>()->default_value(""), "wttr.in options.")
      ("help,h", "Display help.")
      ("version,v", "Display version.")
      // clang-format on
      ;

  po::positional_options_description positional_options_description;
  positional_options_description.add("wttrin-options", 1);

  po::variables_map variables_map;
  po::store(po::command_line_parser(argc, argv)
                .options(options_description)
                .positional(positional_options_description)
                .run(),
            variables_map);
  po::notify(variables_map);

  if (variables_map.count("help")) {
    std::cout
        << "Usage: ascii-weather-forecast [wttr.in options|OPTION [ARGUMENT]]"
        << "\n\n"
        << "Visit https://wttr.in/:help for a full list of wttr.in options."
        << "\n\n";
    std::cout << options_description << std::endl;
  } else if (variables_map.count("version")) {
    std::cout << "ascii-weather-forecast version 1.0.0" << std::endl;
  } else {
    wttrin_wrapper::GetWeatherForecast(
        variables_map["wttrin-options"].as<std::string>());
  }

  return 0;
}
