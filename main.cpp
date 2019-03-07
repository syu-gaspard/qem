#include<iostream>
#include<vector>

#include "QEMApp.h"

namespace {
    QEMApp* createQEMApp(const std::vector<std::string>& args) { return new QEMApp(args); }
    QEMApp* createApp(int argc, const char* argv[])
    {
        return createQEMApp(std::vector<std::string>(&argv[1], argv + argc));
    }
}

int main(int argc, const char* argv[])
{
    QEMApp* app = createApp(argc, argv);
    app->Print();
    return 0;
}
