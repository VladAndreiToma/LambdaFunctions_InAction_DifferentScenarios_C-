//######################################################################33
// An example of lambda function inside an STL algo
#include <iostream>
#include <vector>
#include <algorithm>

void lambdaF_inSTL_algos(){
    std::vector<int> numbers = { 1 , 2, 3 , 4, 5, 6 };
    std::vector<int> numbersCopy( numbers ); // creating a copy through std::vector constructor syntax

    // lambda function to filter the even numbers + std::remove_if
    auto isOdd_AutoTypeGeneration = []( int n ){
        return n%2 != 0; // when we impose a conditional here evaluated to a certain outcome in this case 0 we generate a truth value true or false
    };

    // lets see what happens if we know we expect the a truth result --- a boolean
    auto isOdd_WeKnowWhatTypeWeReturn = []( int n ){
        return n%2 != 0;
    };

    numbers . erase( std::remove_if( numbers.begin() , numbers.end() , isOdd_AutoTypeGeneration ) , numbers.end() );
    // so we make use of erase function to delete element from all array's range using the filter lambda function isOdd custom made before
    // now to print the result
    std::cout << "The even numbers that are left are: \n";
    for( const int &n : numbers ){
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    numbersCopy . erase( std::remove_if( numbersCopy.begin() , numbersCopy.end() , isOdd_WeKnowWhatTypeWeReturn ) , numbersCopy.end() );
    std::cout << "The even numbers that are left when we apply the lambda of which type we know: \n";
    for( const int &n : numbersCopy ){
        std::cout << n << " ";
    }
    std::cout << std::endl;

}
