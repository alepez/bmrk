#ifndef BOOKMARK_HPP_4NOOTDNA
#define BOOKMARK_HPP_4NOOTDNA

#include "bmrk_fwd.hpp"

class Bookmark {
public:
  static Id getID(const String& url);

  static Tags parseTags(const String&);
  static String formatTags(const Tags&);

  template <typename U, typename T, typename N, typename S>
  inline Bookmark(U&& aurl, T&& atitle, S&& atags, N&& anotes)
      : url{aurl}
      , title{atitle}
      , tags{atags}
      , notes{anotes}
      , id(Bookmark::getID(url)) {
    // FIXME id{Bookmark::getID(url)} works with clang 3.7 but not with gcc 4.9
    // (it wants round parens)
  }

  const Url url;
  const Title title;
  const Tags tags;
  const Notes notes;

  const Id id;
};

BookmarkPtr setUrl(BookmarkPtr, String);
BookmarkPtr setTitle(BookmarkPtr, String);
BookmarkPtr setTags(BookmarkPtr, Tags);
BookmarkPtr setNotes(BookmarkPtr, String);

#endif /* end of include guard: BOOKMARK_HPP_4NOOTDNA */
