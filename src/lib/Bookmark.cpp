#include "Bookmark.hpp"
#include <boost/algorithm/string.hpp>
#include <openssl/sha.h>

Id Bookmark::getID(const std::string& url) {
	Id result(20);
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, url.c_str(), url.size());
	SHA1_Final(result.data(), &ctx);
	return result;
}

Tags Bookmark::parseTags(const std::string& str) {
	Tags tags;
	boost::split(tags, str, boost::is_any_of(","));
	return tags;
}
