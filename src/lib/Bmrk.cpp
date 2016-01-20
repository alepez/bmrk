#include "Bmrk.hpp"
#include "Bookmark.hpp"
#include "PageDownloader.hpp"
#include "PageParser.hpp"
#include "Library.hpp"

Bmrk::Bmrk(PageDownloaderPtr downloader, DatabasePtr db)
		: downloader_{downloader}
		, db_{db} {
			library_.reset(new Library);
			library_->connect(db);
}

std::future<BookmarkPtr> Bmrk::createBookmarkFromUrl(const std::string& url) const {
	return std::async(std::launch::async,
			[url, this]() {
				auto page = downloader_->load(url).get();
				auto properties = PageParser(page);
				return BookmarkPtr(
						new Bookmark{url, properties.getTitle(), Tags(), "note"});
			});
}

void Bmrk::add(BookmarkPtr bookmark) {
	library_->add(bookmark);
}
