# ascii-weather-forecast

[![CI](https://github.com/antonioborondo/ascii-weather-forecast/actions/workflows/ci.yml/badge.svg)](https://github.com/antonioborondo/ascii-weather-forecast/actions/workflows/ci.yml)

## Description

C++ wrapper for [wttr.in](https://wttr.in), the console-oriented weather forecast service.

### Example

```bash
$ ascii-weather-forecast Madrid?2FnQ

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
                        ┌─────────────┐
┌───────────────────────┤  Fri 21 Feb ├───────────────────────┐
│             Noon      └──────┬──────┘      Night            │
├──────────────────────────────┼──────────────────────────────┤
│    \  /       Partly Cloudy  │  _`/"".-.     Light rain sho…│
│  _ /"".-.     +14(13) °C     │   ,\_(   ).   +12(9) °C      │
│    \_(   ).   ↑ 12-14 km/h   │    /(___(__)  ↑ 21-36 km/h   │
│    /(___(__)  10 km          │      ‘ ‘ ‘ ‘  10 km          │
│               0.0 mm | 0%    │     ‘ ‘ ‘ ‘   0.3 mm | 100%  │
└──────────────────────────────┴──────────────────────────────┘
```

## Libraries

- cURL: <https://curl.se>

## Tools

- wttr.in: <https://github.com/chubin/wttr.in>
- CMake: <https://cmake.org>
- vcpkg: <https://vcpkg.io>
- GitHub Actions: <https://github.com/features/actions>
