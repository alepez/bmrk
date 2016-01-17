#ifndef BMRK_HPP_0Q6IB5LJ
#define BMRK_HPP_0Q6IB5LJ

#include <string>
#include "bmrk_fwd.h"
#include <future>

class Bmrk {
public:
	Bmrk(const PageDownloaderPtr& downloader);
	std::future<BookmarkPtr> createBookmarkFromUrl(const std::string& url);
private:
	PageDownloaderPtr downloader_;
};

#endif /* end of include guard: BMRK_HPP_0Q6IB5LJ */
