#include "Database.hpp"
#include "Bookmark.hpp"
#include <fstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

Database::Database(const Config& config)
		: root_{config.at("root")} {
	this->setupDirectory();
}

void Database::add(const BookmarkPtr& bookmark) {
	auto path = this->getAbsolutePath(this->getPath(*bookmark));
	fs::create_directories(fs::path(path).parent_path());
	std::ofstream file{path};
	this->write(file, bookmark);
}

void Database::write(std::ostream& stream, const BookmarkPtr& bookmark) {
	stream << bookmark->url << '\n';
	stream << bookmark->title << '\n';
	auto&& tags = bookmark->tags;
	for (unsigned i = 0; i < tags.size(); ++i) {
		stream << (i ? "," : "") << tags[i];
	}
	stream << '\n';
	stream << bookmark->notes << '\n';
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

void Database::setupDirectory() {
	fs::path root{root_};
	if (!fs::exists(root)) {
		fs::create_directories(root);
	}
}
