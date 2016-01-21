#include <map>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <array>

class Bookmark;
class Database;
class PageDownloader;
class PageParser;
class Library;

using Url = std::string;
using Title = std::string;
using Notes = std::string;
using Id = std::array<uint8_t, 20>;
using LibraryPtr = std::shared_ptr<Library>;
using DatabasePtr = std::shared_ptr<Database>;
using BookmarkPtr = std::shared_ptr<const Bookmark>;
using PageDownloaderPtr = std::shared_ptr<const PageDownloader>;
using Bookmarks = std::vector<BookmarkPtr>;

using Tag = std::string;
using Tags = std::vector<Tag>;

using ExplicitFilter = std::function<Bookmarks(Bookmarks)>;
using Filter = std::function<bool(BookmarkPtr)>;

using Config = std::map<std::string, std::string>;
