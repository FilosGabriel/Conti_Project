//
// Created by uic15073 on 8/13/2019.
//

#ifndef IDPS_SLOGGER_H
#define IDPS_SLOGGER_H

#include "Notify.h"
#include "logger.h"

namespace idps {
    class SLogger: public Notify {
    private:
        Logger *loggerNormal;
        Logger *loggerStat;
    public:
        SLogger(std::string logLoccation,std::string stLocation);
        void send(const std::string &message) const override ;
        void send(const std::string &messageSt,const std::string &message) const override;

        virtual ~SLogger();
    };
}


#endif //IDPS_SLOGGER_H
