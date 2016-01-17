#ifndef PAGEPARSER_HPP_GUTITDEQ
#define PAGEPARSER_HPP_GUTITDEQ

#include <string>
#include <memory>

class CDocument;

class PageParser {
public:
	PageParser(const std::string& html);

	std::string getTitle() const;

private:
	std::shared_ptr<CDocument> doc_;
};

#endif /* end of include guard: PAGEPARSER_HPP_GUTITDEQ */
