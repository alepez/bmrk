#include "Bmrk.hpp"
#include "Bookmark.hpp"
#include "PageDownloader.hpp"
#include "PageParser.hpp"
#include "Library.hpp"

namespace bmrk {

Bmrk::Bmrk(PageDownloaderPtr downloader, DatabasePtr db)
    : downloader_{downloader}, db_{db} {
  library_.reset(new Library);
  library_->connect(db);
}

Future<BookmarkPtr> Bmrk::createBookmarkFromUrl(const String& url) const {
  return std::async([url, this]() {
    BookmarkData data;
    auto page = downloader_->load(url).get();
    auto parser = PageParser(page);
		data.url = url;
		data.title = parser.getTitle();
    return BookmarkPtr(new Bookmark{data});
  });
}

void Bmrk::add(BookmarkPtr bookmark) {
  library_->add(bookmark);
}
} /* bmrk  */
