#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include <functional>
#include <string>

class PageDownloader {
public:
	PageDownloader();
    std::string load(const std::string& url);
private:
    const std::string url_;
};

#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
