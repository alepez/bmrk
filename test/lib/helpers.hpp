#ifndef HELPERS_HPP_MRZHJLG4
#define HELPERS_HPP_MRZHJLG4

#include <Bookmark.hpp>

BookmarkPtr createMockBookmark(std::string url = "",
		std::string title = "",
		std::string notes = "",
		Tags tags = Tags{});

#endif /* end of include guard: HELPERS_HPP_MRZHJLG4 */
