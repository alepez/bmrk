#include "PageParser.hpp"

#include <gumbo-query/Node.h>
#include <gumbo-query/Document.h>

PageParser::PageParser(const std::string& html)
		: html_{html} {
}

std::string PageParser::getTitle() const {
	CDocument doc;
	doc.parse(html_.c_str());
	CSelection c = doc.find("head title");
  return c.nodeAt(0).text();
}
