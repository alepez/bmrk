#ifndef LIBRARY_HPP_AZX093RT
#define LIBRARY_HPP_AZX093RT

#include "bmrk_fwd.h"

class Library {
public:
	void add(BookmarkPtr);

private:
	std::vector<BookmarkPtr> bookmarks_;
};

#endif /* end of include guard: LIBRARY_HPP_AZX093RT */
