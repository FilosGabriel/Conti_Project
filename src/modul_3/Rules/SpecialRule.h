//
// Created by uic15073 on 8/20/2019.
//

#ifndef IDPS_SPECIALRULE_H
#define IDPS_SPECIALRULE_H


#include <chrono>
#include "Rule.h"

using namespace idps;

class SpecialRule : public idps::Rule {
private:
    typedef std::chrono::time_point<std::chrono::high_resolution_clock> HighResClock;
    double duration;
    HighResClock m_start;
    HighResClock m_stop;
    int maxPack;
    int maxRate;
    int maxDuration;
    int critic = 0;
public:
    SpecialRule(Configuration *configuration, const NotifySender *sender);

    void execute(Packet &packet) override;

};


#endif //IDPS_SPECIALRULE_H
