//
// Created by root on 8/5/19.
//

#include "invalidParameterException.h"

using namespace idps;

const char *InvalidParameterException::what() const noexcept {

    return error.c_str();

}
