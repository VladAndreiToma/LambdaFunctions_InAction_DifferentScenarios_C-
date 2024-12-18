#include "iostream"
#include "vector"
#include "numeric"

void lambdaF_in_std_accumulate(){
    std::vector<int> numbers = { 1 , 2 ,3 ,4 ,5 ,6  };
    int myProduct = std::accumulate(
        numbers.begin() , numbers.end() , 1 , []( int acc , int x ){
            return acc * x; // since locally acc keeps context it the lambda function will work like an accumulator
        }
    );
    std::cout << "Product of elements: " << myProduct << std::endl;
}