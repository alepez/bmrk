#include <string>
#include <iostream>
#include <boost/program_options.hpp>
#include "../lib/Database.hpp"
#include "../lib/PageDownloader.hpp"
#include "../lib/Library.hpp"
#include "../lib/Bookmark.hpp"
#include "../lib/Bmrk.hpp"

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

int main(int argc, char* argv[]) {
	po::options_description desc{"bmrk"};

	desc.add_options()																							 //
			("interactive,i", "Interactive")					 //
			("url,u", po::value<std::string>(), "Url")									 //
			("title,t", po::value<std::string>(), "Title")							 //
			("tags,a", po::value<std::string>(), "Comma separated tags") //
			("notes,n", po::value<std::string>(), "Notes");							 //

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);

	Config config({{"root", getUserRootDir()}});

	auto db = std::make_shared<Database>(config);
	auto dwl = std::make_shared<PageDownloader>();

	Bmrk bmrk{dwl, db};

	BookmarkPtr bm;

	if (vm.count("url")) {
		bm = bmrk.createBookmarkFromUrl(vm["url"].as<std::string>()).get();
	}

	if (vm.count("title")) {
		bm = setTitle(bm, vm["title"].as<std::string>());
	}

	if (vm.count("tags")) {
		bm = setTags(bm, Bookmark::parseTags(vm["tags"].as<std::string>()));
	}

	if (vm.count("notes")) {
		bm = setNotes(bm, vm["notes"].as<std::string>());
	}

	if (vm.count("interactive")) {
		std::cout << "Url: " << bm->url << "\n";
		std::cout << "Title: " << bm->title << "\n";
		std::cout << "Tags: " << Bookmark::formatTags(bm->tags) << "\n";
		std::cout << "Notes: " << bm->notes << "\n";
		// FIXME ask for new title,tags,notes...
	}

	bmrk.add(bm);

	return 0;
}
