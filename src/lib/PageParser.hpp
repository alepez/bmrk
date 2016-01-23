#ifndef PAGEPARSER_HPP_GUTITDEQ
#define PAGEPARSER_HPP_GUTITDEQ

#include <string>
#include <memory>
#include "bmrk_fwd.hpp"

class CDocument;

namespace bmrk {

/**
 * Parse html string and get info from it
 */
class PageParser {
public:
  /**
   * \param html the page's html
   */
  PageParser(const String& html);

  /**
   * \return the page's title
   */
  String getTitle() const;
  /**
   * \return the page's description
   */
  String getNotes() const;

private:
  std::shared_ptr<CDocument> doc_;
};

} /* bmrk  */
#endif /* end of include guard: PAGEPARSER_HPP_GUTITDEQ */
