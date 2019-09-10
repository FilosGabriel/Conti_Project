//
// Created by uic15073 on 8/30/2019.
//

#include "BadFlag.h"
#include "../../Communication/Modul_3.h"

void idps::BadFlag::launch(std::string &details) {
    auto list = Modul_3::read_bad_flags();
    std::string command = "iptables -i ens32 -A INPUT  -s " + list.at(0);
    for (size_t i = 1; i < list.size(); i++)
        command += "," + list.at(i);
    command += " -j DROP";
    Modul_3::clear_bad_flags();
    notify->send("1", "Block IP:" + details);
}

idps::BadFlag::BadFlag(const idps::Notify *notify1) : Action(notify1) {

}
