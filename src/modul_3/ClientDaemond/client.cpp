//
// Created by root on 8/5/19.
//

#include <client.h>
#include <fatalError.h>
#include <zconf.h>
#include <cstring>


using namespace idps;

#define SERVER_PATH     "/tmp/server1"

Client::Client(const Configuration *configuration) {
//    if ((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
//        throw FatalError("socket creation failed");
//
//    memset(&serveraddr, 0, sizeof(struct sockaddr_un));
//    serveraddr.sun_family = AF_UNIX;
//    strncpy(serveraddr.sun_path, SERVER_PATH, sizeof(serveraddr.sun_path) - 1);

}

void Client::sendToServer(std::string message) const {

//    if (send(sockfd, message.c_str(), 250, 0) < 0)
//        printf("error send to server");
    sendto(sockfd, message.c_str(), 250, 0, (
            struct sockaddr *) &serveraddr, sizeof(struct sockaddr_un));
}

Client::~Client() {
    if (sockfd != -1)
        close(sockfd);

}