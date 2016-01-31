#ifndef BOOKMARKDESERIALIZER_HPP_CXFPWDJF
#define BOOKMARKDESERIALIZER_HPP_CXFPWDJF

#include "Bookmark.hpp"
#include <iostream>

namespace bmrk {

class BookmarkDeserializer {
public:
	BookmarkPtr deserialize(std::istream*);
};

} /* bmrk */

#endif /* end of include guard: BOOKMARKDESERIALIZER_HPP_CXFPWDJF */
