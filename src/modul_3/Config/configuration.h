//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_CONFIGURATION_H
#define IDPS_NEW_CONFIGURATION_H


#include <vector>
#include <string>
#include <map>
#include <mutex>
#include <Notify.h>
#include "../Patterns/BasicPattern.h"

namespace idps {


    class Configuration {
    public:
        explicit Configuration(std::map<std::string, std::string> conf);

        virtual ~Configuration();

        [[nodiscard]] const std::string &getLogFileLocation() const;

        [[nodiscard]] std::string show() const;

        [[nodiscard]] const std::vector<std::string> *getBadFlags() const;

        [[nodiscard]] std::string getIp() const;

        [[nodiscard]] std::string getWhitelistLocation() const;

        [[nodiscard]] std::string getBlacklistLocation() const;

        [[nodiscard]] BasicPattern *const getPattern() const;

        [[nodiscard]] int getPort() const;

        [[nodiscard]]  const std::string &getStFileLocation() const;

        void setPattern(BasicPattern *pattern);

        void addNotify(Notify *notify);

        Notify *getNotify();

        void addIp(std::string ip);

        std::vector<std::string> getListIps();

        int getMaxPack();

    private:
        Notify *notify;
        std::vector<std::string> badBoy{};
        BasicPattern *pattern{};
        std::map<std::string, std::string> conf{};
    };
}


#endif //IDPS_NEW_CONFIGURATION_H
