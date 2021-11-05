#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>


int flavel_rec(int n, int k) {
    if (n == 1) return 1;
    return (flavel_rec(n - 1, k) + k - 1) % n + 1;
}

int flavel_brute_force(int n, int k) {
    std::vector<int> order;
    for (int i = 1; i < n+1; i++)
    {
        order.push_back(i);
    }
    int current = 1;
    while (order.size() != 1) {
        if (current == k) {
            order.erase(order.begin());
            current = 1;
        }
        else {
            int a = order[0];
            order.erase(order.begin());
            order.push_back(a);
            current++;
        }
    }
    return order[0];
}





int main()
{
    int n, k;
    std::cout << "Enter the count of people. N=";
    std::cin >> n;
    std::cout << "Enter the number of the person in line to be executed. K=";
    std::cin >> k;
    std::cout << "Test recursive function..." << std::endl;
    clock_t start = clock();
    int a = flavel_rec(n, k);
    clock_t end = clock();
    std::cout.setf(std::ios::fixed);
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Answer = " << a << "  Used time:" << std::setw(15) << std::setprecision(10) << seconds<<" Seconds"<< std::endl;
    std::cout << "Test \"Brute Force\" function" << std::endl;
    start = clock();
    a = flavel_brute_force(n, k);
    end = clock();
    seconds = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Answer = " << a << "  Used time:" << std::setw(15) << std::setprecision(10)<< seconds << " Seconds" << std::endl;
}

