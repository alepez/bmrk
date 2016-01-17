#include "Bmrk.hpp"
#include "Bookmark.hpp"
#include "PageDownloader.hpp"
#include "PageParser.hpp"

std::future<BookmarkPtr> Bmrk::createBookmarkFromUrl(const std::string& url) {
	return std::async(std::launch::async, [url]() {
		PageDownloader downloader;
		auto page = downloader.load(url).get();
		auto properties = PageParser(page);
		return BookmarkPtr(new Bookmark{url, properties.getTitle(), "note", Tags()});
	});
}
