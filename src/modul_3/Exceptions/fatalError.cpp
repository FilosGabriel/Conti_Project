//
// Created by root on 8/5/19.
//

#include "fatalError.h"

using namespace idps;

const char *FatalError::what() const noexcept {
    return error.c_str();
}
