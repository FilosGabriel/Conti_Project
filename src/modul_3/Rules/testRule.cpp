//
// Created by root on 8/7/19.
//

#include <iostream>
#include <zconf.h>
#include "testRule.h"

using namespace idps;


idps::TestRule::TestRule(idps::Configuration *configuration, const idps::NotifySender *sender) : Rule(configuration,
                                                                                                      sender) {}

void TestRule::execute(Packet &packet) {
    std::string temp;
    std::string src;
    std::string flags;
    try {
        temp = packet.getData();
    } catch (const std::out_of_range &oor) {
        std::cerr << "Out of Range data error: " << oor.what() << '\n';
    }
    try {
        src = packet.getSrc();
    } catch (const std::out_of_range &oor) {
        std::cerr << "Out of Range src error: " << oor.what() << '\n';
    }
    try {
        flags = packet.getFlags();
    } catch (const std::out_of_range &oor) {
        std::cerr << "Out of Range flags error: " << oor.what() << '\n';
    }
//    printf("src:%s\nflags:%s\ndata:%s\n\n\n", src.c_str(), flags.c_str(),
//           temp.c_str());
//    free(temp);
}


