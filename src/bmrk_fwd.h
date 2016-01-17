#include <memory>
#include <string>
#include <vector>
#include <functional>

class Bookmark;
class PageDownloader;
class PageParser;

using BookmarkPtr = std::shared_ptr<const Bookmark>;
using PageDownloaderPtr = std::shared_ptr<const PageDownloader>;
using Bookmarks = std::vector<BookmarkPtr>;

using Tag = std::string;
using Tags = std::vector<Tag>;

using ExplicitFilter = std::function<Bookmarks(Bookmarks)>;
using Filter = std::function<bool(BookmarkPtr)>;
