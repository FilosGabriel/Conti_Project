//
// Created by uic15073 on 8/23/2019.
//

#include <mutex>
#include "Modul_1.h"

std::mutex mtx_1_1;
std::mutex mtx_1_2;
std::mutex mtx_1_3;
vector<string> Modul_1::bandwidth;
string Modul_1::interface_selected = "ens32";
vector<int> Modul_1::actions1;

bool  Modul_1::link_1;
bool  Modul_1::link_2;

string Modul_1::getInterface() {
    return modify_interface("");
}

void Modul_1::setInterface(string interface) {
    modify_interface(interface);
}

vector<string> Modul_1::readBandwidth() {
    return modify_band("");
}

void Modul_1::write_bandwidth(string bandwidth) {
    modify_band(bandwidth);
}

void Modul_1::execute_action(int action) {
    modify_actions(action);
}

vector<int> Modul_1::read_action() {
    return modify_actions(0);
}

string Modul_1::modify_interface(string interface) {
    mtx_1_1.lock();
    if (!interface.empty())
        interface_selected = interface;
    string tmp = interface_selected;
    mtx_1_1.unlock();
    return tmp;
}

vector<int> Modul_1::modify_actions(int action) {
    mtx_1_2.lock();
    if (action)
        actions1.push_back(action);
    vector<int> temp = actions1;
    actions1.clear();
    mtx_1_2.unlock();
    return temp;
}

vector<string> Modul_1::modify_band(string band) {
    mtx_1_3.lock();
    if (!band.empty())
        bandwidth.push_back(band);
    if (bandwidth.size() >= 120) {
        bandwidth = vector<string>(bandwidth.begin() + 60, bandwidth.end());
    }
    vector<string> tmp = bandwidth;
    mtx_1_3.unlock();
    return tmp;
}






