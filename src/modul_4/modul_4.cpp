//
// Created by uic15073 on 8/23/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include <string>
#include <bits/unique_ptr.h>
#include <iostream>

#include "../Communication/Modul_4.h"

std::string getOutputCommand(const char *cmd) {
    std::array<char, 256> buffer{};
    std::string result;
    //const char * READ_MODE;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        result += buffer.data();

    return result;
}


int modul_4_app() {


    bool a = true;
    while (a) {

        //RAM
        std::string ram = getOutputCommand("free -m | grep Mem | awk '{print $2-$4}'");
        Modul_4::write_ram(ram.substr(0,ram.size()-1));

        //CPU
        std::string cpu = getOutputCommand("top -b -n1 | grep ^%Cpu | awk '{print  100-$8 }'");
        Modul_4::write_cpu(cpu.substr(0,cpu.size()-1));


        //disk I/O
        std::string disk = getOutputCommand("cat /sys/block/sda/stat | awk '{print $1, $5}'");
        Modul_4::write_disk(disk.substr(0,disk.size()-1));

        sleep(1);

    }
    return 0;

}
