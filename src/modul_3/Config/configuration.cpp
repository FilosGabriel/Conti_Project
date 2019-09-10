//
// Created by root on 8/5/19.
//

#include <sstream>
#include <iostream>
#include <zconf.h>
#include "configuration.h"
#include "Constants.h"
#include "../Utils/output.h"
#include "../Exceptions/fatalError.h"
#include "../Exceptions/invalidParameterException.h"
#include "configReader.h"
#include <algorithm>

#define LOG_FILE_LOCATION "log_file_location"
#define LOG_ST_LOCATION "st_file_location"
#define FLAGS "flags"
#define IP "ip"
#define WHITELIST "whitelist_file"
#define BLACKLIST "blacklist_file"
using namespace idps;


Configuration::Configuration(std::map<std::string, std::string> conf) : conf(std::move(conf)) {
    badBoy = ConfigReader::getIpsList();
}


const std::string &Configuration::getLogFileLocation() const {
    auto it = conf.find(LOG_FILE_LOCATION);
    return it != conf.end() ? it->second : *(new std::string(DEFAULT_LOG_FILE));
}

const std::string &Configuration::getStFileLocation() const {
    auto it = conf.find(LOG_ST_LOCATION);
    return it != conf.end() ? it->second : *(new std::string(DEFAULT_ST_FILE));
}

std::string Configuration::show() const {
    std::string configString;
    for (const auto &[key, value]: conf) (((configString += key) += ":") += value) += ", ";
    return configString;
}


const std::vector<std::string> *Configuration::getBadFlags() const {
    auto value = conf.find(FLAGS);
    auto result = new std::vector<std::string>();
    if (value != conf.end()) {
        std::istringstream iss(value->second);
        for (std::string flag; iss >> flag;)
            result->push_back(flag);
    }
    return result;
}

std::string Configuration::getIp() const {
    auto value = conf.find(IP);
    if (value == conf.end())
        throw InvalidParameterException("IP  is not set in config file");
    return value->second;
}

std::string Configuration::getWhitelistLocation() const {
    auto value = conf.find(WHITELIST);
    if (value == conf.end())
        throw InvalidParameterException("Whitelist file is not set in config file");
    return value->second;
}

std::string Configuration::getBlacklistLocation() const {
    auto value = conf.find(BLACKLIST);
    if (value == conf.end())
        throw InvalidParameterException("Blacklist file is not set in config file");
    return value->second;
}

BasicPattern *const Configuration::getPattern() const {
    return pattern;
}

void Configuration::setPattern(BasicPattern *pattern) {
    this->pattern = pattern;
}

int Configuration::getPort() const {
    auto value = conf.find("port");
    if (value == conf.end())
        throw InvalidParameterException("Port is not set in config file");
    try {
        return std::stoi(value->second, 0, 10);
    } catch (std::invalid_argument &ex) {
        throw InvalidParameterException("Invalid port number");
    }
}


Configuration::~Configuration() {
    free(pattern);

}

int Configuration::getMaxPack() {
    return 10000;
}

void Configuration::addNotify(Notify *notify) {
    this->notify = notify;

}

Notify *Configuration::getNotify() {
    return this->notify;
}

void Configuration::addIp(std::string ip) {
    int pos = ip.find_first_of("->");
    if (std::find(badBoy.begin(), badBoy.end(), ip.substr(pos + 2)) == badBoy.end())
        badBoy.push_back(ip.substr(pos + 2));

}

std::vector<std::string> Configuration::getListIps() {
    return badBoy;
}

