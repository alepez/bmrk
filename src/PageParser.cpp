#include "PageParser.hpp"

#include <gumbo-query/Node.h>
#include <gumbo-query/Document.h>

PageParser::PageParser(const std::string& html) {
	doc_.reset(new CDocument);
	doc_->parse(html.c_str());
}

std::string PageParser::getTitle() const {
	return doc_->find("head title").nodeAt(0).text();
}
