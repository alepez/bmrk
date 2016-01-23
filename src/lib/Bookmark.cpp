#include "Bookmark.hpp"
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <openssl/sha.h>

namespace bmrk {

Id Bookmark::getID(const String& url) {
  Id result;
  SHA_CTX ctx;
  SHA1_Init(&ctx);
  SHA1_Update(&ctx, url.c_str(), url.size());
  SHA1_Final(result.data(), &ctx);
  return result;
}

Tags Bookmark::parseTags(const String& str) {
  Tags tags;
  boost::split(tags, str, boost::is_any_of(","));
  return tags;
}

String Bookmark::formatTags(const Tags& tags) {
  std::stringstream stream;
  for (unsigned i = 0; i < tags.size(); ++i) {
    stream << (i ? "," : "") << tags[i];
  }
  return stream.str();
}

BookmarkPtr setUrl(BookmarkPtr bm, String url) {
  auto&& title = bm->title;
  auto&& tags = bm->tags;
  auto&& notes = bm->notes;
  return std::make_shared<Bookmark>(url, title, tags, notes);
}

BookmarkPtr setTitle(BookmarkPtr bm, String title) {
  auto&& url = bm->url;
  auto&& tags = bm->tags;
  auto&& notes = bm->notes;
  return std::make_shared<Bookmark>(url, title, tags, notes);
}

BookmarkPtr setTags(BookmarkPtr bm, Tags tags) {
  auto&& url = bm->url;
  auto&& title = bm->title;
  auto&& notes = bm->notes;
  return std::make_shared<Bookmark>(url, title, tags, notes);
}

BookmarkPtr setNotes(BookmarkPtr bm, String notes) {
  auto&& url = bm->url;
  auto&& title = bm->title;
  auto&& tags = bm->tags;
  return std::make_shared<Bookmark>(url, title, tags, notes);
}
} /* bmrk  */
