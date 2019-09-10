//
// Created by uic15073 on 8/13/2019.
//

#include <configuration.h>
#include <iostream>
#include "BadIp.h"

using namespace idps;

void idps::BadIp::launch(std::string &details) {
     configuration->addIp(details);
}

idps::BadIp::BadIp(const idps::Notify *notify1, Configuration *configuration) : Action(notify1) {
    this->configuration = configuration;
}
