//
// Created by root on 8/7/19.
//

#ifndef IDPS_NEW_TESTRULE_H
#define IDPS_NEW_TESTRULE_H

#include "Rule.h"
#include "../Config/configuration.h"

namespace idps {
    class TestRule : public Rule {
    public:
        TestRule(Configuration *configuration, const NotifySender *sender);


        void execute(Packet &packet) override;

    };
}


#endif //IDPS_NEW_TESTRULE_H
