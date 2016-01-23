#include "helpers.hpp"
#include <string>

namespace bmrk {

BookmarkPtr createMockBookmark(
    String url, String title, Tags tags, String notes) {
  if (url.empty()) url = "http://pezzato.net";
  if (title.empty()) title = "Alessandro Pezzato";
  if (tags.empty()) tags = Tags({"foo", "bar", "zee"});
  if (notes.empty()) notes = "That guy who created bmrk";
  return BookmarkPtr(new Bookmark{url, title, tags, notes});
}
} /* bmrk  */
