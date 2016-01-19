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
		return std::async(std::launch::async, [url, this]() -> std::string { return html_; });
	}

private:
	std::string html_;
};

PageDownloaderPtr dwl(const std::string& html) {
	return PageDownloaderPtr{new PageDownloaderMock(html)};
}

struct BmrkTest : public testing::Test {
	Bmrk bmrk{dwl("<html><head><title>ciao</title></head><body></body></html>")};
};

TEST_F(BmrkTest, CanGetBookmarkFromUrl) {
	auto bookmark = bmrk.createBookmarkFromUrl("http://pezzato.net").get();
	ASSERT_EQ("ciao", bookmark->title);
}
