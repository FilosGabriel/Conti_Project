//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_FATALERROR_H
#define IDPS_NEW_FATALERROR_H

#include <exception>
#include <string>

namespace idps {
    class FatalError : public std::exception {
    public:
        explicit FatalError(const std::string &error) : error(error) {}

        [[nodiscard]] const char *what() const noexcept override;

    private:

        std::string error;


    };
}


#endif //IDPS_NEW_FATALERROR_H
