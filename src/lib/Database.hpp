#ifndef DATABASE_HPP_AR2QUN8L
#define DATABASE_HPP_AR2QUN8L

#include "bmrk_fwd.hpp"

class Database {
public:
	/**
	 * \param config a map with configuration
	 */
	Database(const Config& config);

	void add(const BookmarkPtr&);

	void remove(const BookmarkPtr&);

	Bookmarks getAllBookmarks() const;

	std::string getPath(const Bookmark&);

	std::string getAbsolutePath(const std::string&);

	void write(std::ostream&, const BookmarkPtr&);

	BookmarkPtr read(std::istream&) const;

	void clear();

private:
	const std::string root_;
};

#endif /* end of include guard: DATABASE_HPP_AR2QUN8L */
