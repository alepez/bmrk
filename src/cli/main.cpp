#include <string>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
	po::options_description desc{"bmrk"};

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	return 0;
}
