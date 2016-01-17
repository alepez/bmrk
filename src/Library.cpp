#include "Library.hpp"

void Library::add(BookmarkPtr bookmark) {
	bookmarks_.push_back(bookmark);
}
