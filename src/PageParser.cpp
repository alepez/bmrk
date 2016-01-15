#include "PageParser.hpp"

#include <gumbo-query/Node.h>
#include <gumbo-query/Document.h>

PageParser::PageParser(const std::string& html)
		: html_{html} {
}

std::string PageParser::getTitle() const {
	CDocument doc;
	doc.parse(html_.c_str());

	CSelection c = doc.find("h1 a");
	/* std::cout << c.nodeAt(0).text() << std::endl; // some link */
}
