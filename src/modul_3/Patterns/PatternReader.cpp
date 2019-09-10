//
// Created by uic15073 on 8/8/2019.
//

#include "PatternReader.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "../Exceptions/fatalError.h"
#include "BasicPattern.h"

using namespace idps;

BasicPattern *PatternReader::readFile(std::string location) {
    auto listOfPatterns = new std::vector<std::string>();
    std::ifstream infile(location);
    std::string pattern;
    std::string line;

    if (!infile)
        throw FatalError("Pattern file don't exists at:" + location);


    while (std::getline(infile, line))
        if (line.size() != 0 && line == "<-") {
            bool ok = true;
            while (ok) {
                getline(infile, line);
                if (line == "->")
                    ok = false;
                else if (line.empty())
                    pattern += "\n";
                else
                    pattern += line + "\n";
            }
            listOfPatterns->push_back(pattern.substr(0, pattern.size() - 1));

        }

    return new BasicPattern(listOfPatterns);

}
