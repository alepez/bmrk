#include <gtest/gtest.h>
#include <Bmrk.hpp>
#include <Bookmark.hpp>
#include <PageDownloader.hpp>
#include <memory>

class PageDownloaderMock : public PageDownloader {
public:
	PageDownloaderMock(const std::string& html)
			: html_{html} {};
	std::future<std::string> load(const std::string& url) const override {
		std::cerr << "PageDownloaderMock\n";
		return std::async(std::launch::async, [url, this]() -> std::string { return html_; });
	}

private:
	std::string html_;
};

struct BmrkTest : public testing::Test {
	PageDownloaderPtr downloader{new PageDownloaderMock("<body><head><title>ciao</title></head></body>")};
	Bmrk bmrk{downloader};
};

TEST_F(BmrkTest, CanGetBookmarkFromUrl) {
	auto bookmark = bmrk.createBookmarkFromUrl("http://pezzato.net").get();
	ASSERT_EQ("ciao", bookmark->title);
}
