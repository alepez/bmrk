#ifndef PAGEDOWNLOADER_HPP_R1YIYM0U
#define PAGEDOWNLOADER_HPP_R1YIYM0U

#include "bmrk_fwd.hpp"
#include <string>
#include <future>

namespace bmrk {

/**
 * Download a document from a remote url
 */
class PageDownloader {
public:
  /**
   * \return a future with the downloaded document
   */
  virtual Future<String> load(const String& url) const;
};

} /* bmrk  */
#endif /* end of include guard: PAGEDOWNLOADER_HPP_R1YIYM0U */
