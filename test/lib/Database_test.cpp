#include <gtest/gtest.h>
#include <bmrk_fwd.hpp>
#include <Database.hpp>
#include <Bookmark.hpp>
#include "helpers.hpp"

struct DatabaseTest : public testing::Test {
	Config config{{"root", "tmp/db"}};
	Database db{config};
	void SetUp() {
	}
	void TearDown() {
	}
};

TEST_F(DatabaseTest, GetAbsPath) {
	ASSERT_EQ("tmp/db/foo", db.getAbsolutePath("foo"));
}

TEST_F(DatabaseTest, GetPath) {
	auto bookmark = createMockBookmark("http://pezzato.net");
	ASSERT_EQ("65/1d/651db60812a5fff04e5b33ec7384a220da2cee2c", db.getPath(*bookmark));
}
