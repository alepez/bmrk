#include <gtest/gtest.h>
#include <PageDownloader.hpp>
#include <string>

namespace bmrk {

TEST(PageDownloaderTest, DISABLED_CanDownloadPage) {
  String url = "http://pezzato.net";
  PageDownloader downloader;
  String body = downloader.load(url).get();
  ASSERT_GT(body.length(), 0);
}
} /* bmrk  */
