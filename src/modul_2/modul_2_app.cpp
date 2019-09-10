#include <map>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<chrono>
#include<cstring>
#include <string>
#include <fstream>
#include <iostream>
#include<algorithm>
#include <sstream>
#include <vector>
#include <bits/unique_ptr.h>
#include <chrono>
#include <thread>

#include "../Communication/Modul_2.h"
#include "../Communication/Modul_1.h"
#include "modul_2_app.h"
#include "../Communication/Modul_3.h"

using namespace std;
#define IP_SRC 1

map<string, string> readDataFromFileConfig1() {
    std::ifstream fileConfig("/etc/conti_app_conf/m_2.conf");
    map<string, string> conf;
    string line;

    if (!fileConfig)
        printf("EROARE LA DESCHIDERE FISIER DE CONFIGURARE");
    while (std::getline(fileConfig, line)) {
        int position = line.find_first_of('=');
        string key = line.substr(0, position);
        string value = line.substr(position + 1);
        conf[key] = value;
    }
    fileConfig.close();
    return conf;
}


vector<string> readDataFromFileConfig2(map<string, string> conf, string key) {
    vector<string> vector_info;
    string listItems = conf[key];
    while (!listItems.empty()) {
        int virgula = listItems.find_first_of(',');

        string first = listItems.substr(0, virgula);
        listItems = listItems.substr(virgula + 1);
        vector_info.push_back(first);
    }
    return vector_info;
}

int modul_2_app() {
    unsigned long int last = 0;
    unsigned long int packetsRate = 0;
    //date necesare citite din fisierul de configurare
    map<string, string> conf = readDataFromFileConfig1();
    vector<string> ip_src = readDataFromFileConfig2(conf, "ip_src");
    vector<string> ip_dst = readDataFromFileConfig2(conf, "ip_dst");
    vector<string> protocol = readDataFromFileConfig2(conf, "protocol");
    vector<string> port_dst = readDataFromFileConfig2(conf, "port_dst");
    std::string interface = "ens32";

    string command = "sudo /sbin/tshark -l -q -i " + interface +
                     " -T fields -e col.Source -e col.Destination -e col.Protocol -e col.SourcePort -e col.DestinationPort  2>/dev/null ";
    int trsh = atoi(conf["tshold"].c_str()), nr = 0;


    std::ofstream prate;
    prate.open("/tmp/conti_proj/module_2/packetrate.txt", std::ofstream::out);
    std::ofstream notif;
    notif.open("/tmp/conti_proj/module_2/m2_post_infos.txt");
    std::ofstream testFile;
    testFile.open("/tmp/conti_proj/module_2/infos.txt", std::ofstream::out);


    std::array<char, 128> buffer{};
    std::string line;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(
            popen(command.c_str(),
                  "r"),
            pclose);

    if (!pipe)
        throw std::runtime_error("popen() failed!");
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        nr++;
        line = buffer.data();
        testFile << line;
        testFile.flush();
        std::istringstream iss(line);
        std::vector<std::string> results;
        std::string word;
        while (iss >> word) {
            results.push_back(word);
        }
        std::string notificare;


        int i = 0;
        auto it = find(ip_src.begin(), ip_src.end(), results[i]);
        if (it == ip_src.end())//nu a fost gasit
            notificare += std::to_string(nr) + "->" + results[i];
        else {
            i++;
            auto it = find(ip_dst.begin(), ip_dst.end(), results[i]);
            if (it == ip_dst.end())
                notificare += std::to_string(nr) + "->" + results[i];
            else {
                i++;
                auto it = find(protocol.begin(), protocol.end(), results[i]);
                if (it == protocol.end())
                    notificare += std::to_string(nr) + "->" + results[i];
                else {
                    if (results.size() == 5) {
                        i++;
                        int port_src = stoi(results[i]);
                        if (port_src <= 1024 && port_src != 21 && port_src != 20)
                            //tmp += "Port sursa necunoscut\n";
                            notificare += std::to_string(nr) + "->" + results[i];
                        else {
                            i++;
                            auto it = find(port_dst.begin(), port_dst.end(), results[i]);
                            if (it == port_dst.end())
                                //tmp += "Port destinatie necunoscut\n";
                                notificare += std::to_string(nr) + "->" + results[i];
                        }
                    }
                }
            }
        }

        end = std::chrono::system_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

        if (duration >= 1) {
            start = end;
            prate << packetsRate << endl;
            Modul_2::write_packetrate(std::to_string(nr - last));
            last = nr;

            if (packetsRate > trsh) {
                Modul_3::execute_action(0);
            }

            auto band = Modul_1::readBandwidth();

            std::cout << "\nModule 2 read info from module 1\n";

            packetsRate = 0;
        }
        if (!notificare.empty()) {
            notif << notificare << std::endl;
            Modul_2::write_packets(notificare);
            notif.flush();
        }


    }

    notif.close();
    testFile.close();
    return 0;
}

