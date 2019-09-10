//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_PACKET_H
#define IDPS_NEW_PACKET_H


#include <vector>
#include <string>
#include <array>
#include <unordered_map>

class Packet {
public:
    explicit Packet(std::vector<std::string> packet);

    std::string getFlags();

    std::vector<std::string> get();


    std::string getSrc();

    std::string getData();

private:

    std::vector<std::string> packet;


};


#endif //IDPS_NEW_PACKET_H
