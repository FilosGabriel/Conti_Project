//
// Created by uic15073 on 8/8/2019.
//

#include "BasicPattern.h"


using namespace std;
# define NO_OF_CHARS 256
#define DEFAULT_VALUE (-1)

int BasicPattern::max(int a, int b) {
    return (a > b) ? a : b;
}

BasicPattern::BasicPattern(const std::vector<std::string> *listOfPatternsInput) : listOfPatterns(listOfPatternsInput) {
    auxData = new std::vector<std::vector<int> *>();
    for (const auto &item   :*listOfPatterns)
        auxData->push_back(badCharHeuristic(item));
}

vector<int> *BasicPattern::badCharHeuristic(std::string str) {
    auto badchar = new std::vector<int>(NO_OF_CHARS, DEFAULT_VALUE);
    for (size_t index = 0; index < str.size(); index++)
        badchar->at((int) str[index]) = index;
    return badchar;
}

bool BasicPattern::search(const std::string &text, const std::string &pattern, const std::vector<int> *badchar) {
    int patternSize = pattern.size();
    int textSize = text.size();
    int position = 0;
    while (position <= (textSize - patternSize)) {
        int j = patternSize - 1;

        while (j >= 0 && pattern.at(j) == text.at(position + j))
            j--;

        if (j < 0) {
//            printf("\n pattern occurs at shift = %d", position);
//            position += (position + patternSize < textSize) ? patternSize -
//                                                              badchar->at(text.at(position + patternSize)) : 1;
            return true;
        } else
            position += this->max(1, j - badchar->at(text.at(position + j)));
    }
    return false;
}


bool BasicPattern::search(std::string &text) {
    for (size_t noPattern = 0; noPattern < this->listOfPatterns->size(); noPattern++)
        if (search(text, this->listOfPatterns->at(noPattern), this->auxData->at(noPattern)))
            return true;
    return false;
}

const vector<std::string> *BasicPattern::getListOfPatterns() const {
    return listOfPatterns;
}


