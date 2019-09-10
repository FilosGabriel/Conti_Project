//
// Created by uic15073 on 8/27/2019.
//

#ifndef MODUL_4_H
#define MODUL_4_H


#include <string>
#include <vector>

using namespace std;

class Modul_4 {
private:
    static vector<string> ram_v;
    static vector<string> cpu_v;
    static vector<string> disk_v;

public:
    static vector<string> modify_ram(string ram);

    static vector<string> modify_cpu(string cpu);

    static vector<string> modify_hdd(string hdd);


    static void write_ram(std::string ram);

    static void write_cpu(std::string cpu);

    static void write_disk(std::string disk);

    static vector<string> read_ram();

    static vector<string> read_cpu();

    static vector<string> read_disk();


};


#endif //IDPS_MODUL_4_H
