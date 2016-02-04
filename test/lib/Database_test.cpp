#include <gtest/gtest.h>
#include <bmrk_fwd.hpp>
#include <Database.hpp>
#include <Bookmark.hpp>
#include "helpers.hpp"

namespace bmrk {

struct DatabaseTest : public testing::Test {
  Config config{{"root", "tmp/db"}};
  Database db{config};
  void SetUp() {
  }
  void TearDown() {
    db.clear();
  }
};

TEST_F(DatabaseTest, DISABLED_GetAbsPath) {
  // Disabled because the absolute path depends on system
  ASSERT_EQ("tmp/db/foo", db.getAbsolutePath("foo"));
}

TEST_F(DatabaseTest, GetPath) {
  auto bookmark = createMockBookmark("http://pezzato.net");
  ASSERT_EQ("bookmarks/65/1d/651db60812a5fff04e5b33ec7384a220da2cee2c",
      db.getPath(*bookmark));
}

TEST_F(DatabaseTest, CanAddBookmark) {
  auto bookmark = createMockBookmark("http://pezzato.net");
  db.add(bookmark);
  ASSERT_EQ(1u, db.getAllBookmarks().size());
}

TEST_F(DatabaseTest, CanRemoveBookmark) {
  auto bookmark = createMockBookmark("http://pezzato.net");
  db.add(bookmark);
  ASSERT_EQ(1u, db.getAllBookmarks().size());
  db.remove(bookmark);
  ASSERT_EQ(0u, db.getAllBookmarks().size());
}

TEST_F(DatabaseTest, CanClear) {
  auto bookmark = createMockBookmark("http://pezzato.net");
  db.clear();
  ASSERT_EQ(0u, db.getAllBookmarks().size());
}

TEST(DatabaseWithWrongDirectoryTest, ThrowsIfCannotCreateDirectory) {
  Config config{{"root", "/this_directory_does_not_exist/db"}};
  ASSERT_ANY_THROW(Database db{config};);
}

} /* bmrk  */
