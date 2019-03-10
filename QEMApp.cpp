#include "QEMApp.h"

#include <vector>
#include <iostream>

#include "Vector3.h"


QEMApp::QEMApp(const std::vector<std::string>& args) :
 debugEnabled_(false)
{
    parseArgs(args);
}

void QEMApp::parseArgs(const std::vector<std::string>& args)
{
    for (auto it = args.begin(); it != args.end(); ++it) {
        if ((*it == "-f" || *it == "--file") && ++it != args.end()) {
            plyFile_ = *it;
        } else if (*it == "-d" || *it == "--debug") {
            debugEnabled_ = true;
        } else {
            std::cerr << "qem : illegal optin " << *it << "\n"
                      << "Usage : qem [-f ply_file] [-d]\n" 
                      << "  -f, --file ply_file        specified ply file\n"
                      << "  -d, --debug                enable debug mode\n"
                      << std::endl;
            exit(1);
        }
    }
}

void QEMApp::print()
{
    std::cout << "-f : " << plyFile_ << "\n"
              << "-d : " << (debugEnabled_ ? "ON" : "OFF") << "\n"
              << std::endl;
}
