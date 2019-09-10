//
// Created by uic15073 on 9/3/2019.
//

#ifndef IDPS_PRETTY_PRINT_H
#define IDPS_PRETTY_PRINT_H

#include <string>
#include <vector>

using namespace std;
int get_pos(int *y, int *x);
void preaty_print(string &interface, vector <string> &bandwidth, vector <string> &packetRate,
                  vector <string> &badPackets, vector <string> &badFlags, vector <string> &badContent,
                  vector <string> &ram,
                  vector <string> cpu, int bandwidth_t, int packetRate_t, int badPackets_t, int badFlags_t, int cpu_t,
                  int ram_t,int y,int max_ram);

#endif //IDPS_PRETTY_PRINT_H
