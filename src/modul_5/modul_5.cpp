
//
// Created by uic15073 on 8/23/2019.
//

#include "modul_5.h"
#include "../Communication/Modul_1.h"
#include "../Communication/Modul_2.h"
#include "../Communication/Modul_3.h"
#include "../Communication/Modul_4.h"
#include <map>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<chrono>
#include<cstring>
#include <string>
#include <fstream>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include<algorithm>
#include <sstream>
#include <vector>
#include <bits/unique_ptr.h>
#include <chrono>
#include <thread>
#include <vector>
#include <output.h>
#include "pretty_print.h"

#define  EXIST_DATA_1 !bandwidth.empty() && !packetRate.empty() && !cpu.empty()
#define EXIST_DATA_2 !ram.empty() && !packetRate.empty() && !badPackets.empty()
using namespace std;


map<string, string> readDataFromFileConfig11() {
    std::ifstream fileConfig("/etc/conti_app_conf/m_5.conf");
    map<string, string> conf;
    string line;
    if (!fileConfig)
        perror("EROARE LA DESCHIDERE FISIER DE CONFIGURARE");
    while (std::getline(fileConfig, line)) {
        int position = line.find_first_of('=');
        string key = line.substr(0, position);
        string value = line.substr(position + 1);
        conf[key] = value;
    }
    fileConfig.close();
    return conf;
}


void modul_5_app(bool terminal) {
    bool run = true;
    map<string, string> conf = readDataFromFileConfig11();
    int bandwidth_t = atoi(conf["bandwidth_t"].c_str());
    int packetRate_t = atoi(conf["packetRate_t"].c_str());
    int badPackets_t = atoi(conf["badPackets_t"].c_str());
    int badFlags_t = atoi(conf["badFlags_t"].c_str());
    int cpu_t = atoi(conf["cpu_t"].c_str());
    int ram_t = atoi(conf["ram_t"].c_str());
    int x = 0, y = 0;

    printf("\n");
    if (terminal)
        get_pos(&y, &x);
    int max_ram =atoi(idps::Output::getOutputCommand("free -m | grep Mem | awk '{print $2}' ").c_str());
    while (run) {

        string interface = Modul_1::getInterface();
        vector<string> bandwidth = Modul_1::readBandwidth();
        vector<string> packetRate = Modul_2::read_packetrate();
        vector<string> badPackets = Modul_2::read_packets();
        vector<string> badFlags = Modul_3::read_bad_flags();
        vector<string> badContent = Modul_3::read_bad_content();
        vector<string> ram = Modul_4::read_ram();
        vector<string> cpu = Modul_4::read_cpu();
        preaty_print(interface, bandwidth, packetRate, badPackets, badFlags, badContent, ram, cpu, bandwidth_t,
                     packetRate_t, badPackets_t, badFlags_t, cpu_t, ram_t, y,max_ram);

//        if (EXIST_DATA_1 && atoi(bandwidth.back().c_str()) > bandwidth_t and
//            atoi(packetRate.back().c_str()) > packetRate_t and atoi(cpu.back().c_str()) > cpu_t)
//            Modul_1::execute_action(1); //inchide interfata
//        else if (EXIST_DATA_2 && atoi(ram.back().c_str()) > ram_t and atoi(packetRate.back().c_str()) > packetRate_t and
//                 atoi(badPackets.back().c_str()) > badPackets_t) {
//            Modul_3::execute_action(2); //blocheze IP
//            auto interface = Modul_1::getInterface();
//            if (interface == "ens32")
//                Modul_1::setInterface("ens35");
//            else
//                Modul_1::setInterface("ens32");
//        } else if (badFlags.size() > badFlags_t)
//            Modul_1::execute_action(1); //inchide interfata
//
        sleep(1);
    }

}


