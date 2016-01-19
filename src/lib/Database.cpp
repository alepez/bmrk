#include "Database.hpp"
#include "Bookmark.hpp"

Database::Database(const Config& config)
		: root_{config.at("root")} {
}

void Database::add(const BookmarkPtr& bookmark) {
	auto path = this->getAbsolutePath(this->getPath(*bookmark));
}

std::string Database::getPath(const Bookmark& bookmark) {
	auto&& id = bookmark.id;
	return id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id;
}

std::string Database::getAbsolutePath(const std::string& path) {
	return root_ + "/" + path;
}
