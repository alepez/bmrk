#ifndef BMRK_HPP_0Q6IB5LJ
#define BMRK_HPP_0Q6IB5LJ

#include "bmrk_fwd.hpp"

namespace bmrk {

/**
 * Bmrk
 */
class Bmrk {
public:
  /**
   * \param downloader the PageDownloader this instance will use to download
   * \param db the database
   */
  Bmrk(PageDownloaderPtr downloader, DatabasePtr db);

  /**
   * \return a future with the created bookmark
   */
  Future<BookmarkPtr> createBookmarkFromUrl(const std::string& url) const;

  void add(BookmarkPtr);

private:
  PageDownloaderPtr downloader_;
  DatabasePtr db_;
  LibraryPtr library_;
};

} /* bmrk  */
#endif /* end of include guard: BMRK_HPP_0Q6IB5LJ */
