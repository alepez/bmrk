#include <gtest/gtest.h>
#include <Tag.hpp>
#include "helpers.hpp"

namespace bmrk {

struct TagTest : public testing::Test {
};

TEST_F(TagTest, CanParseTagsFromCommaSeparatedString) {
	std::string tagsStr = "one,two,tree";
	auto tags = parseTags(tagsStr);
  ASSERT_EQ(3u, tags.size());
}

TEST_F(TagTest, CanFormatTagsToCommaSeparatedString) {
	Tags tags = {"one", "two", "tree"};
	auto tagsStr = formatTags(tags);
	ASSERT_EQ("one,two,tree", tagsStr);
}

} /* bmrk  */

