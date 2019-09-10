//
// Created by uic15073 on 8/30/2019.
//

#ifndef IDPS_BADFLAG_H
#define IDPS_BADFLAG_H

#include "Actions.h"

namespace idps{
    class BadFlag :public Action {
    public:
    void launch(std::string &details) override ;

    explicit BadFlag(const Notify *notify1);
};
}


#endif //IDPS_BADFLAG_H
