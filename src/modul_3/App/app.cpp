//
// Created by root on 8/5/19.
//

#include <iostream>
#include <app.h>
#include <Notify.h>
#include <logger.h>
#include <invalidParameterException.h>
#include <idps.h>
#include <configReader.h>
#include <fatalError.h>
#include <client.h>
#include <SLogger.h>
#include <zconf.h>

using namespace idps;


void idps::App::start(int argc, char **argv) {
    try {

        auto configuration = ConfigReader::getConfiguration();
        auto client = new Client(configuration);

        Notify *notify = new SLogger(configuration->getLogFileLocation(), configuration->getStFileLocation());
        configuration->addNotify(notify);
        notify->send("Application started");


        auto protectionSys = new IDPS(client, configuration);
        protectionSys->run();

        free(notify);
        sleep(3);
        free(configuration);
        free(protectionSys);
        free(client);


    } catch (InvalidParameterException &exception) {
        std::cerr << "Error: " << exception.what();
    } catch (FatalError &fatalError) {
        std::cerr << "Error: " << fatalError.what();
    }
}
