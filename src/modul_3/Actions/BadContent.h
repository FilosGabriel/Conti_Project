//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_BLOCKIP_H
#define IDPS_NEW_BLOCKIP_H


#include <search.h>
#include "Actions.h"

namespace idps{
    class BadContent: public Action {
    public:
        void launch(std::string &details) override ;

        explicit BadContent(const Notify *notify1);
    };
}




#endif //IDPS_NEW_BLOCKIP_H
