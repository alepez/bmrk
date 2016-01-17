#ifndef LIBRARY_HPP_AZX093RT
#define LIBRARY_HPP_AZX093RT

#include "bmrk_fwd.h"

class Library {
public:
	void add(BookmarkPtr);
	const Bookmarks& getAllBookmarks() const;

private:
	Bookmarks bookmarks_;
};

#endif /* end of include guard: LIBRARY_HPP_AZX093RT */
