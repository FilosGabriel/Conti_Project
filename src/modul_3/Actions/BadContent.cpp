//
// Created by root on 8/5/19.
//

#include "BadContent.h"
#include "../../Communication/Modul_3.h"

void idps::BadContent::launch(std::string &details) {
    auto list = Modul_3::read_bad_content();
    std::string command = "iptables -i ens32 -A INPUT  -s " + list.at(0);
    for (size_t i = 1; i < list.size(); i++)
        command += "," + list.at(i);
    command+=" -j DROP";
    Modul_3::clear_bad_content();
    notify->send("1", "Block IP:" + details);
}

idps::BadContent::BadContent(const idps::Notify *notify1) : Action(notify1) {}


