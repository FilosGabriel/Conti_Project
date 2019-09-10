//
// Created by uic15073 on 8/23/2019.
//

#ifndef IDPS_MODUL_3_H
#define IDPS_MODUL_3_H


#include <vector>
#include <string>

using namespace std;

class Modul_3 {
public:
    static vector <string> badFlags;
    static vector <string> badContent;
    static vector<int> actions3;

    static vector <string> modify_bad_content(string bad_content,bool clear);

    static vector<int> modify_action(int action);

    static vector<string> modify_bad_flags(string info_packets, bool clear);



    static void write_bad_content(string bad_content);

    static vector <string> read_bad_content();



    static vector <string> read_bad_flags();

    static void write_bad_flags(string packet);



    static void execute_action(int action);


    static vector<int> read_action();

    static void clear_bad_content();

    static void clear_bad_flags();
};

#endif //IDPS_MODUL_3_H
