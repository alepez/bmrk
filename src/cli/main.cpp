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

  desc.add_options()                                               //
      ("interactive,i", "Interactive")                             //
      ("url,u", po::value<std::string>(), "Url")                   //
      ("title,t", po::value<std::string>(), "Title")               //
      ("tags,a", po::value<std::string>(), "Comma separated tags") //
      ("notes,n", po::value<std::string>(), "Notes");              //

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);

  bmrk::Config config({{"root", getUserRootDir()}});

  auto db = std::make_shared<bmrk::Database>(config);
  auto dwl = std::make_shared<bmrk::PageDownloader>();

  bmrk::Bmrk bmrk{dwl, db};

  auto url = vm.count("url") ? vm["url"].as<std::string>() : "";
  if (url.empty()) {
    // FIXME here we need a more friendly error
    throw std::runtime_error("url is mandatory");
  }

  auto bm = bmrk.createBookmarkFromUrl(url).get();

  auto title = vm.count("title") ? vm["title"].as<std::string>() : bm->title;
  auto tags = vm.count("tags") ? vm["tags"].as<std::string>()
                               : bmrk::Bookmark::formatTags(bm->tags);
  auto notes = vm.count("notes") ? vm["notes"].as<std::string>() : bm->notes;

  if (vm.count("interactive")) {
    std::string line;

    cout << "Url: " << bm->url << "\n";

    cout << "Title: " << title << "\n";
    if (title.empty()) tryChange(title);

    cout << "Tags: " << tags << "\n";
    if (tags.empty()) tryChange(tags);

    cout << "Notes: " << notes << "\n";
    if (notes.empty()) tryChange(notes);
  }

  bm = setTitle(bm, title);
  bm = setTags(bm, bmrk::Bookmark::parseTags(tags));
  bm = setNotes(bm, notes);

  bmrk.add(bm);

  return 0;
}
