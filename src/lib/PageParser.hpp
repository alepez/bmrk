#ifndef PAGEPARSER_HPP_GUTITDEQ
#define PAGEPARSER_HPP_GUTITDEQ

#include <string>
#include <memory>

class CDocument;

/**
 * Parse html string and get info from it
 */
class PageParser {
public:
	/**
	 * \param html the page's html
	 */
	PageParser(const std::string& html);

	/**
	 * \return the page's title
	 */
	std::string getTitle() const;
	/**
	 * \return the page's description
	 */
	std::string getNotes() const;

private:
	std::shared_ptr<CDocument> doc_;
};

#endif /* end of include guard: PAGEPARSER_HPP_GUTITDEQ */
