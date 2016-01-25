#ifndef BOOKMARKDATA_HPP_JCCM1IQ6
#define BOOKMARKDATA_HPP_JCCM1IQ6

#include "bmrk_fwd.hpp"

namespace bmrk {

struct BookmarkData {
  Url url;
  Title title;
  Tags tags;
  Notes notes;
};

} /* bmrk */

#endif /* end of include guard: BOOKMARKDATA_HPP_JCCM1IQ6 */
