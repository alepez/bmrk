#include "helpers.hpp"
#include <string>

BookmarkPtr createMockBookmark(
    std::string url, std::string title, Tags tags, std::string notes) {
  if (url.empty()) url = "http://pezzato.net";
  if (title.empty()) title = "Alessandro Pezzato";
  if (tags.empty()) tags = Tags({"foo", "bar", "zee"});
  if (notes.empty()) notes = "That guy who created bmrk";
  return BookmarkPtr(new Bookmark{url, title, tags, notes});
}
