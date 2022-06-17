#include "NDArray.h"
#include <iostream>

int main()
{

     std::vector<int> testsize;
    testsize.push_back(2);
    testsize.push_back(3);

    NDArray<int> test(testsize);
    test.set(0, 1);
    test.set(1, 2);
    test.set(2, 3);
    test.set(3, 4);
    test.set(4, 5);
    test.set(5, 6);
    NDArray<int> transptest = test.MatrixTransp();
    std::cout << test.get(1)<<std::endl;
    std::cout << test.MatrixTransp().get(1) << std::endl;
    
    
    for (int i = 0; i < 6; i++) {
        std::cout << test.get(i)<< ' ';
    }
    std::cout<< std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << transptest.get(i)<< ' ';
    }
    

}

