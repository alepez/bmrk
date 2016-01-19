#include "Bmrk.hpp"
#include "Bookmark.hpp"
#include "PageDownloader.hpp"
#include "PageParser.hpp"

Bmrk::Bmrk(const PageDownloaderPtr& downloader)
		: downloader_{downloader} {
}

std::future<BookmarkPtr> Bmrk::createBookmarkFromUrl(const std::string& url) {
	return std::async(std::launch::async, [url, this]() {
		auto page = downloader_->load(url).get();
		auto properties = PageParser(page);
		return BookmarkPtr(new Bookmark{url, properties.getTitle(), Tags(), "note"});
	});
}
