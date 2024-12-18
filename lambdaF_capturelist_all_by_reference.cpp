//##########################################################################
// An example to showcase the reference capturing to modify out of scope variables
#include "iostream"

void captureByReferenceExample(){
    int counter = 0;
    // using the principia of capture_all with [&]
    auto incrementCounter = [&](){
        ++ counter;
        std::cout << "current counter value: " << counter << '\n';
        std::cout << "counter lives @: " << &counter << '\n';
        std::cout << "------------------------------" << '\n';
    };
    // name assignment call
    incrementCounter();
    incrementCounter();
    incrementCounter(); // each time counter value should get modified
    // from console log we can see that its the same address everywhere as we work with reference  
} 