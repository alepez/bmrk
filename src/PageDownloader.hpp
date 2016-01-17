#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include <string>
#include <future>

class PageDownloader {
public:
	virtual std::future<std::string> load(const std::string& url) const;
};

#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
