//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    auto render = [](auto collection) {
        for (const auto &val : collection) {
            cout << val << endl;
        }
    };

    vector<int> inCollection{1,2,3,4,5,6,7,8,9,10};
    vector<int> outCollection;
    transform(inCollection.begin(), inCollection.end(), 
        back_inserter(outCollection), [](const int &value){ return value * 3; }
    );
    cout << "transform:" << endl;
    render(outCollection);

    vector<int> filteredCollection;
    copy_if(outCollection.begin(), outCollection.end(), 
        back_inserter(filteredCollection), [](int &value){ return value % 2 != 0; }
    );
    cout << "copy_if:" << endl;
    render(filteredCollection);

    int results = accumulate(filteredCollection.begin(), filteredCollection.end(), 
        0, [](int total, int current){ return total + current; }    
    );
    cout << "accumulate:" << endl;
    cout << results << endl;

    return 0;
}

/*
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

TEST_CASE("Fibonacci series", "[fibonacci]") {
    REQUIRE(fibonacci(0) == 0);
    REQUIRE(fibonacci(1) == 1);
    REQUIRE(fibonacci(2) == 1);
    REQUIRE(fibonacci(3) == 2);
    REQUIRE(fibonacci(4) == 3);
    REQUIRE(fibonacci(5) == 5);
    REQUIRE(fibonacci(12) == 144);
}
*/
