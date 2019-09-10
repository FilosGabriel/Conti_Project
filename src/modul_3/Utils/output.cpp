//
// Created by root on 8/5/19.
//
#include <array>
#include "output.h"
#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <string>
#include <memory>

using namespace idps;
#define DEFAULT_SIZE 128
#define READ_MODE "r"

std::string Output::getOutputCommand(const char *cmd) {
    std::array<char, DEFAULT_SIZE> buffer{};
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, READ_MODE), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        result += buffer.data();

    return result;
}
