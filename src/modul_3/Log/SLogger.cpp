//
// Created by uic15073 on 8/13/2019.
//

#include "SLogger.h"

void idps::SLogger::send(const std::string &messageSt, const std::string &message) const {
    loggerStat->send(messageSt);
    loggerNormal->send(message);
}

idps::SLogger::SLogger(std::string logLoccation, std::string stLocation) {
    this->loggerNormal = new Logger(logLoccation, 1);
    this->loggerStat = new Logger(stLocation, 0);

}

void idps::SLogger::send(const std::string &message) const {
    loggerNormal->send(message);
}

idps::SLogger::~SLogger() {
    free(this->loggerNormal);
    free(this->loggerStat);

}
