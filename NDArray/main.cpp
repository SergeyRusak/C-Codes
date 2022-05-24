#include "NDArray.h"
#include <iostream>

int main()
{

    std::vector<int> testsize;
    testsize.push_back(2);
    testsize.push_back(2);

    NDArray<int> test(testsize);
    test.set(0, 1);
    test.set(1, 2);
    test.set(2, 3);
    test.set(3, 4);

    std::cout << test.get(1)<<std::endl;
    std::cout << test.MatrixTransp().get(1) << std::endl;
    
    
    NDArray<int> test2(3, 2, 2, 2);
    test2.set(0, 2);
    NDArray<int>test21(NDArray<int>::one(2,2,2));
    NDArray<int>test22 = NDArray<int>::rand(2,2,2);
    std::cout << test22.get(0) << std::endl;
    std::cout << (test22-test21).get(0) << std::endl;
    NDArray<int>test3 = test22.MatrixMultiply(test21);
    std::cout << test3[0];

}

