//
// Created by uic15073 on 8/23/2019.
//


#ifndef IDPS_MODUL_2_H
#define IDPS_MODUL_2_H


#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Modul_2 {
public:
    static vector<string> packetRate;
    static vector<string> badPackets;
    static vector<int> actions;
    //functions for packet rate

    static vector<string> modify_packetrate(string packet_rate);

    static void write_packetrate(string packet_rate);

    static vector<string> read_packetrate();
    //functions for bad packets


    static vector<string> modifyPackets(string info_packets);

    static vector<string> read_packets();

    static void write_packets(string packet);
    //functions for actions


    static void execute_action(int action);

    static vector<int> read_action();


    static vector<int> modify_action(int action);


    static void write_badPacketrate(string bad_packetRate);




};

#endif //IDPS_MODUL_2_APP_H


