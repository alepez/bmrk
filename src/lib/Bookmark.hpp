#ifndef BOOKMARK_HPP_4NOOTDNA
#define BOOKMARK_HPP_4NOOTDNA

#include "bmrk_fwd.hpp"

class Bookmark {
public:
	static std::string getID(const std::string& url);

	template <typename U, typename T, typename N, typename S>
	Bookmark(U&& aurl, T&& atitle, N&& anotes, S&& atags)
			: url{aurl}
			, title{atitle}
			, notes{anotes}
			, tags{atags}
			, id{getID(url)} {
	}

	const std::string url;
	const std::string title;
	const std::string notes;
	const Tags tags;

	const std::string id;
};

#endif /* end of include guard: BOOKMARK_HPP_4NOOTDNA */
