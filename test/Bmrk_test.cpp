#include <gtest/gtest.h>
#include <Bmrk.hpp>
#include <Bookmark.hpp>

struct BmrkTest : public testing::Test {
	Bmrk bmrk;
};

TEST_F(BmrkTest, CanGetBookmarkFromUrl) {
	auto bookmark = bmrk.createBookmarkFromUrl("http://pezzato.net").get();
	ASSERT_EQ("Alessandro Pezzato Blog | Alessandro Pezzato", bookmark->title);
}
