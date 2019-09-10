//
// Created by uic15073 on 8/26/2019.
//

#include "OtherModule.h"
#include "../../Communication/Modul_2.h"
#include "../../Communication/Modul_3.h"

int OtherModule::lastPack = -1;

OtherModule::OtherModule(idps::Configuration *configuration, const idps::NotifySender *sender) : Rule(configuration,
                                                                                                      sender) {
    command = new idps::Command(configuration->getNotify(), configuration);
    start = system_clock::now();
    end = system_clock::now();
}

void OtherModule::execute(Packet &packet) {
    end = system_clock::now();
    auto elapsed = end - start;

    if (duration_cast<seconds>(elapsed).count() > 1) {
        packetRate = Modul_2::read_packetrate();

        start = end;
        auto ips = Modul_2::read_packets();
        for (auto const &ip  :ips) {
            if (isNewerThanLastPacket(ip)) {
                configuration->addIp(ip);
            }
        }
        if (packetRate.size() > 0)
            std::cout << "\n\nModule 3  packet rate from module 2:" + packetRate.at(packetRate.size() - 1)+"\n";


        for (auto const &action  :Modul_3::read_action()) {
            command->run(action, "action");
        }

        configuration->getNotify()->send("am primit packet rate");
    }


}

bool OtherModule::isNewerThanLastPacket(std::string packet) {
    int pos = packet.find_first_of("->");
    int pack = atoi(packet.substr(0, pos).c_str());
    if (pack > lastPack) {
        lastPack = pack;
        return true;
    }
    return false;
}
