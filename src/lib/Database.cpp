#include "Database.hpp"
#include "Bookmark.hpp"
#include "Utils.hpp"

#include <fstream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

static std::string setupDirectory(const std::string&);

Database::Database(const Config& config)
    : root_{setupDirectory(config.at("root"))} {
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
  stream << Bookmark::formatTags(bookmark->tags) << '\n';
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
  fs::directory_iterator end;
  for (fs::directory_iterator it(dir); it != end; ++it) {
    if (fs::is_directory(*it)) {
      recursiveFindBookmarkFiles(bookmarks, *it);
    } else {
      bookmarks.push_back(it->path().c_str());
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
  auto&& id = utils::formatId(bookmark.id);
  return "bookmarks/" + id.substr(0, 2) + "/" + id.substr(2, 2) + "/" + id;
}

std::string Database::getAbsolutePath(const std::string& path) {
  return root_ + "/" + path;
}

std::string setupDirectory(const std::string& rootPath) {
  fs::path root{rootPath};
  if (!fs::exists(root)) {
    if (!fs::create_directories(root)) {
      throw std::runtime_error{"Cannot create database directory!"};
    }
  }
  return fs::canonical(root).string<std::string>();
}

void Database::clear() {
  fs::path root{root_};
  fs::directory_iterator end;
  for (fs::directory_iterator it(root); it != end; ++it) {
    fs::remove_all(*it);
  }
}
