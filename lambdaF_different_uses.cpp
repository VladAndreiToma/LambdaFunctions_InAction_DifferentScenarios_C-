#include <iostream>
#include <fstream>
#include <cmath>

void lambdaF_different_uses(){
    // method1
    // this is a generic called lambda function without name assigment
    [](int a , int b){
        std::cout << "From method 1: Calling without name using cout: " << (a+b) << std::endl;
    }( 10 , 20);
    // method2
    // pure assignment to a name type is to be deduced by compiler if using auto
    // or can be assigned by coder
    // method 2
    auto myResult = []( int var1, int var2 ){
        // return works in this case cause it puts stuff inside myResult
        return abs( var1 + var2 );
    };
    int myResult_2 = [](int var1 , int var2 ){
        return abs( var1 + var2 );
    }( 10 , 20 );
    // now here lets indulge for an example that will allow to demonstrate an eventual crash
    // i.e. the mismatch in the data type that we send in the coma separated list of params
    int result3 = []( double var1 , double var2 ){
        return (var1 - var2);
    }( 25.01 , 3.76);
     
    std::cout << "From method 2 calling with a name assigned using return and call at name runnig: " << myResult( 10 , 20 ) << std::endl;
    std::cout << "From method 2 calling with a name assigned but with run before calling and type user specified: " << myResult_2 << std::endl;
    // result3 should rise a comphat we convert to int by chunking it down
    /*int result4 = []( double var1 , double var2 )->int{
        return ( var1 - var2 ); compilation error? it doesnt cause it, converts intrinsically to int
    // but we can make sure t
    }( 22.03 , 8.98 );
    std::cout << result4 << std::endl;
    */
    std::cout << "Implicit conversion by specifying the data of the result param that we expect: " << result3 << std::endl;
}