#include "UUID.hpp"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace bmrk {

UUID makeUUID() {
	UUID v;
	auto u = boost::uuids::random_generator()();
	std::copy(u.begin(), u.end(), v.begin());
	return v;
}

String formatUUID(UUID id) {
  String result;
  result.reserve(id.size() * 2);
  char buf[3];
  for (auto&& i : id) {
    sprintf(buf, "%02x", i);
    result.append(buf);
  }
  return result;
}


} /* bmrk */

