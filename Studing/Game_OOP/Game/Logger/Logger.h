//
// Created by danil on 12.11.2021.
//

#ifndef MAIN_CPP_LOGGER_H
#define MAIN_CPP_LOGGER_H

#include <string>

class Logger {
    static Logger* logger_object;
    std::string event_info;
    Logger();
public:
    Logger(const Logger&) = delete;
    void operator=(const Logger&) = delete;
    static Logger* get_logger();
    std::string get_event_info();
    void set_event_info(std::string event);
};


#endif //MAIN_CPP_LOGGER_H
