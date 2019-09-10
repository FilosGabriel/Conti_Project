//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_IDPS_H
#define IDPS_NEW_IDPS_H

#include <vector>
#include "../Config/configuration.h"
#include "sender.h"
#include "../Config/Constants.h"
#include "../Rules/Rule.h"

namespace idps {
    class IDPS {

    public:
        IDPS(NotifySender *sender1, Configuration *configuration);

        void run();

        virtual ~IDPS();

    private:
        std::vector<Rule *> vectorOfRule{};
         Configuration* configuration;
        const NotifySender *sender;
        bool continueRun = true;
    };
}


#endif //IDPS_NEW_IDPS_H
