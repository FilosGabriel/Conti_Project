//
// Created by root on 8/5/19.
//

#include <iostream>
#include "christmasTree.h"
#include "../../Communication/Modul_3.h"


using namespace idps;
//
//void Christmas::execute(ListOfPackets *lisOfPackets) {
//    for (auto &packet : lisOfPackets->getPackets())
//        if (packet->getSrc() != myIP)
//            for (const auto &badFlags : vectorOfFlags)
//                if (badFlags == packet->getFlags()) {
//                    this->sender->sendToServer("0" + badFlags + "|" + packet->getFlags() + "|");
//                    break;
//                }
//
//}

Christmas::Christmas(Configuration *configuration, const NotifySender *sender) : Rule(configuration, sender) {
    this->vectorOfFlags = *configuration->getBadFlags();
    this->command = new Command(configuration->getNotify(), configuration);
}

void Christmas::execute(Packet &packet) {
    if (packet.getSrc() != myIP)
        for (const auto &badFlag : vectorOfFlags)
            if (badFlag == packet.getFlags()) {
//                this->sender->sendToServer("0|" + badFlag + "|" + packet.getFlags() + "|");

                Modul_3::write_bad_flags(packet.getSrc());
                break;
            }

}

