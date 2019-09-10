//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_CHRISTMASTREE_H
#define IDPS_NEW_CHRISTMASTREE_H

#include <command.h>
#include "Rule.h"
#include "../Config/configuration.h"

namespace idps {
    class Christmas : public Rule {
    public:
        void execute(Packet &packet) override ;

        Christmas( Configuration *configuration, const NotifySender *sender);

    private:
        std::vector<std::string> vectorOfFlags{};
        std::string myIP{};
        idps::Command *command;


    };
}


#endif //IDPS_NEW_CHRISTMASTREE_H
