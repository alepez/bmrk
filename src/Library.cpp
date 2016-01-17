#include "Library.hpp"

void Library::add(BookmarkPtr bookmark) {
	bookmarks_.push_back(bookmark);
}

const Bookmarks& Library::getAllBookmarks() const {
	return bookmarks_;
}
