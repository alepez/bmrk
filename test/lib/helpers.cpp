#include "helpers.hpp"
#include <string>

namespace bmrk {

BookmarkPtr createMockBookmark(
    String url, String title, Tags tags, String notes) {
  BookmarkData data;
  data.url = url.empty() ? "http://pezzato.net" : url;
  data.title = title.empty() ? "Alessandro Pezzato" : title;
  data.tags = tags.empty() ? Tags({"foo", "bar", "zee"}) : tags;
  data.notes = notes.empty() ? "That guy who created bmrk" : notes;
  return BookmarkPtr(new Bookmark{data});
}

} /* bmrk  */
