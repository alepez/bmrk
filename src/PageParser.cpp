#include "PageParser.hpp"

#include <gumbo-query/Node.h>
#include <gumbo-query/Document.h>

PageParser::PageParser(const std::string& html)
		: doc_{new CDocument} {
	if (html.empty()) {
		throw std::runtime_error{"Empty document"};
	}
	doc_->parse(html.c_str());
}

std::string PageParser::getTitle() const {
	auto&& node = doc_->find("head title").nodeAt(0);
	if (!node.valid()) {
		throw std::runtime_error{"Cannot parse title"};
	}
	return node.text();
}
