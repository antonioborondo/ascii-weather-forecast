# ascii-weather-forecast

[![CI](https://github.com/antonioborondo/ascii-weather-forecast/actions/workflows/ci.yml/badge.svg)](https://github.com/antonioborondo/ascii-weather-forecast/actions/workflows/ci.yml)

## Description

C++ wrapper for [wttr.in](https://wttr.in), the console-oriented weather forecast service.

## Usage

Pass the wttr.in options as argument:

```shell
$ ascii-weather-forecast Madrid?1FnQ

      \   /     Sunny
       .-.      16 °C
    ― (   ) ―   ↗ 12 km/h
       `-’      10 km
      /   \     0.0 mm
                        ┌─────────────┐
┌───────────────────────┤  Thu 20 Feb ├───────────────────────┐
│             Noon      └──────┬──────┘      Night            │
├──────────────────────────────┼──────────────────────────────┤
│     \   /     Sunny          │     \   /     Clear          │
│      .-.      +14(13) °C     │      .-.      12 °C          │
│   ― (   ) ―   ↗ 9-10 km/h    │   ― (   ) ―   ↗ 5-10 km/h    │
│      `-’      10 km          │      `-’      10 km          │
│     /   \     0.0 mm | 0%    │     /   \     0.0 mm | 0%    │
└──────────────────────────────┴──────────────────────────────┘
```

Store the wttr.in options so you don't have to pass them every time:

```shell
$ ascii-weather-forecast -s Madrid?1FnQ

$ ascii-weather-forecast

      \   /     Sunny
       .-.      16 °C
    ― (   ) ―   ↗ 12 km/h
       `-’      10 km
      /   \     0.0 mm
                        ┌─────────────┐
┌───────────────────────┤  Thu 20 Feb ├───────────────────────┐
│             Noon      └──────┬──────┘      Night            │
├──────────────────────────────┼──────────────────────────────┤
│     \   /     Sunny          │     \   /     Clear          │
│      .-.      +14(13) °C     │      .-.      12 °C          │
│   ― (   ) ―   ↗ 9-10 km/h    │   ― (   ) ―   ↗ 5-10 km/h    │
│      `-’      10 km          │      `-’      10 km          │
│     /   \     0.0 mm | 0%    │     /   \     0.0 mm | 0%    │
└──────────────────────────────┴──────────────────────────────┘
```

Get all the options available with `-h`:

```shell
$ ascii-weather-forecast -h

Usage: ascii-weather-forecast [wttr.in options|OPTION [ARGUMENT]]

Visit https://wttr.in/:help for a full list of wttr.in options.

Options:
  -w [ --wttrin-options ] arg     wttr.in options.
  -s [ --set-wttrin-options ] arg Set wttr.in options.
  -u [ --unset-wttrin-options ]   Unset wttr.in options.
  -g [ --get-wttrin-options ]     Get wttr.in options.
  -h [ --help ]                   Display help.
  -v [ --version ]                Display version.
```

## Libraries

- Boost: <https://boost.org>
- curl: <https://curl.se>
- GoogleTest: <https://github.com/google/googletest>
- inifile-cpp: <https://github.com/Rookfighter/inifile-cpp>

## Tools

- wttr.in: <https://github.com/chubin/wttr.in>
- CMake: <https://cmake.org>
- vcpkg: <https://vcpkg.io>
- GitHub Actions: <https://github.com/features/actions>
