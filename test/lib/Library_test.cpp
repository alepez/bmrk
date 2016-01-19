#include <gtest/gtest.h>
#include <Library.hpp>
#include <Bookmark.hpp>
#include <memory>

BookmarkPtr bm(
		std::string url, std::string title, std::string notes, Tags tags) {
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
	auto bookmarks = library.getAll();
	ASSERT_EQ(1u, bookmarks.size());
}

TEST_F(LibraryTest, CanFilterExplicit) {
	auto bookmarks = library.filter([](Bookmarks) {
		Bookmarks filtered;
		return filtered;
	});
	ASSERT_EQ(0u, bookmarks.size());
}

TEST_F(LibraryTest, CanFilterImplicit) {
	auto bookmarks = library.filter([](BookmarkPtr) { return true; });
	ASSERT_EQ(library.getAll().size(), bookmarks.size());
}

TEST_F(LibraryTest, CanFilterImplicit2) {
	auto bookmarks = library.filter([](BookmarkPtr) { return false; });
	ASSERT_EQ(0u, bookmarks.size());
}
