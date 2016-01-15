#ifndef PAGEPARSER_HPP_GUTITDEQ
#define PAGEPARSER_HPP_GUTITDEQ

#include <string>

class PageParser {
public:
	PageParser(const std::string& html);

  std::string getTitle() const;

private:
  std::string html_;
};

#endif /* end of include guard: PAGEPARSER_HPP_GUTITDEQ */
