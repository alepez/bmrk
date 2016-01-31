#include "BookmarkSerializer.hpp"
#include "Tag.hpp"

namespace bmrk {

void BookmarkSerializer::serialize(std::ostream* stream, BookmarkPtr bookmark) {
  *stream << bookmark->url << '\n';
  *stream << bookmark->title << '\n';
  *stream << formatTags(bookmark->tags) << '\n';
  *stream << bookmark->notes << '\n';
}

} /* bmrk */
