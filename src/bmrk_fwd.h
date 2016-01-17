#include <memory>
#include <string>
#include <vector>

class Bookmark;

using BookmarkPtr = std::shared_ptr<const Bookmark>;

using Tag = std::string;
using Tags = std::vector<Tag>;
