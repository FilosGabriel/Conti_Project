

#include <iostream>
#include <thread>
#include <cstring>
#include "src/modul_1/modul_1_app.h"
#include "src/modul_2/modul_2_app.h"
#include "src/modul_5/modul_5.h"
#include "src/modul_4/modul_4.h"
#include "src/modul_3/modul_3_app.h"
#include "src/Utils/ConfigApp.h"
#include "src/Utils/ExistsCommands.h"

using namespace std;


int main(int argc, char **argv) {
    fileConf();
    if (existCommands()) {


        std::thread thread1([]() {
            modul_1_app();
        });

        std::thread thread2([]() {
            modul_2_app();
        });


        std::thread thread3([=]() {
            modul_3_app(argc, argv);
        });
        std::thread thread4([]() {
            modul_4_app();
        });

        std::thread thread5([=]() {
            bool terminal = false;
            if (argc == 2 && strcmp(argv[1], "-t") == 0)
                terminal = true;
            modul_5_app(terminal);
        });


        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();

        thread5.join();
    }

    return 0;

}
