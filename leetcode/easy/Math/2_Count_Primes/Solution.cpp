class Solution {
public:
    int countPrimes(int n) {
        if (n<3)
            return 0;
        // Sieve of Eratosthenes, skip even numbers.
        vector<bool> isprime(n, true);
        int primes = 1;
        for (int i=3; i<n; i+=2) {
            if (isprime[i]) {
                primes++;
                for (long long j= (long long)i*i; j<n; j+=2*i) {
                    isprime[j] = false;
                }
            }
        }
        
        return primes;
    }
};
