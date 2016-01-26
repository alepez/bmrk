#include "helpers.hpp"
#include <string>

namespace bmrk {

BookmarkPtr createMockBookmark(
    String url, String title, Tags tags, String notes) {
	BookmarkData data;
  if (url.empty()) data.url = "http://pezzato.net";
  if (title.empty()) data.title = "Alessandro Pezzato";
  if (tags.empty()) data.tags = Tags({"foo", "bar", "zee"});
  if (notes.empty()) data.notes = "That guy who created bmrk";
  return BookmarkPtr(new Bookmark{data});
}
} /* bmrk  */
