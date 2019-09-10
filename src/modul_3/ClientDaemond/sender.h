//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_SENDER_H
#define IDPS_NEW_SENDER_H

#include <string>

namespace idps {
    class NotifySender {
    public:
        virtual void sendToServer(std::string message) const=0;

    };
}


#endif //IDPS_NEW_SENDER_H
