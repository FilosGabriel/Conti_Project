//
// Created by uic15073 on 8/23/2019.
//

#ifndef IDPS_MODUL_1_H
#define IDPS_MODUL_1_H

#include <string>
#include <vector>

using namespace std;

class Modul_1 {
private:
    static string interface_selected;
    static vector<string> bandwidth;
    static bool link_1;
    static bool link_2;


    static vector<int> actions1;
public:
    static string getInterface();

    static void setInterface(string interface);

    static vector<string> readBandwidth();

    static void write_bandwidth(string bandwidth);

    static void execute_action(int action);


    static vector<int> read_action();


    static string modify_interface(string interface);

    static vector<int> modify_actions(int action);

    static vector<string> modify_band(string band);

};


#endif //IDPS_MODUL_1_APP_H
