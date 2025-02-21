#include "options.h"

#include <inicpp.h>
#include <string.h>

#include <filesystem>

namespace {

std::filesystem::path GetDataDirectory() {
  std::filesystem::path data_directory;

  const auto xdg_data_home_directory{std::getenv("XDG_DATA_HOME")};
  if (xdg_data_home_directory && strlen(xdg_data_home_directory) != 0) {
    data_directory = xdg_data_home_directory;
  } else {
    data_directory = std::getenv("HOME");
    data_directory /= ".local/share";
  }

  data_directory /= "ascii-weather-forecast";

  return data_directory;
}

void CreateDataDirectory(const std::filesystem::path& data_directory) {
  std::filesystem::create_directories(data_directory);
}

std::filesystem::path GetIniFilePath() {
  std::filesystem::path data_directory{GetDataDirectory()};
  CreateDataDirectory(data_directory);

  return data_directory /= "options.ini";
}

}  // namespace

void options::Set(const std::string& section, const std::string& key,
                  const std::string& value) {
  ini::IniFile ini_file;
  ini_file[section][key] = value;
  const auto ini_file_path{GetIniFilePath()};
  ini_file.save(GetIniFilePath());
}

std::string options::Get(const std::string& section, const std::string& key) {
  ini::IniFile ini_file;
  const auto ini_file_path{GetIniFilePath()};
  ini_file.load(ini_file_path);
  return ini_file[section][key].as<const char*>();
}
