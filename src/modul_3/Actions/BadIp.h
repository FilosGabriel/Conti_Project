//
// Created by uic15073 on 8/13/2019.
//

#ifndef IDPS_BADIP_H
#define IDPS_BADIP_H

#include "Actions.h"

namespace idps {
    class BadIp : public Action {
    public:
        void launch(std::string &details) override;

        BadIp(const Notify *notify1, Configuration *configuration);

    private:
        Configuration *configuration;
    };
}


#endif //IDPS_BADIP_H
