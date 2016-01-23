#ifndef DATABASE_HPP_AR2QUN8L
#define DATABASE_HPP_AR2QUN8L

#include "bmrk_fwd.hpp"

namespace bmrk {

class Database {
public:
  /**
   * \param config a map with configuration
   */
  Database(const Config& config);

  void add(const BookmarkPtr&);

  void remove(const BookmarkPtr&);

  Bookmarks getAllBookmarks() const;

  String getPath(const Bookmark&);

  String getAbsolutePath(const String&);

  void write(std::ostream&, const BookmarkPtr&);

  BookmarkPtr read(std::istream&) const;

  void clear();

private:
  const String root_;
};

} /* bmrk  */
#endif /* end of include guard: DATABASE_HPP_AR2QUN8L */
