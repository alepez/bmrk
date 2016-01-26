#include "Bookmark.hpp"
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

} /* bmrk  */
