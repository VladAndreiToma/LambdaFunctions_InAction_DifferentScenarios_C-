#include "iostream"
#include "future"

// This code aims to use lambda functions for concurrent computations
void lambdaF_for_parallelizing_in_std_async(){
    auto computeSum = []( int start , int finish ){
        int sum = 0;
        for( int i = start ; i <= finish ; i++ ){
            sum += i;
        }
        return sum;
    };
    // so here we deploy 2 sumation jobs of type promise return async.
    // in a non blocking manner we deploy uninterfering jobs that once solved will return a result. They are interval sumation jobs
    auto futureSumation1 = std::async( std::launch::async , computeSum,  1, 50 ); // deploy asynchronously a sumation job on the interval 1,50
    auto futureSumation2 = std::async( std::launch::async , computeSum , 51 , 100 ); // _________________________________________________51,100
    int totalSum = futureSumation1.get() + futureSumation2.get();
    std::cout << "Total sum: " << totalSum << std::endl;
}