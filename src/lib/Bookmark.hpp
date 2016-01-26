#ifndef BOOKMARK_HPP_4NOOTDNA
#define BOOKMARK_HPP_4NOOTDNA

#include "bmrk_fwd.hpp"
#include "BookmarkData.hpp"

namespace bmrk {

class Bookmark {
public:
  static Id getID(const String& url);

  static Tags parseTags(const String&);
  static String formatTags(const Tags&);

  template <typename D>
  inline Bookmark(D&& data)
      : url{data.url}
      , title{data.title}
      , tags{data.tags}
      , notes{data.notes}
      , id(Bookmark::getID(url)) {
  }

  inline BookmarkData data() const {
    return BookmarkData{url, title, tags, notes};
  }

  const Url url;
  const Title title;
  const Tags tags;
  const Notes notes;

  const Id id;
};

} /* bmrk  */
#endif /* end of include guard: BOOKMARK_HPP_4NOOTDNA */
