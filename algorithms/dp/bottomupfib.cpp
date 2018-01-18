#include <iostream>

using namespace std;

int fib[1001] = {1, 1};

int fibo(int n) {
    // for 1, 2
    if (n < 3) return fib[n];
    int i = 3;
    while (i <= n) {
        fib[i-1] = fib[i-2] + fib[i-3];
        i++;
    }
    return fib[n-1];
}
int main() {
    int n;
    cout << "fib n? ";
    cin >> n;
    cout << fibo(n) << endl;
}
