#ifndef HELPERS_HPP_MRZHJLG4
#define HELPERS_HPP_MRZHJLG4

#include <Bookmark.hpp>

namespace bmrk {

BookmarkPtr createMockBookmark(
    String url = "", String title = "", Tags tags = Tags{}, String notes = "");

} /* bmrk  */
#endif /* end of include guard: HELPERS_HPP_MRZHJLG4 */
