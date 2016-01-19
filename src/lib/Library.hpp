#ifndef LIBRARY_HPP_AZX093RT
#define LIBRARY_HPP_AZX093RT

#include "bmrk_fwd.hpp"

/**
 * Keeps all the bookmarks and filter them
 */
class Library {
public:
	/**
	 * Add a bookmark
	 */
	void add(BookmarkPtr);

	/**
	 * \return all the bookmarks
	 */
	Bookmarks getAll() const;

	/**
	 * \return filtered bookmarks
	 * \param filter a function that accept Bookmarks and return Bookmarks
	 */
	Bookmarks filter(ExplicitFilter filter) const;

	/**
	 * \return filtered bookmarks
	 * \param filter a function that accept Bookmark and return bool
	 */
	Bookmarks filter(Filter filter) const;

private:
	Bookmarks bookmarks_;
};

#endif /* end of include guard: LIBRARY_HPP_AZX093RT */
