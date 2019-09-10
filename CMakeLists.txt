cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(IDPS)

set(CMAKE_CXX_STANDARD 17)
set(LOGGING_LEVEL "" CACHE STRING "Logging level, default is INFO")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -Wall -O3 -g ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -lcurses -Wall -O0 -g ")


include_directories(src/modul_3/Actions)
include_directories(src/modul_3/App)
include_directories(src/modul_3/ClientDaemond)
include_directories(src/modul_3/CommandCenter)
include_directories(src/modul_3/Config)
include_directories(src/modul_3/IDPS)
include_directories(src/modul_3/Log)
include_directories(src/modul_3/Packets)
include_directories(src/modul_3/Rules)
include_directories(src/modul_3/Utils)
include_directories(src/modul_3/Exceptions)
include_directories(src/modul_3/Patterns)

add_executable(conti_app_final
        src/modul_3/Actions/Actions.h
        src/modul_3/Actions/BadContent.cpp
        src/modul_3/Actions/BadContent.h
        src/modul_3/Actions/testActions.cpp
        src/modul_3/Actions/testActions.h
        src/modul_3/App/app.cpp
        src/modul_3/App/app.h
        src/modul_3/ClientDaemond/client.cpp
        src/modul_3/ClientDaemond/client.h
        src/modul_3/CommandCenter/command.cpp
        src/modul_3/CommandCenter/command.h
        src/modul_3/Config/configReader.cpp
        src/modul_3/Config/configReader.h
        src/modul_3/Config/configuration.cpp
        src/modul_3/Config/configuration.h
        src/modul_3/Config/Constants.h
        src/modul_3/IDPS/idps.cpp
        src/modul_3/IDPS/idps.h
        src/modul_3/Log/logger.cpp
        src/modul_3/Log/logger.h
        src/modul_3/Log/Notify.h
        src/modul_3/Packets/packet.cpp
        src/modul_3/Packets/packet.h
        src/modul_3/Rules/christmasTree.cpp
        src/modul_3/Rules/christmasTree.h
        src/modul_3/Rules/content.cpp
        src/modul_3/Rules/content.h
        src/modul_3/Rules/Rule.h
        src/modul_3/Rules/testRule.cpp
        src/modul_3/Rules/testRule.h
        src/modul_3/Utils/date.cpp
        src/modul_3/Utils/date.h
        src/modul_3/Exceptions/fatalError.cpp
        src/modul_3/Exceptions/fatalError.h
        src/modul_3/Exceptions/invalidParameterException.cpp
        src/modul_3/Exceptions/invalidParameterException.h
        src/modul_3/Utils/output.cpp
        src/modul_3/Utils/output.h
        src/modul_3/ClientDaemond/sender.cpp
        src/modul_3/ClientDaemond/sender.h
        main.cpp src/modul_3/Patterns/PatternReader.cpp
        src/modul_3/Patterns/PatternReader.h
        src/modul_3/Patterns/BasicPattern.cpp
        src/modul_3/Patterns/BasicPattern.h
        src/modul_3/Actions/BadIp.cpp
        src/modul_3/Actions/BadIp.h
        src/modul_3/Log/SLogger.cpp
        src/modul_3/Log/SLogger.h
        src/modul_3/Rules/SpecialRule.cpp
        src/modul_3/Rules/SpecialRule.h
        src/modul_2/modul_2_app.cpp
        src/modul_2/modul_2_app.h
        src/modul_1/modul_1_app.cpp
        src/modul_1/modul_1_app.h
        src/modul_4/modul_4.cpp
        src/modul_4/modul_4.h
        src/modul_5/modul_5.cpp
        src/modul_5/modul_5.h
        src/Communication/Modul_2.cpp
        src/Communication/Modul_2.h
        src/Communication/Modul_3.cpp
        src/Communication/Modul_3.h
        src/Communication/Modul_1.cpp src/Communication/Modul_1.h src/modul_3/Rules/OtherModule.cpp src/modul_3/Rules/OtherModule.h src/Communication/Modul_4.cpp src/Communication/Modul_4.h src/modul_3/modul_3_app.cpp src/modul_3/modul_3_app.h src/modul_3/Actions/BadFlag.cpp src/modul_3/Actions/BadFlag.h src/Utils/ConfigApp.cpp src/Utils/ConfigApp.h src/Utils/ExistsCommands.cpp src/Utils/ExistsCommands.h src/modul_5/pretty_print.cpp src/modul_5/pretty_print.h)

