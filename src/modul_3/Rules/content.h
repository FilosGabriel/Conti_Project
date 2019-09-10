//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_CONTENT_H
#define IDPS_NEW_CONTENT_H

#include "Rule.h"
#include "../Config/configuration.h"
#include <vector>
#include <string>
#include <command.h>

namespace idps {

    class Content : public Rule {
    public:
        Content(Configuration *configuration, const NotifySender *sender);



        void execute(Packet &packet) override;

    private:
        std::vector<std::string> badIp{};
        BasicPattern *patternSearch;
        idps::Command *command;
    };
}


#endif //IDPS_NEW_CONTENT_H
