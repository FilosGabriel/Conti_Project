//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_NOTIFY_H
#define IDPS_NEW_NOTIFY_H

#include <string>

namespace idps {
    class Notify {
    public:
        virtual void send(const std::string &message) const = 0;
        virtual void send(const std::string &messageSt,const std::string &message) const = 0;
    };
}


#endif //IDPS_NEW_NOTIFY_H
