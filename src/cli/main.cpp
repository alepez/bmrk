#include <string>
#include <boost/program_options.hpp>
#include "../lib/Database.hpp"
#include "../lib/Library.hpp"
#include "../lib/Bookmark.hpp"

namespace po = boost::program_options;

std::string getUserRootDir() {
	if (::getenv("BMRK_DIR")) {
		return ::getenv("BMRK_DIR");
	}

	std::string homeDir = ::getenv("HOME");
	/* linux */
	return homeDir += "/.config/bmrk";
	// FIXME support other OS
}

void add(
		std::string url, std::string title, std::string tags, std::string notes) {
	Config config({{"root", getUserRootDir()}});
	DatabasePtr db = std::make_shared<Database>(config);
	Library library;
	library.connect(db);
	library.add(
			std::make_shared<Bookmark>(url, title, Bookmark::parseTags(tags), notes));
}

int main(int argc, char* argv[]) {
	po::options_description desc{"bmrk"};

	desc.add_options()																							 //
			("url,u", po::value<std::string>(), "Url")									 //
			("title,t", po::value<std::string>(), "Title")							 //
			("tags,a", po::value<std::string>(), "Comma separated tags") //
			("notes,n", po::value<std::string>(), "Notes");							 //

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);

	if (vm.count("url") && vm.count("title") && vm.count("tags") &&
			vm.count("notes")) {
		add(vm["url"].as<std::string>(),
				vm["title"].as<std::string>(),
				vm["tags"].as<std::string>(),
				vm["notes"].as<std::string>());
	}

	return 0;
}
