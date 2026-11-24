#include <iostream>
#include <queue>
#include <stack>
#include "OPMMLib\procesos.hpp"
#include "OPMMLib\config.hpp"

void printQueue(std::queue<Proceso> secondQueue) {
    std::stack<Proceso> stackTemp;

    while (!secondQueue.empty()) {
        stackTemp.push(secondQueue.front());
        secondQueue.pop();
    }

    while (!stackTemp.empty()) {
        printProcess(stackTemp.top());
        stackTemp.pop();
    }
}