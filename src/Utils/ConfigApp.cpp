//
// Created by uic15073 on 9/2/2019.
//

#include <string>
#include <sys/stat.h>

#include "ConfigApp.h"

#define DONT_EXISTS 0

bool existFile(const std::string &locationFile) {
    struct stat buffer{};
    return (stat(locationFile.c_str(), &buffer) == DONT_EXISTS);
}

bool existDirectory(const std::string &location) {
    struct stat buffer{};
    return (stat(location.c_str(), &buffer) == DONT_EXISTS);

}

void m_1() {
    if (!existDirectory("/tmp/conti_proj/module_1"))
        system("mkdir /tmp/conti_proj/module_1");


    if (!existFile("/tmp/conti_proj/module_1/bm_ens32.txt"))
        system("touch /tmp/conti_proj/module_1/bm_ens32.txt");

    if (!existFile("/tmp/conti_proj/module_1/bm_ens35.txt"))
        system("touch /tmp/conti_proj/module_1/bm_ens35.txt");

    if (!existFile("/etc/conti_app_conf/m_1.conf"))
        system("printf \"nic_1 = ens32 ;\n"
               "nic_2 = ens35 ;\n"
               "nic_interfaces = 2 ;\n"
               "nic_1_file = bm_ens32.txt ;\n"
               "nic_2_file = bm_ens35.txt ;\n"
               "m_1_path = /tmp/conti_proj/module_1 ;\n"
               "low = 10 ;\n"
               "med = 90 ;\n"
               "high = 100 ;\" >> /etc/conti_app_conf/m_1.conf");

}

void m_2() {
    if (!existDirectory("/tmp/conti_proj/module_2"))
        system("mkdir /tmp/conti_proj/module_2");

    if (!existFile("/etc/conti_app_conf/m_2.conf"))
        system("printf \"ip_src=192.168.137.130,192.168.137.132,\n"
               "ip_dst=192.168.137.130,192.168.137.132,\n"
               "protocol=TCP,ICMP,\n"
               "port_dst=80,20,21,\n"
               "tshold=20\n"
               "~\n"
               "~\n"
               "~\" >> /etc/conti_app_conf/m_2.conf");

}


void m_3() {
    if (!existDirectory("/etc/conti_app_conf/m_3"))
        system("mkdir /etc/conti_app_conf/m_3");

    if (!existDirectory("/tmp/conti_proj/module_3"))
        system("mkdir /tmp/conti_proj/module_3");

    if (!existFile("/etc/conti_app_conf/m_3/m_3.conf"))
        system("printf \"log_file_location=/var/idps.log\n"
               "flags=SSS P.\n"
               "ip=192.168.189.140\n"
               "whitelist_file=./whitelist\n"
               "blacklist_file=/etc/idps/blacklist\n"
               "port=9997\">> /etc/conti_app_conf/m_3/m_3.conf");


    if (!existFile("/etc/conti_app_conf/m_3/m_3.conf"))
        system("printf \"192.168.189.140\n"
               "192.168.189.1\" >> /etc/conti_app_conf/m_3/ip_blocked");


    if (!existFile("/etc/conti_app_conf/m_3/blacklist"))
        system("printf \"<-\n"
               "..........\n"
               "->\n"
               "\n"
               "<-\n"
               "21231\n"
               "dasd\n"
               "\n"
               "asdasd\n"
               "\n"
               "sada\n"
               "->\" >> /etc/conti_app_conf/m_3/blacklist");
}

void m_4() {
    if (!existDirectory("/tmp/conti_proj/module_4"))
        system("mkdir /tmp/conti_proj/module_4");

}


void m_5() {
    if (!existFile("/etc/conti_app_conf/m_5.conf"))
        system("printf \"bandwidth_t=90\n"
               "packetRate_t=80\n"
               "badPackets_t=1\n"
               "badFlags_t=10\n"
               "cpu_t=90\n"
               "ram_t=1700\" >> /etc/conti_app_conf/m_5.conf");


    if (!existDirectory("/tmp/conti_proj/module_5"))
        system("mkdir /tmp/conti_proj/module_5");

}

void fileConf() {
    if (!existDirectory("/etc/conti_app_conf"))
        system("mkdir /etc/conti_app_conf");

    if (!existDirectory("/tmp/conti_proj"))
        system("mkdir /tmp/conti_proj");

    m_1();
    m_2();
    m_3();
    m_4();
    m_5();

}
