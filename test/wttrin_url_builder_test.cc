#include "wttrin_url_builder.h"

#include <gtest/gtest.h>

TEST(WttrinUrlBuilderTest, GetUrl) {
  const auto wttrin_options("Madrid?1FnQ");
  WttrinUrlBuilder url_builder{wttrin_options};

  const auto url{"https://wttr.in/Madrid?1FnQ"};
  ASSERT_STREQ(url, url_builder.GetUrl().c_str());
}
