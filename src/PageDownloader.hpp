#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include <functional>
#include <string>
#include <future>

class PageDownloader {
public:
	PageDownloader();
    std::future<std::string> load(const std::string& url);
private:
    const std::string url_;
};

#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
