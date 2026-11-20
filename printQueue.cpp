#include <iostream>
#include <queue>
#include <stack>
#include "procesos.hpp"

void printQueue(std::queue<Proceso> secondQueue) {
    std::stack<Proceso> stackTemp;

    while (!secondQueue.empty()) {
        stackTemp.push(secondQueue.front());
        secondQueue.pop();
    }

    while (!stackTemp.empty()) {
        std::cout << "["
		<< stackTemp.top().id
		<< ", "
		<< stackTemp.top().tam
		<< ", "
		<< stackTemp.top().cuanto
		<< "] ";
        stackTemp.pop();
    }
    std::cout << "\n";
}