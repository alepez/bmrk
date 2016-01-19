#include "Library.hpp"
#include "Database.hpp"
#include <algorithm>
#include "Bookmark.hpp"

void Library::add(BookmarkPtr bookmark) {
	bookmarks_.push_back(bookmark);
	if (db_) {
		db_->add(bookmark);
	}
}

void Library::remove(BookmarkPtr bookmark) {
	// TODO find a more efficient algorithm
	bookmarks_.erase(
			std::remove_if(bookmarks_.begin(),
					bookmarks_.end(),
					[bookmark](const BookmarkPtr& b) { return b->id == bookmark->id; }),
			bookmarks_.end());
	bookmarks_.push_back(bookmark);
	if (db_) {
		db_->remove(bookmark);
	}
}

Bookmarks Library::getAll() const {
	return bookmarks_;
}

Bookmarks Library::filter(ExplicitFilter filter) const {
	return filter(bookmarks_);
}

Bookmarks Library::filter(Filter filter) const {
	Bookmarks filtered;

	for (auto&& bookmark : bookmarks_) {
		if (filter(bookmark)) {
			filtered.push_back(bookmark);
		}
	}

	return filtered;
}

void Library::connect(const DatabasePtr& db) {
	db_ = db;
}
