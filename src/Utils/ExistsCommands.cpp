//
// Created by uic15073 on 9/2/2019.
//

#include <output.h>
#include <iostream>
#include <sys/stat.h>
#include "ExistsCommands.h"

#define DONT_EXISTS 0

bool existFile(std::string file) {
    struct stat buffer{};
    return (stat(file.c_str(), &buffer) == DONT_EXISTS);
}

bool existCommands() {
    std::string dep;
    bool run = true;
    if (!existFile("/usr/sbin/tcpdump") && !existFile("/usr/bin/tcpdump")) {
        dep += " tcpdump";
        run = false;
    }

    if (!existFile("/usr/sbin/tshark")&&!existFile("/usr/bin/tshark")) {
        dep += " wireshark";
        run = false;
    }

    if (!existFile("/usr/bin/bwm-ng")&&!existFile("/usr/sbin/bwm-ng")) {
        dep += " bwm-ng";
        run = false;
    }
    if (!run)
        printf("Plese install : %s\n", dep.c_str());
    return run;
}