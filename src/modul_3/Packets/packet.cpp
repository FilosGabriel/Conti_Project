#include <utility>

#include <utility>

//
// Created by root on 8/5/19.
//

#include <iostream>
#include "packet.h"

#define TAB 9

Packet::Packet(std::vector<std::string> packetI) : packet(packetI) {}


std::string Packet::getSrc() {
    std::string tmp= packet.at(1).substr(4, packet.at(1).find_first_of(' ', 13) - 4);

    return  tmp.substr(0,tmp.find_last_of("."));
}

std::string Packet::getData() {
    auto temp = std::string();
    auto it = this->packet.begin();
    it += 2;
    if ('0' != it->at(1))
        while (it->at(1) != '0' && it != packet.end()) {
            temp += it->substr(0, it->size() - 1);
            it++;
        }
    else
        for (; it != packet.end(); it++)
            temp += it->substr(51, it->size() - 52);
    return temp;
}

std::string Packet::getFlags() {
    unsigned begin = packet.at(1).find("Flags [") + 7;
    unsigned end = packet.at(1).find("], ");
    return packet.at(1).substr(begin, end - begin);
}

std::vector<std::string> Packet::get() {
    return packet;
}

