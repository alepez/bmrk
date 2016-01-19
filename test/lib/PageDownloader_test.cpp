#include <gtest/gtest.h>
#include <PageDownloader.hpp>
#include <string>

TEST(PageDownloaderTest, DISABLED_CanDownloadPage) {
	std::string url = "http://pezzato.net";
	PageDownloader downloader;
	std::string body = downloader.load(url).get();
	ASSERT_GT(body.length(), 0);
}
