#include <gtest/gtest.h>
#include <PageParser.hpp>
#include <string>

TEST(PageParserTest, CanParseTitle) {
  std::string html = "<html><head><title>This is a title</title></head><body></body></html>";
  PageParser parser{html};
  ASSERT_EQ("This is a title", parser.getTitle());
}

