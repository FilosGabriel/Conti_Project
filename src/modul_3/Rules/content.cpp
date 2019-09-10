//
// Created by root on 8/5/19.
//

#include "content.h"
#include "../../Communication/Modul_3.h"

idps::Content::Content(idps::Configuration *configuration, const idps::NotifySender *sender) : Rule(configuration,
                                                                                                    sender) {
    this->patternSearch = configuration->getPattern();
    this->command = new Command(configuration->getNotify(), configuration);
}

void idps::Content::execute(Packet &packet) {
    auto data = packet.getData();
    auto src = packet.getSrc();
    for (const auto &ip : configuration->getListIps()) {
        if (ip == src) {
            auto test = patternSearch->search(data);
            if (test) {
//            command->run(1, packet.getSrc());
                Modul_3::write_bad_content(src);
                break;
            }
        }
    }

}

