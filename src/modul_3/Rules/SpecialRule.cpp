//
// Created by uic15073 on 8/20/2019.
//

#include <iostream>
#include "SpecialRule.h"

SpecialRule::SpecialRule(Configuration *configuration, const NotifySender *sender) : Rule(configuration, sender) {
    m_start = std::chrono::high_resolution_clock::now();
    maxPack = configuration->getMaxPack();
}

void SpecialRule::execute(Packet &packet) {
    m_stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::seconds>(m_stop - m_start).count();
    m_start = m_stop;
    double rate = maxPack / duration;
    if (rate > maxRate) {
        critic++;
        if (critic == maxDuration)
            critic = 0;
    } else
        critic = 0;


    printf("%f\n", duration);

}

