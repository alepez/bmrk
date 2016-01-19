#include "Database.hpp"
#include "Bookmark.hpp"
#include <openssl/sha.h>

Database::Database(const Config& config)
		: root_{config.at("root")} {
}

void Database::add(const BookmarkPtr& bookmark) {
	auto path = this->getAbsolutePath(this->getPath(*bookmark));
}

std::string getSha1String(const std::string& str) {
	std::string result;
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, str.c_str(), str.size());
	unsigned char hash[SHA_DIGEST_LENGTH];
	SHA1_Final(hash, &ctx);
	char buf[3];
	for (int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
		sprintf(buf, "%02x", hash[i]);
		result.append(buf);
	}
	return result;
}

std::string Database::getPath(const Bookmark& bookmark) {
	auto&& hash = getSha1String(bookmark.url);
	return hash.substr(0, 2) + "/" + hash.substr(2, 2) + "/" + hash;
}

std::string Database::getAbsolutePath(const std::string& path) {
	return root_ + "/" + path;
}
