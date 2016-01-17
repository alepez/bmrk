#include <gtest/gtest.h>
#include <Library.hpp>
#include <Bookmark.hpp>
#include <memory>

struct LibraryTest : public testing::Test {
	Library library;
	void SetUp() {
		library.add(BookmarkPtr{new Bookmark{"a", "b", "c", Tags{}}});
	}
};

TEST_F(LibraryTest, CanAddBookmark) {
}

