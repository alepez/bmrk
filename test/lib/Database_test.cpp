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
	ASSERT_EQ("bookmarks/65/1d/651db60812a5fff04e5b33ec7384a220da2cee2c", db.getPath(*bookmark));
}

TEST_F(DatabaseTest, CanWriteBookmark) {
	auto bookmark = createMockBookmark("http://pezzato.net", "one", "two", Tags{{"foo","bar"}});
	std::stringstream stream;
	db.write(stream, bookmark);
	ASSERT_EQ("http://pezzato.net\none\ntwo\nfoo,bar,", stream.str());
}

TEST_F(DatabaseTest, CanAddBookmark) {
	auto bookmark = createMockBookmark("http://pezzato.net");
	db.add(bookmark);
	ASSERT_EQ(1u, db.getAllBookmarks().size());
}

TEST_F(DatabaseTest, DISABLED_CanRemoveBookmark) {
	auto bookmark = createMockBookmark("http://pezzato.net");
	db.add(bookmark);
	ASSERT_EQ(1u, db.getAllBookmarks().size());
	db.remove(bookmark);
	ASSERT_EQ(0u, db.getAllBookmarks().size());
}
