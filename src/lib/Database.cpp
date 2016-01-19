#include "Database.hpp"
#include "Bookmark.hpp"
#include <fstream>

Database::Database(const Config& config)
		: root_{config.at("root")} {
}

void Database::add(const BookmarkPtr& bookmark) {
	auto path = this->getAbsolutePath(this->getPath(*bookmark));
	std::ofstream file{path};
	this->write(file, bookmark);
}

void Database::write(std::ostream& stream, const BookmarkPtr& bookmark) {
	stream << bookmark->url << '\n';
	stream << bookmark->title << '\n';
	stream << bookmark->notes << '\n';
	for (auto&& tag : bookmark->tags) {
		stream << tag << ',';
	}
	stream << '\n';
}

void Database::remove(const BookmarkPtr& bookmark) {
	auto path = this->getAbsolutePath(this->getPath(*bookmark));
}

Bookmarks Database::getAllBookmarks() const {
	Bookmarks bookmarks;

	return bookmarks;
}

std::string Database::getPath(const Bookmark& bookmark) {
	auto&& id = bookmark.id;
	return "bookmarks/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id;
}

std::string Database::getAbsolutePath(const std::string& path) {
	return root_ + "/" + path;
}
