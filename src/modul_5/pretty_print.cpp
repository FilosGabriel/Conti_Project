//
// Created by uic15073 on 9/3/2019.
//

#include "pretty_print.h"
#include "../Communication/Modul_4.h"
#include <iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <termios.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

int get_pos(int *y, int *x) {

    char buf[30] = {0};
    int ret, i, pow;
    char ch;

    *y = 0;
    *x = 0;

    struct termios term, restore;

    tcgetattr(0, &term);
    tcgetattr(0, &restore);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &term);

    write(1, "\033[6n", 4);

    for (i = 0, ch = 0; ch != 'R'; i++) {
        ret = read(0, &ch, 1);
        if (!ret) {
            tcsetattr(0, TCSANOW, &restore);
            fprintf(stderr, "getpos: error reading response!\n");
            return 1;
        }
        buf[i] = ch;
    }

    if (i < 2) {
        tcsetattr(0, TCSANOW, &restore);
        printf("i < 2\n");
        return (1);
    }

    for (i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
        *x = *x + (buf[i] - '0') * pow;

    for (i--, pow = 1; buf[i] != '['; i--, pow *= 10)
        *y = *y + (buf[i] - '0') * pow;

    tcsetattr(0, TCSANOW, &restore);
    return 0;
}

void red() {
    printf("\033[1;31m");
}

void yellow() {
    printf("\033[1;33m");
}

void magenta() {
    printf("\033[0;35m");
}

void cyan() {
    printf("\033[1;36m");
}

void reset() {
    printf("\033[0m");
}

void preaty_print(string &interface, vector<string> &bandwidth, vector<string> &packetRate,
                  vector<string> &badPackets, vector<string> &badFlags, vector<string> &badContent, vector<string> &ram,
                  vector<string> cpu, int bandwidth_t, int packetRate_t, int badPackets_t, int badFlags_t, int cpu_t,
                  int ram_t, int y,int max_ram) {
    clear();
    gotoxy(1, 0);
    reset();
    printf("Nic in use:                         %s  \n", interface.c_str());
    auto alt = interface == "ens32" ? "ens35" : "ens32";
    printf("Nic fallback:                       %s\n",alt);

//
//
    if (!bandwidth.empty()) {
        if (atoi(bandwidth.back().c_str()) > bandwidth_t)
            red();
        auto tmp="Nic used bandwidth:                 "+bandwidth.at(bandwidth.size() - 1)+"% of 1Gbps\n";
        printf("%s",tmp.c_str());
        reset();
    }

    if (packetRate.size() > 0) {
        if (atoi(packetRate.back().c_str()) > packetRate_t)
            cyan();
        cout << "Packet rate:                        " + packetRate.at(packetRate.size() - 1) << " packets/seconds"
             << "\n";
        reset();
    }


    if (badPackets.size() > 0) {
        if (atoi(badPackets.back().c_str()) > badPackets_t)
            cyan();
        cout << "Last bad packet:                    " + badPackets.at(badPackets.size() - 1) << "\n";
        reset();
    }


    if (ram.size() > 0) {
        if (atoi(ram.back().c_str()) > ram_t)
            magenta();
        cout << "Ram used:                           " + ram.at(ram.size() - 1) + " Megabyte of "+to_string(max_ram)+" Megabyte\n";
        reset();
    }

    if (cpu.size() > 0) {
        if (atoi(cpu.back().c_str()) > cpu_t)
            magenta();
        cout << "Cpu used:                           " + cpu.at(cpu.size() - 1) + "%\n";
        reset();
    }
    auto hdd = Modul_4::read_disk();
    if (hdd.size() > 0) {
        int split = hdd.back().find(' ');
        if (hdd.size() > 0)
            cout << "Disk:                               " + hdd.back().substr(0, split) + " read I/O " +
                    hdd.back().substr(split + 1) +
                    " write I/O" "\n";
    }
    int a = badFlags.size();
    if (a > badFlags_t)
        red();
    printf("Number of packets with bad flags:   %d packets\n", a);
    reset();
    a = badContent.size();
    if (a > 0)
        red();
    printf("Number of packets with bad content: %d packets\n", a);
    reset();


}