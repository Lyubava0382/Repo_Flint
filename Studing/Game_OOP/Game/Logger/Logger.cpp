//
// Created by danil on 12.11.2021.
//

#include "Logger.h"

Logger* Logger::get_logger(){
    if(logger_object == nullptr){
        //logger_object = new Logger();
    }
    return logger_object;
}

std::string Logger::get_event_info(){
    return event_info;
};

void Logger::set_event_info(std::string event){
    event_info = event;
};

Logger* Logger::logger_object = nullptr;