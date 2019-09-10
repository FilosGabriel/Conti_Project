//
// Created by uic15073 on 8/23/2019.
//
#include "Modul_2.h"

#include <mutex>

std::mutex mtx_2;
std::mutex mtx_3;
vector<string> Modul_2::packetRate;
vector<string> Modul_2::badPackets;
vector<int> Modul_2::actions;

void Modul_2::write_packetrate(string packet_rate) {
    if (!packet_rate.empty())
        modify_packetrate(packet_rate);
}

vector<string> Modul_2::read_packetrate() {
    return modify_packetrate("");
}

vector<string> Modul_2::modify_packetrate(string packet_rate) {
    mtx_2.lock();
    if (!packet_rate.empty())
        packetRate.push_back(packet_rate);
    if (packetRate.size() >= 120)
        packetRate = vector<string >(packetRate.begin() + 60, packetRate.end());
    vector<string> temp = packetRate;
    mtx_2.unlock();
    return temp;
}


vector<string> Modul_2::modifyPackets(string info_packets) {
    mtx_3.lock();
    if (!info_packets.empty())
        badPackets.push_back(info_packets);
    if (badPackets.size() >= 120)
        badPackets = vector<string>(badPackets.begin() + 60, badPackets.end());
    vector<string> temp = badPackets;
    mtx_3.unlock();
    return temp;
}

void Modul_2::write_packets(string packet) {
    if (!packet.empty())
        modifyPackets(packet);
}

vector<string> Modul_2::read_packets() {
    return modifyPackets("");
}

void Modul_2::execute_action(int action) {
    modify_action(action);

}

vector<int> Modul_2::read_action() {
    return modify_action(0);
}

vector<int> Modul_2::modify_action(int action) {
    mtx_3.lock();
    if (action)
        actions.push_back(action);
    vector<int> temp = actions;
    actions.clear();
    mtx_3.unlock();
    return temp;
}

static void write_badPacketrate(string bad_packetRate) {
    std::cout << bad_packetRate << "\n";
}
