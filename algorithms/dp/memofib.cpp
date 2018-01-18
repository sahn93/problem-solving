#include <iostream>

using namespace std;

int memo[1001] = {1, 1};

int fib(int n) {
    if (n<2) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
int main() {
    int n;
    cout << "fib n? ";
    cin >> n;
    cout << fib(n) << endl;
}
