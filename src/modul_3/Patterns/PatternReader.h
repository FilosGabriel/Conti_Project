//
// Created by uic15073 on 8/8/2019.
//

#ifndef AAAA_PATTERNREADER_H
#define AAAA_PATTERNREADER_H

#include <string>
#include <vector>
#include "BasicPattern.h"

namespace idps {

    class PatternReader {
    public:
        static  BasicPattern *readFile(std::string location);
    };

}

#endif //AAAA_PATTERNREADER_H
