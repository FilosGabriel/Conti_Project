//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_CONFIGREADER_H
#define IDPS_NEW_CONFIGREADER_H


#include "configuration.h"
namespace idps{
    class ConfigReader {
    public:
        static  Configuration* getConfiguration();
        static std::vector<std::string> getIpsList();

    private:

        static bool existFile(const std::string &locationFile);

        static void createDefaultConfigFile();

        static void loadConfFile(const std::string &location, std::map<std::string, std::string> &conf);

    };
}



#endif //IDPS_NEW_CONFIGREADER_H
