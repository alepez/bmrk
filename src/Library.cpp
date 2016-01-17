#include "Library.hpp"

void Library::add(BookmarkPtr bookmark) {
	bookmarks_.push_back(bookmark);
}

Bookmarks Library::getAll() const {
	return bookmarks_;
}

Bookmarks Library::filter(ExplicitFilter filter) const {
	return filter(bookmarks_);
}

Bookmarks Library::filter(Filter filter) const {
	Bookmarks filtered;

	for (auto&& bookmark: bookmarks_) {
		if (filter(bookmark)) {
			filtered.push_back(bookmark);
		}
	}

	return filtered;
}
