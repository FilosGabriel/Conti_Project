//
// Created by root on 8/5/19.
//

#include <testRule.h>
#include <christmasTree.h>
#include <content.h>
#include <memory>
#include <SpecialRule.h>
#include <OtherModule.h>
#include "idps.h"

using namespace idps;
#define DEFAULT_SIZE 512
#define READ_MODE "r"
#define TAB 9
#define SPACE 32

IDPS::IDPS(NotifySender *sender1, Configuration *configuration) : configuration(configuration), sender(sender1) {

    vectorOfRule.push_back(new Christmas(this->configuration, this->sender));
    vectorOfRule.push_back(new Content(this->configuration, this->sender));
    vectorOfRule.push_back(new OtherModule(this->configuration, this->sender));
//    vectorOfRule.push_back(new TestRule(this->configuration, this->sender));
}

void IDPS::run() {
    std::array<char, DEFAULT_SIZE> buffer{};
    std::string line;
    std::vector<std::string> packet;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(
            popen("sudo tcpdump -i ens32 tcp -n -A -vv -X  -s0 --immediate-mode 2>/dev/null", READ_MODE),
            pclose);
    int nrPackets = 0;
    const int maxPackets = configuration->getMaxPack();
    if (!pipe)
        throw std::runtime_error("popen() failed!");

//    SpecialRule special = SpecialRule(configuration,sender);


    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        line = buffer.data();
        if (line.at(0) == SPACE || line.at(0) == TAB)
            packet.push_back(line);
        else {
            if (!packet.empty()) {
                nrPackets++;
                if (nrPackets == maxPackets) {
                    nrPackets = 0;
                }
                Packet tempPacket = Packet(packet);

                for (const auto &rule:vectorOfRule)
                    rule->execute(tempPacket);
                packet.clear();
                packet.push_back(line);
            }
        }
    }
}

IDPS::~IDPS() {
    free(configuration);
    for (const auto item : vectorOfRule)
        free(item);

}
