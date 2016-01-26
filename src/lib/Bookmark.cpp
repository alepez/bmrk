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

} /* bmrk  */
