#ifndef BOOKMARK_HPP_4NOOTDNA
#define BOOKMARK_HPP_4NOOTDNA

#include "bmrk_fwd.hpp"

class Bookmark {
public:
	static std::string getID(const std::string& url);

	template <typename U, typename T, typename N, typename S>
	inline Bookmark(U&& aurl, T&& atitle, S&& atags, N&& anotes)
			: url{aurl}
			, title{atitle}
			, tags{atags}
			, notes{anotes}
			, id{getID(url)} {
	}

	const std::string url;
	const std::string title;
	const Tags tags;
	const std::string notes;

	const std::string id;
};

#endif /* end of include guard: BOOKMARK_HPP_4NOOTDNA */
