//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_COMMAND_H
#define IDPS_NEW_COMMAND_H


#include <Actions.h>
#include <vector>
#include <configuration.h>

namespace idps {

    class Command {
    private:
        int sizeOfActions{};
        std::vector<Action *> vectorOfActions{};

    public:
        void run(int code, std::string details);

        explicit Command(const Notify *notify, Configuration *configuration);

        virtual ~Command();

        const Notify *notify;
    };
}


#endif //IDPS_NEW_COMMAND_H
