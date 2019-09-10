//
// Created by root on 8/7/19.
//

#include <iostream>
#include "testActions.h"

void idps::TestActions::launch(std::string &details) {
    std::cout << "test  " + details<<std::endl;

}

idps::TestActions::TestActions(const idps::Notify *notify1) : Action(notify1) {}
