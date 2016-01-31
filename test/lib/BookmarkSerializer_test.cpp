#include <gtest/gtest.h>
#include <BookmarkSerializer.hpp>
#include "helpers.hpp"

namespace bmrk {

struct BookmarkSerializerTest: public testing::Test {
	BookmarkSerializer bs;
};

TEST_F(BookmarkSerializerTest, CanSerialize) {
  auto bookmark = createMockBookmark(
      "http://pezzato.net", "one", Tags({"foo", "bar"}), "two");
  std::stringstream stream;
	bs.serialize(&stream, bookmark);
  ASSERT_EQ("http://pezzato.net\none\nfoo,bar\ntwo\n", stream.str());
}

} /* bmrk  */


