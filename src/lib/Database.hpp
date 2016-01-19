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

	std::string getPath(const Bookmark&);

	std::string getAbsolutePath(const std::string&);

private:
	const std::string root_;
};

#endif /* end of include guard: DATABASE_HPP_AR2QUN8L */