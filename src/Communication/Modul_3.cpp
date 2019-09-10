//

// Created by uic15073 on 8/23/2019.
//

#include "Modul_3.h"
//
// Created by uic15073 on 8/23/2019.
//



#include <mutex>

std::mutex mtx_3_1;
std::mutex mtx_3_2;
std::mutex mtx_3_3;

vector<string> Modul_3::badFlags;
vector<string> Modul_3::badContent;
vector<int> Modul_3::actions3;

void Modul_3::write_bad_content(string bad_content) {
    if (!bad_content.empty())
        modify_bad_content(bad_content, false);
}

vector<string> Modul_3::read_bad_content() {
    return modify_bad_content("", false);
}

vector<string> Modul_3::modify_bad_content(string bad_content, bool clear) {
    mtx_3_1.lock();
    if (clear) {
        badContent.clear();
    } else {
        if (!bad_content.empty())
            badContent.push_back(bad_content);
        if (badContent.size() > 2000)
            badContent = vector<string>(badContent.begin() + 1000, badContent.end());

    }
    vector<string> temp = badContent;
    mtx_3_1.unlock();
    return temp;
}

void Modul_3::clear_bad_content() {
    modify_bad_content("", true);
}

void Modul_3::clear_bad_flags() {
    modify_bad_flags("", true);
}

vector<string> Modul_3::modify_bad_flags(string info_packets, bool clear) {
    mtx_3_2.lock();
    if (clear) {
        badFlags.clear();
    } else {
        if (!info_packets.empty())
            badFlags.push_back(info_packets);
        if (badFlags.size() >= 2000)
            badFlags = vector<string>(badFlags.begin() + 1000, badFlags.end());
    }
    vector<string> temp = badFlags;
    mtx_3_2.unlock();
    return temp;
}

void Modul_3::write_bad_flags(string packet) {
    if (!packet.empty())
        modify_bad_flags(packet, false);
}

vector<string> Modul_3::read_bad_flags() {
    return modify_bad_flags("", false);
}

void Modul_3::execute_action(int action) {
    modify_action(action);

}

vector<int> Modul_3::read_action() {
    return modify_action(0);
}

vector<int> Modul_3::modify_action(int action) {
    mtx_3_3.lock();
    if (action)
        actions3.push_back(action);
    vector<int> temp = actions3;
    actions3.clear();
    mtx_3_3.unlock();
    return temp;
}

