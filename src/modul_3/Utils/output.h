//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_OUTPUT_H
#define IDPS_NEW_OUTPUT_H

#include <string>

namespace idps {
    class Output {
    public:
        static std::string getOutputCommand(const char *cmd);
    };
}


#endif //IDPS_NEW_OUTPUT_H
