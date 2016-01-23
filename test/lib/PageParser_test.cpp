#include <gtest/gtest.h>
#include <PageParser.hpp>
#include <string>

namespace bmrk {

TEST(PageParserTest, CanParseTitle) {
  String html =
      "<html><head>"
      "<title>This is a title</title>"
      "</head><body></body></html>";
  PageParser parser{html};
  ASSERT_EQ("This is a title", parser.getTitle());
}

TEST(PageParserTest, ThrowsWithInvalidDocument) {
  PageParser parser{"<html></dasd>"};
  ASSERT_ANY_THROW(parser.getTitle());
}

TEST(PageParserTest, ThrowsWithEmptyDocument) {
  ASSERT_ANY_THROW([]() { PageParser parser{""}; }());
}

// FIXME parse description
TEST(PageParserTest, DISABLED_CanParseDescription) {
  String html =
      "<html><head>"
      "<title>This is a title</title>"
      "<meta name=\"description\">foo bar</meta>"
      "</head><body></body></html>";
  PageParser parser{html};
  ASSERT_EQ("foo bar", parser.getNotes());
}
} /* bmrk  */
