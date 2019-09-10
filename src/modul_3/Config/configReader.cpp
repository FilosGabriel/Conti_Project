//
// Created by root on 8/5/19.
//

#include <vector>
#include <sys/stat.h>
#include <fatalError.h>
#include <iostream>
#include <fstream>
#include <configReader.h>
#include <Constants.h>
#include <configuration.h>
#include <PatternReader.h>

#define DELIMITER '='
#define DONT_EXISTS 0
#define WRITE_MODE "w"
using namespace idps;

void ConfigReader::createDefaultConfigFile() {
    auto configFile = fopen(DEFAULT_CONFIG_FILE, WRITE_MODE);
    if (!configFile)
        throw FatalError("Error creating config file");
    fprintf(configFile, "log_file_location=%s\nflags=\nip=\nblacklist_file=/etc/conti_app_conf/m_3/blacklist\nport=9997",
            DEFAULT_LOG_FILE);
    fclose(configFile);
}


void ConfigReader::loadConfFile(const std::string &location, std::map<std::string, std::string> &conf) {
    std::ifstream infile(location);
    if (!infile)
        throw FatalError("Configuration file don't exist at: " + location);

    std::string line;
    while (std::getline(infile, line)) {
        std::size_t pos = line.find_first_of(DELIMITER);
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        conf[key] = value;
        conf["interface"];
    }
}

bool ConfigReader::existFile(const std::string &locationFile) {
    struct stat buffer{};
    return (stat(locationFile.c_str(), &buffer) == DONT_EXISTS);
}

Configuration *ConfigReader::getConfiguration() noexcept(false) {
    if (existFile(DEFAULT_CONFIG_FILE)) {
        std::map<std::string, std::string> conf;
        loadConfFile(DEFAULT_CONFIG_FILE, conf);
        auto config = new Configuration(conf);
        config->setPattern(PatternReader::readFile(config->getBlacklistLocation()));
        return config;
    } else {
        createDefaultConfigFile();
        std::string error = "Config file was created";
        error += DEFAULT_CONFIG_FILE;
        error += ". Change the parameters there";
        throw FatalError(error);
    }
}

std::vector<std::string> ConfigReader::getIpsList() {
    std::ifstream infile("/etc/conti_app_conf/m_3/ip_blocked");\
    if (!infile) {
        throw FatalError("Configuration file don't exist at: /etc/conti_app_conf/m_3/ip_blocked");
    }

    std::string line;
    std::vector<std::string> tmp;
    while (std::getline(infile, line))
        tmp.push_back(line);

    return tmp;
}

