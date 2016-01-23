#include "Utils.hpp"

namespace bmrk {

namespace utils {
String formatId(Id id) {
  String result;
  result.reserve(id.size() * 2);
  char buf[3];
  for (auto&& i : id) {
    sprintf(buf, "%02x", i);
    result.append(buf);
  }
  return result;
}
} /* utils */
} /* bmrk  */
