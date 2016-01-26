#include "Tag.hpp"
#include <sstream>
#include <boost/algorithm/string.hpp>

namespace bmrk {

Tags parseTags(const String& str) {
  Tags tags;
  boost::split(tags, str, boost::is_any_of(","));
  return tags;
}

String formatTags(const Tags& tags) {
  std::stringstream stream;
  for (unsigned i = 0; i < tags.size(); ++i) {
    stream << (i ? "," : "") << tags[i];
  }
  return stream.str();
}

} /* bmrk  */
