#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include <exception>
#include <chrono>
#include <iterator>
#include <random>

using namespace std;

#include "Hash.cpp"
#include "RobinHoodHashTable.cpp"
#include "timeTest.cpp"
#include "testForGrafics.cpp"


int main()
{
    for (double i = 0.2; i <= 1; i += 0.05)
    test_for_graphics(i, 100000);
   
    
    for (int i = 1; i <= 7; i++) {
        cout << i * 10000<< " : "<<endl;
        test_time(i * 10000);
        cout << endl;
    }
    return 0;
}
