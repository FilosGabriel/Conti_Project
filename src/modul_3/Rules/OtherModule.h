//
// Created by uic15073 on 8/26/2019.
//

#ifndef IDPS_OTHERMODULE_H
#define IDPS_OTHERMODULE_H


#include <command.h>
#include "Rule.h"

using namespace std;
using namespace chrono;


class OtherModule : public idps::Rule {
private:
    std::vector<std::string> packetRate;
    std::vector<std::string> badIps;
    idps::Command *command;

    static int lastPack;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
public:
    OtherModule(idps::Configuration *configuration, const idps::NotifySender *sender);

    void execute(Packet &packet) override;

    static bool isNewerThanLastPacket(std::string packet);


};


#endif //IDPS_OTHERMODULE_H
