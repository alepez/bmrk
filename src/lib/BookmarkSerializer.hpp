#ifndef BOOKMARKSERIALIZER_HPP_WZ0OUAEF
#define BOOKMARKSERIALIZER_HPP_WZ0OUAEF

#include "Bookmark.hpp"
#include <iostream>

namespace bmrk {

class BookmarkSerializer {
public:
  void serialize(std::ostream*, BookmarkPtr);
};

} /* bmrk */

#endif /* end of include guard: BOOKMARKSERIALIZER_HPP_WZ0OUAEF */
