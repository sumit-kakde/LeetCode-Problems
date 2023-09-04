class Solution {
public:
    int countPrimes(int n) {
           if (n <= 2) {
        return 0; // There are no prime numbers less than 2
    }

    // Create a boolean array to mark numbers as prime or non-prime
    std::vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Use Sieve of Eratosthenes to mark non-prime numbers
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count the number of prime numbers
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }

    return count; 
    }
};