#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include <string>
#include <future>

class PageDownloader {
public:
    std::future<std::string> load(const std::string& url);
};

#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
