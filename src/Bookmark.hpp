#ifndef BOOKMARK_HPP_4NOOTDNA
#define BOOKMARK_HPP_4NOOTDNA

#include "bmrk_fwd.h"

struct Bookmark {
	const std::string url;
	const std::string title;
	const std::string notes;
	const std::vector<std::string> tags;
};

#endif /* end of include guard: BOOKMARK_HPP_4NOOTDNA */
