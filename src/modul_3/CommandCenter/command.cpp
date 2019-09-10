//
// Created by root on 8/5/19.
//

#include <command.h>
#include <testActions.h>
#include <BadContent.h>
#include <BadIp.h>
#include <configuration.h>
#include <iostream>
#include <BadFlag.h>

using namespace idps;

Command::Command(const Notify *notify, Configuration *configuration) {
    this->notify = notify;
    vectorOfActions.push_back(new TestActions(this->notify));
    vectorOfActions.push_back(new BadContent(this->notify));
    vectorOfActions.push_back(new BadFlag(this->notify));
    sizeOfActions = vectorOfActions.size();
}

void Command::run(int code, std::string details) {
    if (code >= 0 && code < sizeOfActions)
        vectorOfActions.at(code)->launch(details);
    else
        this->notify->send("Unknown code: " + std::to_string(code));
}

Command::~Command() {
    for (auto item : vectorOfActions)
        free(item);
}
