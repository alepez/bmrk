#include "Utils.hpp"

namespace utils {
std::string formatId(Id id) {
  std::string result;
  result.reserve(id.size() * 2);
  char buf[3];
  for (auto&& i : id) {
    sprintf(buf, "%02x", i);
    result.append(buf);
  }
  return result;
}
} /* utils */
