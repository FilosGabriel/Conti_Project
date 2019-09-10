//
// Created by root on 8/7/19.
//

#ifndef IDPS_NEW_TESTACTIONS_H
#define IDPS_NEW_TESTACTIONS_H

#include "Actions.h"

namespace idps {
    class TestActions : public Action {
    public:
        void launch(std::string &details) override;

        explicit TestActions(const Notify *notify1);
    };
}


#endif //IDPS_NEW_TESTACTIONS_H
