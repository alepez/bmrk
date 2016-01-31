#ifndef DATABASE_HPP_AR2QUN8L
#define DATABASE_HPP_AR2QUN8L

#include "bmrk_fwd.hpp"
#include "BookmarkSerializer.hpp"
#include "BookmarkDeserializer.hpp"

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

  void clear();

private:
  const String root_;
	const std::unique_ptr<BookmarkSerializer> serializer_;
	const std::unique_ptr<BookmarkDeserializer> deserializer_;
};

} /* bmrk  */
#endif /* end of include guard: DATABASE_HPP_AR2QUN8L */
