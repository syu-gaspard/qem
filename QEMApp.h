#ifndef __QEM_APP_H__
#define __QEM_APP_H__

#include<vector>
#include<string>

class QEMApp
{
public:
    QEMApp(const std::vector<std::string>& args);

    void print();

private:
    void parseArgs(const std::vector<std::string>& args);
    std::string plyFile_;
    bool debugEnabled_;
};

#endif /* __QEM_APP_H__ */
