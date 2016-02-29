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
    db.clear();
  }
  void TearDown() {
  }
};

TEST_F(DatabaseTest, DISABLED_GetAbsPath) {
  // Disabled because the absolute path depends on system
  ASSERT_EQ("tmp/db/foo", db.getAbsolutePath("foo"));
}

TEST_F(DatabaseTest, GetPath) {
  UUID uuid{{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b,
      0x0c, 0x0d, 0x0e, 0x0f, 0x10}};
  ASSERT_EQ(
      "bookmarks/01/02/0102030405060708090a0b0c0d0e0f10", db.getPath(uuid));
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
