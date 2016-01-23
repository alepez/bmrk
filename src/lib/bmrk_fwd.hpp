#ifndef BMRK_FWD_HPP_C9NIKUEG
#define BMRK_FWD_HPP_C9NIKUEG

#include <array>
#include <functional>
#include <future>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace bmrk {

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

template <typename T>
using Future = std::future<T>;

using String = std::string;

template <typename T, typename U>
using Map = std::map<T, U>;

template <typename T>
using Vector = std::vector<T>;

// template <typename T>
// inline auto async(T fun) {
//   return std::async(std::launch::async, fun);
// }

using Error = std::runtime_error;

} /* bmrk  */
#endif /* end of include guard: BMRK_FWD_HPP_C9NIKUEG */
