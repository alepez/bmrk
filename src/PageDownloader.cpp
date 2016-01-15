#include "PageDownloader.hpp"

#include <curl/curl.h>
#include <curl/easy.h>
#include <sstream>

namespace {

using CurlWriteFunction = size_t (*)(void*, size_t, size_t, void*);

template <typename Callback> void downloadWithCurl(const std::string& url, Callback fn, void* data) {
	auto curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 15);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
	curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");

	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, static_cast<CurlWriteFunction>(fn));
	if (CURLE_OK != curl_easy_perform(curl)) {
		curl_easy_cleanup(curl);
		throw std::runtime_error("Cannot perform download " + url);
	}
	curl_easy_cleanup(curl);
}

template <typename T> void downloadToStreamWithCurl(const std::string& url, T* stream) {
	downloadWithCurl(url, [](void* ptr, size_t size, size_t nmemb, void* data) {
		auto stream = reinterpret_cast<T*>(data);
		stream->write(reinterpret_cast<char*>(ptr), size * nmemb);
		return size * nmemb;
	}, stream);
}

} // end namespace

std::future<std::string> PageDownloader::load(const std::string& url) {
	auto handle = std::async(std::launch::async, [url]() {
		std::stringstream stream;
		downloadToStreamWithCurl(url, &stream);
		return stream.str();
	});
	return handle;
}
