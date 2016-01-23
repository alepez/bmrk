#ifndef LIBRARY_HPP_AZX093RT
#define LIBRARY_HPP_AZX093RT

#include "bmrk_fwd.hpp"

namespace bmrk {

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
   *
   * Remove a bookmark
   */
  void remove(BookmarkPtr);

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

  /**
   * connect to a database
   * \param db the database
   */
  void connect(DatabasePtr db);

private:
  Bookmarks bookmarks_;
  DatabasePtr db_;
};

} /* bmrk  */
#endif /* end of include guard: LIBRARY_HPP_AZX093RT */
