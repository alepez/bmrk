#ifndef BOOKMARK_HPP_4NOOTDNA
#define BOOKMARK_HPP_4NOOTDNA

#include "bmrk_fwd.hpp"

class Bookmark {
public:
	static Id getID(const std::string& url);

	static Tags parseTags(const std::string&);

	template <typename U, typename T, typename N, typename S>
	inline Bookmark(U&& aurl, T&& atitle, S&& atags, N&& anotes)
			: url{aurl}
			, title{atitle}
			, tags{atags}
			, notes{anotes}
			, id{Bookmark::getID(url)} {
	}

	const Url url;
	const Title title;
	const Tags tags;
	const Notes notes;

	const Id id;
};

// BookmarkPtr setUrl(BookmarkPtr, std::string);
// BookmarkPtr setTitle(BookmarkPtr, std::string);
// BookmarkPtr setTags(BookmarkPtr, Tags);
// BookmarkPtr setNotes(BookmarkPtr, std::string);

#endif /* end of include guard: BOOKMARK_HPP_4NOOTDNA */
