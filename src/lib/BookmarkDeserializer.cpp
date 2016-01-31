#include "BookmarkDeserializer.hpp"

namespace bmrk {

BookmarkPtr BookmarkDeserializer::deserialize(std::istream* stream) {
  BookmarkData data;
  String url, title, notes, buf;
  Tags tags;
  std::getline(*stream, data.url);
  std::getline(*stream, data.title);

  /* tags */
  std::getline(*stream, buf);

  /* notes */
  while (std::getline(*stream, buf)) {
    data.notes += buf;
  }

  return std::make_shared<Bookmark>(data);
}

} /* bmrk */
