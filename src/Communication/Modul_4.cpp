//
// Created by uic15073 on 8/27/2019.
//

#include <mutex>
#include "Modul_4.h"

std::mutex mtx_4_1;
std::mutex mtx_4_2;
std::mutex mtx_4_3;
vector<string> Modul_4::ram_v;
vector<string> Modul_4::cpu_v;
vector<string> Modul_4::disk_v;

void Modul_4::write_ram(std::string ram) {
    modify_ram(ram);

}

void Modul_4::write_cpu(std::string cpu) {
    modify_cpu(cpu);
}

void Modul_4::write_disk(std::string disk) {
    modify_hdd(disk);
}


vector<string> Modul_4::modify_ram(string ram) {
    mtx_4_1.lock();
    if (!ram.empty())
        ram_v.push_back(ram);
    if (ram_v.size() >= 200)
        ram_v = vector<string>(ram_v.begin() + 100, ram_v.end());
    vector<string> temp = ram_v;

    mtx_4_1.unlock();
    return temp;
}

vector<string> Modul_4::modify_cpu(string cpu) {
    mtx_4_2.lock();
    if (!cpu.empty())
        cpu_v.push_back(cpu);
    if (cpu_v.size() >= 200)
        cpu_v = vector<string>(cpu_v.begin() + 100, cpu_v.end());
    vector<string> temp = cpu_v;

    mtx_4_2.unlock();
    return temp;
}

vector<string> Modul_4::modify_hdd(string hdd) {
    mtx_4_3.lock();
    if (!hdd.empty())
        disk_v.push_back(hdd);
    if (disk_v.size() >= 200)
        disk_v = vector<string>(disk_v.begin() + 100, disk_v.end());
    vector<string> temp = disk_v;

    mtx_4_3.unlock();
    return temp;
}

vector<string> Modul_4::read_ram() {
    return modify_ram("");
}

vector<string> Modul_4::read_cpu() {
    return modify_cpu("");
}

vector<string> Modul_4::read_disk() {
    return modify_hdd("");
}
