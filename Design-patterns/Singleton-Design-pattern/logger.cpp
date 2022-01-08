#include <iostream>

#include "logger.hpp"
#include <thread>

using namespace std;

int Logger::ctr = 0;
Logger *Logger::loggerInstance = nullptr;

mutex Logger : mtx;

Logger::Logger()
{
    ctr++;
    cout << "New Instance created no of  instance is " << ctr;
}

void Logger::Log(string message)
{
    cout << message << endl;
}

Logger *Logger::getLogger()
{
    if (loggerInstance == nullptr)
    {

        mtx.lock();
        if (loggerInstance == nullptr)
        {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}
