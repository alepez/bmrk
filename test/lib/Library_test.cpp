#include <gtest/gtest.h>
#include <Library.hpp>
#include <Database.hpp>
#include <Bookmark.hpp>
#include <memory>
#include "helpers.hpp"

struct LibraryTest : public testing::Test {
  Library library;
  void SetUp() {
    library.add(createMockBookmark());
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

TEST_F(LibraryTest, CanConnectToDatabase) {
  auto db = std::make_shared<Database>(Config({{"root", "tmp/db"}}));
  library.connect(db);
}
