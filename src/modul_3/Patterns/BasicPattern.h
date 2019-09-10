//
// Created by uic15073 on 8/8/2019.
//

#ifndef AAAA_BASICPATTERN_H
#define AAAA_BASICPATTERN_H


#include <string>
#include <vector>

# define NO_OF_CHARS 256

class BasicPattern {

public:
    explicit BasicPattern(const std::vector<std::string> *listOfText);

    bool search(std::string &text);

    const std::vector<std::string> *getListOfPatterns() const;

protected:
    const std::vector<std::string> *listOfPatterns;
    std::vector<std::vector<int>*> *auxData;

private:

    static std::vector<int>* badCharHeuristic(std::string str);

    bool search(const std::string &text, const std::string &pattern, const std::vector<int> *badchar);

    static int max(int a, int b);
};


#endif //AAAA_BASICPATTERN_H
