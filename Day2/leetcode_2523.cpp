//Closest prime number in range
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);

        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        if (primes.size() < 2) {
            return {-1, -1};
        }
        if(left==1)
        {
            return {2,3};
        }

        int minDiff = INT_MAX;
        vector<int> result(2);
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i], primes[i + 1]};
            }
        }

        return result;
    }
};

