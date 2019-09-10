//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_INVALIDPARAMETEREXCEPTION_H
#define IDPS_NEW_INVALIDPARAMETEREXCEPTION_H


#include <string>

namespace idps {
    class InvalidParameterException : public std::exception {
    public:
        explicit InvalidParameterException(const std::string &error) : error(error) {}

        [[nodiscard]] const char *what() const noexcept override;

    private:

        std::string error;
    };
}


#endif //IDPS_NEW_INVALIDPARAMETEREXCEPTION_H
