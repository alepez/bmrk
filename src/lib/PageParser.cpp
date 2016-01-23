#include "PageParser.hpp"

#include <gumbo-query/Node.h>
#include <gumbo-query/Document.h>

PageParser::PageParser(const String& html) : doc_{new CDocument} {
  if (html.empty()) {
    throw Error{"Empty document"};
  }
  doc_->parse(html.c_str());
}

String PageParser::getTitle() const {
  auto&& node = doc_->find("head title").nodeAt(0);
  if (!node.valid()) {
    throw Error{"Cannot parse title"};
  }
  return node.text();
}

String PageParser::getNotes() const {
  // FIXME select by attribute doesn't work
  auto&& node = doc_->find("head meta[name='description']").nodeAt(0);
  return node.valid() ? node.text() : "";
}
