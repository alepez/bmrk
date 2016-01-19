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

BookmarkPtr Database::read(std::istream& stream) const {
	std::string url, title, notes, buf;
	Tags tags;
	std::getline(stream, url);
	std::getline(stream, title);

	/* tags */
	std::getline(stream, buf);

	/* notes */
	while (std::getline(stream, buf)) {
		notes += buf;
	}

	return std::make_shared<Bookmark>(url, title, tags, notes);
}

void Database::remove(const BookmarkPtr& bookmark) {
	auto path = this->getAbsolutePath(this->getPath(*bookmark));
	fs::remove(fs::path(path));
}

template <typename B, typename T>
void recursiveFindBookmarkFiles(B& bookmarks, T dir) {
	for (auto&& l : fs::directory_iterator(dir)) {
		if (fs::is_directory(l)) {
			recursiveFindBookmarkFiles(bookmarks, l);
		} else {
			bookmarks.push_back(l.path().c_str());
		}
	}
}

Bookmarks Database::getAllBookmarks() const {
	Bookmarks bookmarks;
	std::vector<std::string> bookmarkFiles;
	recursiveFindBookmarkFiles(bookmarkFiles, fs::path(root_));
	for (auto&& f : bookmarkFiles) {
		std::ifstream file{f};
		bookmarks.push_back(this->read(file));
	}
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

void Database::clear() {
	fs::path root{root_};
	for (auto&& l : fs::directory_iterator(root)) {
		fs::remove_all(l);
	}
}
