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
using namespace bmrk;

String getUserRootDir() {
  if (::getenv("BMRK_DIR")) {
    return ::getenv("BMRK_DIR");
  }

  String homeDir = ::getenv("HOME");
  /* linux */
  return homeDir += "/.config/bmrk";
  // FIXME support other OS
}

void tryChange(String& str) {
  String line;
  cout << "Change? ";
  std::getline(cin, line);
  if (!line.empty()) {
    str = line;
  }
}

int main(int argc, char* argv[]) {
  po::options_description desc{"bmrk"};

  desc.add_options()                                          //
      ("interactive,i", "Interactive")                        //
      ("url,u", po::value<String>(), "Url")                   //
      ("title,t", po::value<String>(), "Title")               //
      ("tags,a", po::value<String>(), "Comma separated tags") //
      ("notes,n", po::value<String>(), "Notes");              //

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);

  Config config({{"root", getUserRootDir()}});

  auto db = std::make_shared<Database>(config);
  auto dwl = std::make_shared<PageDownloader>();

  Bmrk bmrk{dwl, db};

  auto url = vm.count("url") ? vm["url"].as<String>() : "";
  if (url.empty()) {
    // FIXME here we need a more friendly error
    throw std::runtime_error("url is mandatory");
  }

  auto bm = bmrk.createBookmarkFromUrl(url).get();
	auto bmd = bm->data();

  auto title = vm.count("title") ? vm["title"].as<String>() : bmd.title;
  auto tags = vm.count("tags") ? vm["tags"].as<String>() : Bookmark::formatTags(bmd.tags);
  auto notes = vm.count("notes") ? vm["notes"].as<String>() : bmd.notes;

  if (vm.count("interactive")) {
		std::cerr << "interactive\n";
    String line;

    cout << "Url: " << bmd.url << "\n";

    cout << "Title: " << title << "\n";
    tryChange(title);

    cout << "Tags: " << tags << "\n";
    tryChange(tags);

    cout << "Notes: " << notes << "\n";
    tryChange(notes);
  }

  bmrk.add(std::make_shared<Bookmark>(bmd));

  return 0;
}
