//
// Created by root on 8/5/19.
//

#ifndef IDPS_NEW_CLIENT_H
#define IDPS_NEW_CLIENT_H

#include <netinet/in.h>
#include <Constants.h>
#include <configuration.h>
#include <sender.h>
#include <sys/un.h>
#define BUFFER_LENGTH    250
namespace idps {
    class Client : public NotifySender {
    public:
        explicit Client(const Configuration *configuration);

        void sendToServer(std::string message) const override;

        ~Client();

    private:

        int sockfd = 0;
        struct sockaddr_in servaddr;
        struct sockaddr_un serveraddr;
        char buffer[BUFFER_LENGTH];
    };


}


#endif //IDPS_NEW_CLIENT_H
