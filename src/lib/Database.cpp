#include "Database.hpp"
#include "Bookmark.hpp"
#include "Utils.hpp"
#include "Tag.hpp"

#include <fstream>
#include <boost/filesystem.hpp>

namespace bmrk {

namespace fs = boost::filesystem;

static String setupDirectory(const String&);

Database::Database(const Config& config)
    : root_{setupDirectory(config.at("root"))}
    , serializer_(new BookmarkSerializer)
    , deserializer_(new BookmarkDeserializer) {
}

void Database::add(const BookmarkPtr& bookmark) {
  auto path = this->getAbsolutePath(this->getPath(bookmark->id));
  fs::create_directories(fs::path(path).parent_path());
  std::ofstream file{path};
  serializer_->serialize(&file, bookmark);
}

void Database::remove(const BookmarkPtr& bookmark) {
  auto path = this->getAbsolutePath(this->getPath(bookmark->id));
  fs::remove(fs::path(path));
}

void recursiveFindBookmarkFiles(
    std::vector<String>& bookmarks, const fs::path& dir) {
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
  std::vector<String> bookmarkFiles;
  recursiveFindBookmarkFiles(bookmarkFiles, fs::path(root_));
  for (auto&& f : bookmarkFiles) {
    std::ifstream file{f};
    bookmarks.push_back(deserializer_->deserialize(&file));
  }
  return bookmarks;
}

String Database::getPath(const UUID& uuid) {
  auto&& idStr = formatUUID(uuid);
  return "bookmarks/" + idStr.substr(0, 2) + "/" + idStr.substr(2, 2) + "/" + idStr;
}

String Database::getAbsolutePath(const String& path) {
  return root_ + "/" + path;
}

String setupDirectory(const String& rootPath) {
  fs::path root{rootPath};
  if (!fs::exists(root)) {
    fs::create_directories(root);
  }
  return fs::canonical(root).string<String>();
}

void Database::clear() {
  fs::path root{root_};
  fs::directory_iterator end;
  for (fs::directory_iterator it(root); it != end; ++it) {
    fs::remove_all(*it);
  }
}

} /* bmrk  */
