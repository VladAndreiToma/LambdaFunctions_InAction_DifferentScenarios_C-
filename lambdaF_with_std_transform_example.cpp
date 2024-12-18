#include "iostream"
#include "vector"
#include "algorithm"

void lambdaF_with_std_transform_example(){
    std::vector<int> numbers = { 1 ,2 , 3 ,4 ,5 ,6 };
    std::vector<int> squaredNumbers( numbers.size() );
    // creating a vector of squared numbers from "numbers" and i use a lambda function inside the transform function
    std::transform( numbers.begin() , numbers.end() , squaredNumbers.begin() , [](int x){
        return (x*x);
    } );
    // no need to specify a name or smth, no capture list, just a parameters in the list of parameters

    std::cout << "Numbers given: ";
    for( const int &n : numbers )     std::cout << n << " ";
    std::cout << "\nNumbers squared via transform: ";
    for( const int &n : squaredNumbers )     std::cout << n << " ";
}

