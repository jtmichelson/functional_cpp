#include <iostream>
#include <vector>
using namespace std;

// regular recursive implementation
int factorial(const int input, const int sum = 1) {
    if (input > 1) {
        return factorial(input - 1, sum * input);
    } else {
        return sum;
    }
}

// template metaprogramming implementation
// there is no branching logic in TMP so we use specialization
template<int input, int sum = 1>
struct Factorial : Factorial<input - 1, input * sum> {};
template<int sum>
struct Factorial<1, sum> {
    enum {
        value = sum
    };
};

int main() {
    cout << "5! = " << factorial(5) << endl;
    cout << "Factorial<4> " << Factorial<4>::value << endl;
    cout << "Factorial<5> " << Factorial<5>::value << endl;
    return 0;
}
