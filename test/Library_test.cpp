#include <gtest/gtest.h>
#include <Library.hpp>
#include <Bookmark.hpp>
#include <memory>

BookmarkPtr bm(std::string url, std::string title, std::string notes, Tags tags) {
	return BookmarkPtr{new Bookmark{url, title, notes, tags}};
}

struct LibraryTest : public testing::Test {
	Library library;
	void SetUp() {
		library.add(bm("http://pezzato.net",
									 "Alessandro Pezzato",
									 "That guy who created bmrk",
									 Tags{}));
	}
};

TEST_F(LibraryTest, CanListBookmarks) {
	auto bookmarks = library.getAllBookmarks();
	ASSERT_EQ(1u, bookmarks.size());
}
