//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_LOGGER_H
#define IDPS_NEW_LOGGER_H


#include <cstdio>
#include <string>
#include "Notify.h"

namespace idps {
    class Logger {
    private:
        FILE *logFile;
        int type;

        FILE *createLogFile(const std::string &locationLogFile);

        static bool existFile(const std::string &locationLogFile);

    public:
        void send(const std::string &message) const;

        explicit Logger(const std::string &location, int type);

        virtual ~Logger();

    };
}


#endif //IDPS_NEW_LOGGER_H
