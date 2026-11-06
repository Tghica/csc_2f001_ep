#include <iostream>
#include "lispEval.h"

using namespace std;

int main() {
    frame_t* frame = new frame_t;

    symbol_t* i = new symbol_t{"i"};
    frame->set(i, new integer_t{0});

    // Build: (< i 3)
    list_t* condition = new list_t;
    condition->append(new less_t);
    condition->append(i);
    condition->append(new integer_t{3});

    // Build: (+ i 1)
    list_t* addition = new list_t;
    addition->append(new add_t);
    addition->append(i);
    addition->append(new integer_t{1});

    // Build: (set! i (+ i 1))
    list_t* assignment = new list_t;
    assignment->append(new set_t);
    assignment->append(i);
    assignment->append(addition);

    // Build: (while (< i 0) (set! i (+ i 1)))
    list_t* loop = new list_t;
    loop->append(new while_t);
    loop->append(condition);
    loop->append(assignment);

    loop->eval(frame);

    std::cout << loop->to_string() << " => i = " << frame->get(i)->to_string() << '\n';

    return 0;
}