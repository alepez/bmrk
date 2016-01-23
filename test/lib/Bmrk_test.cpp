#include <gtest/gtest.h>
#include <Database.hpp>
#include <Bmrk.hpp>
#include <Bookmark.hpp>
#include <PageDownloader.hpp>
#include <memory>

namespace bmrk {

class PageDownloaderMock : public PageDownloader {
public:
  PageDownloaderMock(const String& html) : html_{html} {};
  Future<String> load(const String& url) const override {
    return async([url, this]() -> String { return html_; });
  }

private:
  String html_;
};

PageDownloaderPtr dwl(const String& html) {
  return PageDownloaderPtr{new PageDownloaderMock(html)};
}

struct BmrkTest : public testing::Test {
  // FIXME use a mock database
  Config config{{{"root", "tmp/db"}}};
  DatabasePtr db = std::make_shared<Database>(config);
  Bmrk bmrk{dwl("<html><head>"
                "<title>ciao</title>"
                "</head><body>"
                "</body></html>"),
      db};
};

TEST_F(BmrkTest, CanGetBookmarkFromUrl) {
  auto bookmark = bmrk.createBookmarkFromUrl("http://pezzato.net").get();
  ASSERT_EQ("ciao", bookmark->title);
}
} /* bmrk  */
