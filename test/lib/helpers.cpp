#include "helpers.hpp"
#include <string>

BookmarkPtr createMockBookmark(
		std::string url, std::string title, std::string notes, Tags tags) {
	if (url.empty()) url = "http://pezzato.net";
	if (title.empty()) title = "Alessandro Pezzato";
	if (notes.empty()) notes = "That guy who created bmrk";
	if (tags.empty()) tags = Tags({"foo", "bar", "zee"});
	return BookmarkPtr(new Bookmark{url, title, notes, tags});
}
