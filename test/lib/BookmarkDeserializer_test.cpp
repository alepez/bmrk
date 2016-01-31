#include <gtest/gtest.h>
#include <BookmarkDeserializer.hpp>
#include "helpers.hpp"

namespace bmrk {

struct BookmarkDeserializerTest: public testing::Test {
	BookmarkDeserializer bd;
};

TEST_F(BookmarkDeserializerTest, CanDeserialize) {
  std::stringstream stream;
	stream << "http://pezzato.net\none\nfoo,bar\ntwo\n";
	auto bookmark = bd.deserialize(&stream);
	ASSERT_EQ("http://pezzato.net", bookmark->url);
}

} /* bmrk  */



