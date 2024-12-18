#include "iostream"
#include "queue"
#include "vector"

void lambdaF_for_comparator_in_priorityQueue(){
    // lets use the lambda function to construct a comparator for a priority queue usage
    // assign a name to the callable object that is the lambda function and use "auto" keyword to make compilare deduce the type of return
    auto myComparator = []( int a , int b ){
        return a > b;
    };
    // creating a priority queue using the standard libraries Q and vector
    std::priority_queue<int,std::vector<int> , decltype( myComparator )> myPQ( myComparator );
    // now we insert values in the priorty queue and they will be evaluated with the comparator
    myPQ . push( 10 );
    myPQ . push( 1 );
    myPQ . push( 5 );
    myPQ . push( 100 );
    myPQ . push( 7 );
    // we could go on here
    std::cout << "PQ elements in ascending order: ";
    while( !myPQ.empty() ){
        // while the queue is not empty
        std::cout << myPQ.top() << " ";
        myPQ.pop();
    }
    std::cout << std::endl;
}