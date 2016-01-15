#include <gtest/gtest.h>
#include <PageDownloader.hpp>
#include <string>

TEST(PageDownloaderTest, CanDownloadPage) {
	std::string url = "http://pezzato.net";
	PageDownloader downloader;
	downloader.load(url, [](std::string body) {

	});
}
