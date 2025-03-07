class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i <= sqrt(n); i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i = left ; i <= right ; i++) if(isPrime(i)) primes.push_back(i);
        if(primes.size() < 2) return {-1, -1};
        vector<int> ans = {primes[0], primes[1]};
        int diff = primes[1] - primes[0];
        for(int i = 1 ; i < primes.size() - 1 ; i++) {
            int a = primes[i], b = primes[i+1];
            if(b - a < diff) {
                diff  = b - a;
                ans[0] = a;
                ans[1] = b;
            }
        }
        return ans;
    }
};
