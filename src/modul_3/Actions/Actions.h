//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_ACTIONS_H
#define IDPS_NEW_ACTIONS_H

#include "../Log/Notify.h"

namespace idps {
    class Action {
    public:
        virtual void launch(std::string &details) = 0;

    protected:
        const Notify *notify;

        explicit Action(const Notify *notify1) : notify(notify1) {};
    };
}


#endif //IDPS_NEW_ACTIONS_H
