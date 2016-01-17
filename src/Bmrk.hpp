#ifndef BMRK_HPP_0Q6IB5LJ
#define BMRK_HPP_0Q6IB5LJ

#include <string>
#include "bmrk_fwd.h"
#include <future>

class Bmrk {
public:
	std::future<BookmarkPtr> createBookmarkFromUrl(const std::string& url);
};

#endif /* end of include guard: BMRK_HPP_0Q6IB5LJ */
