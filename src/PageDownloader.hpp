#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include <string>
#include <future>

/**
 * Download a document from a remote url
 */
class PageDownloader {
public:
	/**
	 * \return a future with the downloaded document
	 */
	virtual std::future<std::string> load(const std::string& url) const;
};

#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
