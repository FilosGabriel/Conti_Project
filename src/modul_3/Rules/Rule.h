//explicit Christmas(const NotifySender *sender);
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_RULE_H
#define IDPS_NEW_RULE_H

#include <packet.h>
#include "sender.h"
#include "../Config/configuration.h"

namespace idps {
    class Rule {
    public:


        virtual void execute(Packet &packet) = 0;

        Rule(Configuration *configuration, const NotifySender *sender) : configuration(configuration), sender(sender) {}

    protected:
        Configuration *configuration;

        const NotifySender *sender;

    };


}

#endif //IDPS_NEW_RULE_H
