#include "Bookmark.hpp"
#include <openssl/sha.h>

std::string Bookmark::getID(const std::string& url) {
	std::string result;
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, url.c_str(), url.size());
	unsigned char hash[SHA_DIGEST_LENGTH];
	SHA1_Final(hash, &ctx);
	char buf[3];
	for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
		sprintf(buf, "%02x", hash[i]);
		result.append(buf);
	}
	return result;
}
