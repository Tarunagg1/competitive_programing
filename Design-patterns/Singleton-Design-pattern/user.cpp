#include <iostream>

#include "logger.hpp"

#include<thread>

void userLog1(){
    Logger *logger1 = Logger::getLogger();
    logger1->Log(" This is form user 1");
}


void userLog2(){
    Logger *logger2 = Logger::getLogger();
    logger2->Log(" This is form user 2");
}


int main()
{
    thread t1(userLog1);
    thread t2(userLog2);

    t1.join();
    t2.join();

    return 0;
}

