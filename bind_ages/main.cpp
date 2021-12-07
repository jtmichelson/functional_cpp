#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

auto greater_than(int first, int second) {
    return first >= second;
}

int main() {
    vector<int> ages{9, 20, 13, 4, 5, 6, 10, 28, 19, 15, 60, 23, 47, 12, 19, 99};
    int over21 = 0;
    for (int age : ages) {
        if (age >= 21) {
            ++over21;
        }
    }
    cout << "Number over 21 = " << over21 << endl;

    // functional version of same code above
    auto num_over21 = count_if(ages.begin(), ages.end(),
        bind(&greater_than, placeholders::_1, 21)
    );
    cout << "New number of over 21 = " << num_over21 << endl;

    return 0; 
}
