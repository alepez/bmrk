#include <string>
#include <iostream>
#include <boost/program_options.hpp>
#include "../lib/Database.hpp"
#include "../lib/PageDownloader.hpp"
#include "../lib/Library.hpp"
#include "../lib/Bookmark.hpp"
#include "../lib/Bmrk.hpp"

namespace po = boost::program_options;
using std::cin;
using std::cout;

std::string getUserRootDir() {
	if (::getenv("BMRK_DIR")) {
		return ::getenv("BMRK_DIR");
	}

	std::string homeDir = ::getenv("HOME");
	/* linux */
	return homeDir += "/.config/bmrk";
	// FIXME support other OS
}

void tryChange(std::string& str) {
	std::string line;
	cout << "Change? ";
	std::getline(cin, line);
	if (!line.empty()) {
		str = line;
	}
}

int main(int argc, char* argv[]) {
	po::options_description desc{"bmrk"};

	desc.add_options()																							 //
			("interactive,i", "Interactive")														 //
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

	auto url = vm.count("url") ? vm["url"].as<std::string>() : "";
	if (url.empty()) {
		// FIXME here we need a more friendly error
		throw std::runtime_error("url is mandatory");
	}

	BookmarkPtr bm = bmrk.createBookmarkFromUrl(url).get();

	auto title = vm.count("title") ? vm["title"].as<std::string>() : "";
	auto tags = vm.count("tags") ? vm["tags"].as<std::string>() : "";
	auto notes = vm.count("notes") ? vm["notes"].as<std::string>() : "";

	if (vm.count("interactive")) {
		std::string line;

		cout << "Url: " << bm->url << "\n";

		cout << "Title: " << bm->title << "\n";
		tryChange(title);

		cout << "Tags: " << Bookmark::formatTags(bm->tags) << "\n";
		tryChange(tags);

		cout << "Notes: " << bm->notes << "\n";
		tryChange(notes);
	}

	bm = setTitle(bm, title);
	bm = setTags(bm, Bookmark::parseTags(tags));
	bm = setNotes(bm, notes);

	bmrk.add(bm);

	return 0;
}
