#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "options.h"
#include "version.h"
#include "wttrin_wrapper.h"
#include "wttrin_wrapper_exception.h"

namespace po = boost::program_options;

int main(int argc, char** argv) {
  try {
    po::options_description options_description("Options");
    options_description.add_options()
        // clang-format off
        ("wttrin-options,w", po::value<std::string>()->default_value(""), "wttr.in options.")
        ("set-wttrin-options,s", po::value<std::string>(), "Set wttr.in options.")
        ("unset-wttrin-options,u", "Unset wttr.in options.")
        ("get-wttrin-options,g", "Get wttr.in options.")
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

    if (variables_map.count("set-wttrin-options")) {
      const auto value{variables_map["set-wttrin-options"].as<std::string>()};
      options::Set("wttrin", "options", value);
    } else if (variables_map.count("unset-wttrin-options")) {
      options::Set("wttrin", "options", "");
    } else if (variables_map.count("get-wttrin-options")) {
      std::cout << options::Get("wttrin", "options") << std::endl;
    } else if (variables_map.count("help")) {
      std::cout
          << "Usage: ascii-weather-forecast [wttr.in options|OPTION [ARGUMENT]]"
          << "\n\n"
          << "Visit https://wttr.in/:help for a full list of wttr.in options."
          << "\n\n";
      std::cout << options_description << std::endl;
    } else if (variables_map.count("version")) {
      std::cout << "ascii-weather-forecast version " << kVersion << std::endl;
    } else {
      auto options{variables_map["wttrin-options"].as<std::string>()};
      if (options.empty()) {
        options = options::Get("wttrin", "options");
      }
      try {
        wttrin_wrapper::GetWeatherForecast(options);
      } catch (const WttrinWrapperException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
      }
    }
  } catch (const boost::program_options::unknown_option& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  } catch (const boost::program_options::invalid_command_line_syntax& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
