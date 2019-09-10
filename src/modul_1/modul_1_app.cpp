#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include  <csignal>
#include  <cstdlib>
#include  <unistd.h>

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include "modul_1_app.h"
#include "../Communication/Modul_1.h"
#include <mutex>
#include <ctime>
#include <command.h>
#include <output.h>

void execute(int a, std::string net_name_current, std::string net_name_new) {
    switch (a) {
        case 1: {
            std::string command = " /sbin/ifdown " + net_name_current;
            system(command.c_str());
            break;
        }
        case 2: {
            std::string command = "/sbin/ifup " + net_name_new + " && /sbin/ifdown " + net_name_current;
            system(command.c_str());
            break;
        }
        default:
            break;
    }
}

std::string getBand(std::string inter) {
//    std::string tmp = "cat /proc/net/dev | grep " + inter + " | awk '{print ($2+$10)/1000000000*100}'";
    std::string tmp = "bwm-ng --output plain --count 1| grep " + inter + " |  awk '{printf(\"%.5f\"), ($6/125000)*100}'";
    return idps::Output::getOutputCommand(tmp.c_str());

}

std::string changeInterface(std::string inter) {

    std::string nic_file;
    if (inter == "ens32")
        nic_file = "/tmp/conti_proj/bm_ens32.txt";
    else
        nic_file = "/tmp/conti_proj/bm_ens35.txt";

    std::string value = getBand(inter);
    std::string comm =
            "bwm-ng --output plain --count 1| grep " + inter + " |  awk '{print $2, $4, ($6/125000)*100}' >> " +
            nic_file + ";" +
            " bwm-ng --output plain --count 1| grep " + inter +
            " | awk '"
            "{print $2, $4, ($6/125000)*100}' | awk '{if ($3 < 10) print \"low\"; else if($3<90) print \"med\"; else print \"high\";}' >> " +
            nic_file;

    system(comm.c_str());
    return value;
}


std::string exec(const char *cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int modul_1_app() {


    using namespace std::this_thread; // sleep_for, sleep_until

    std::vector<std::string> m_1_vector;
    std::string str;

    std::ifstream conf("/etc/conti_app_conf/m_1.conf", std::ios::in);

    while (conf >> str)
        m_1_vector.push_back(str);

    conf.close();


    std::string m_1_path = m_1_vector[22];
    std::string nic_2_file = m_1_vector[18];
    std::string nic_1_file = m_1_vector[14];
    int nic_interfaces = stoi(m_1_vector[10]);
    std::string nic_2 = m_1_vector[6];
    std::string nic_1 = m_1_vector[2];

    int low = stoi(m_1_vector[26]);
    int med = stoi(m_1_vector[30]);
    int high = stoi(m_1_vector[34]);


//    std::cout << m_1_path << std::endl;
//    std::cout << nic_1_file << std::endl;
//    std::cout << nic_2_file << std::endl;
//    std::cout << nic_interfaces << std::endl;
//    std::cout << nic_1 << std::endl;
//    std::cout << nic_2 << std::endl;
//    std::cout << low << std::endl;
//    std::cout << med << std::endl;
//    std::cout << high << std::endl;
    std::string command_t = "ifdown " + nic_1 + " & ifdown " + nic_2;

    std::string net_name;
    net_name = "ens32";
    if (net_name == nic_1)//
    {
        std::string commandupdown1 = "/sbin/ifup " + nic_1 + " && /sbin/ifdown " + nic_2;
        system(commandupdown1.c_str());
    } else if (net_name == nic_2) {
        std::string commandupdown2 = "/sbin/ifup " + nic_2 + " && /sbin/ifdown " + nic_1;
        system(commandupdown2.c_str());
    }

    std::ofstream ens1, ens2;
    std::string adr_ens1, adr_ens2;
    adr_ens1 = m_1_path + nic_1_file;
    adr_ens2 = m_1_path + nic_2_file;
    ens1.open(adr_ens1);
    ens2.open(adr_ens2);

    std::string commandLeft32 =
            "cat /proc/net/dev | grep " + nic_1 + " | awk '{print $2, $10, 8*($2+$10)/1000000000*100}' >> " + m_1_path +
            nic_1_file;
    std::string commandLeft34 =
            "cat /proc/net/dev | grep " + nic_2 + " | awk '{print $2, $10, 8*($2+$10)/1000000000*100}' >> " + m_1_path +
            nic_2_file;

    std::string commandLeftDate32 = "date +'Date start: %A %d-%b-%y %T' >> " + m_1_path + nic_1_file;
    std::string commandLeftDate34 = "date +'Date start: %A %d-%b-%y %T' >> " + m_1_path + nic_2_file;


    std::string interfata = net_name;

    system(commandLeftDate32.c_str());
    system(commandLeftDate34.c_str());

    std::string commandHead32 = "echo '\nRX\tTX\t%\n' >>" + m_1_path + nic_1_file;
    std::string commandHead34 = "echo '\nRX\tTX\t%\n' >>" + m_1_path + nic_2_file;

    system(commandHead32.c_str());
    system(commandHead34.c_str());

    bool b = true;
    std::string oldInterface;

    while (b) {
        auto tmp = changeInterface(interfata);

        Modul_1::write_bandwidth(tmp.substr(0, tmp.size() - 1));
        oldInterface = interfata;
        interfata = Modul_1::getInterface();
        if (interfata != oldInterface) {
            if (interfata.compare("ens32") == 0) {

                system(commandLeftDate32.c_str());
                std::string temp_1 =
                        "bwm-ng --output plain --count 1| grep " + interfata + " |  awk '{printf(\"%.3f\"), ($6/125000)*100}'";
                std::string value_1 = idps::Output::getOutputCommand(temp_1.c_str());
                int value_int_1 = stoi(value_1);
                if (value_int_1 >= high) {
                    changeInterface(interfata);
                    std::string temp_2 =
                            "bwm-ng --output plain --count 1| grep " + interfata + " |  awk '{printf(\"%.3f\"), ($6/125000)*100}'";
                    std::string value_2 = idps::Output::getOutputCommand(temp_2.c_str());
                    int value_int_2 = stoi(value_2);
                    if (value_int_2 >= high) {
                        std::string command = "/sbin/ifdown " + interfata + " && /sbin/ifdown " + oldInterface;
                        system(command.c_str());
                    }
                }


            } else {

                system(commandLeftDate34.c_str());
                std::string temp_1 =
                        "bwm-ng --output plain --count 1| grep " + interfata + " |  awk '{printf(\"%.3f\"), ($6/125000)*100}'";
                std::string value_1 = idps::Output::getOutputCommand(temp_1.c_str());
                int value_int_1 = stoi(value_1);
                if (value_int_1 >= high) {
                    changeInterface(interfata);
                    std::string temp_2 =
                            "bwm-ng --output plain --count 1| grep " + interfata + " |  awk  '{printf(\"%.3f\"), ($6/125000)*100}'";
                    std::string value_2 = idps::Output::getOutputCommand(temp_2.c_str());
                    int value_int_2 = stoi(value_2);
                    if (value_int_2 >= high) {
                        std::string command = "/sbin/ifdown " + interfata + " && /sbin/ifdown " + oldInterface;
                        system(command.c_str());
                    }
                }

            }
        }
        auto actions = Modul_1::read_action();
        for (auto const &action:actions)
            system(command_t.c_str());
        sleep(1);
    }


    ens1.close();
    ens2.close();

    return 0;
}