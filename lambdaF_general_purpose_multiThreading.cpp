#include <thread>
#include <vector>
#include <numeric>

void lambdaF_general_purpose_multiThreading(){
    // a example of lambda functions used in threading
    // labmda to compute the sum of a range
    auto mySumLambda = []( int start , int finish ) -> int {
        // inside scope declaration of sum param
        int sum = 0;
        for( int i = start ; i <= finish ; ++i ){
            sum += i;
        }
        return sum;
    };

    // dividing the total range in 3 threads
    int result1 = 0 , result2 = 0 , result3 = 0;
    // i ll call the sum_lambda function inside another lambda function
    // just to make use of this concept
    // i ll also send the results with reference inside the caputre lists so my labmda function has the ability to scope top level and modify the results
    // the second lambda functions are neutral just to scope out the inner lambda function within their capture lists
    std::thread myThread1( [ &result1 , mySumLambda ](){
        result1 = mySumLambda( 10, 30 );
    } );
    std::thread myThread2( [ &result2 , mySumLambda ](){
        result2 = mySumLambda( 30 , 50 );
    } );
    std::thread myThread3( [ &result3 , mySumLambda ](){
        result3 = mySumLambda( 50 , 100 );
    } );
    // threads are started -> now joining
    myThread1.join();
    myThread2.join();
    myThread3.join();
    int totalSum = result1 + result2 + result3;
    std::cout << "The summation from all threads: " << totalSum << std::endl;
}
