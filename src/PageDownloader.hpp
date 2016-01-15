#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include <functional>
#include <string>

class PageDownloader {
public:
	PageDownloader();
	void load(const std::string& url, std::function<void(std::string)>);
private:
    const std::string url_;
};

#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
