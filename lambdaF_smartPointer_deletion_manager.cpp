//##########################################################################
// An example of smart pointer custom deleter manager
#include "memory"

void smartPointerShowCase(){
    // creating the lambda function is a callable object so we use auto for the compiler to deduce the returned type
    auto customDeleter = []( int* myPointer ){
        std::cout<< "Deleting the pointer that points at: " << myPointer << " and has the value: " << *myPointer << std::endl;
        delete myPointer; // deleting    
    };
    // creating an unique pointer with custom action associated to it
    std::unique_ptr<int , decltype(customDeleter)> mySmartPointer( new int(42) , customDeleter );
    std::cout << "Smart pointer value: " << *mySmartPointer << std::endl;
}