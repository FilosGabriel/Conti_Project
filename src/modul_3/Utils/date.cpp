//
// Created by root on 8/5/19.
//

#include <chrono>
#include "date.h"

using namespace std::chrono;
using namespace std;

const char *idps::Date::getTimeNow() {
    auto timeS = system_clock::to_time_t(system_clock::now());
    return string(ctime(&timeS)).substr(0, string(ctime(&timeS)).size() - 1).c_str();
}
