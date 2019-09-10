//
// Created by root on 8/5/19.
//

#include <sys/stat.h>
#include <iostream>
#include <cstring>
#include <fatalError.h>
#include "logger.h"
#include "../Config/Constants.h"
#include "../Utils/date.h"

#define FOLDER_LOGS_PERMISSIONS 0777
#define ERROR_CREATE_DIRECTORY (-1)
#define  APPEND "a"

using namespace idps;

FILE *Logger::createLogFile(const std::string &locationLogFile) {
    if (mkdir(DEFAULT_FOLDER_LOGS, FOLDER_LOGS_PERMISSIONS) == ERROR_CREATE_DIRECTORY && errno != EEXIST) {
        std::cerr << "Error :  " << strerror(errno) << std::endl;
        exit(errno);
    }
    logFile = fopen(locationLogFile.c_str(), "w");
    if (!logFile)
        throw FatalError("Fail to create log file");
    fprintf(logFile, "Created log file at %s\n", Date::getTimeNow());
    return logFile;
}

bool Logger::existFile(const std::string &locationLogFile) {
    struct stat buffer{};
    return (stat(locationLogFile.c_str(), &buffer) == 0);
}

void Logger::send(const std::string &message) const {
    if (type)
        fprintf(logFile, "[%s] %s \n", Date::getTimeNow(), message.c_str());
    else
        fprintf(logFile, "%s,%s \n", Date::getTimeNow(), message.c_str());
}

Logger::Logger(const std::string &location, int type) {
    this->type = type;
    this->logFile = !this->existFile(location) ? createLogFile(location) : fopen(location.c_str(), APPEND);
}

Logger::~Logger() {
    fclose(logFile);
}

