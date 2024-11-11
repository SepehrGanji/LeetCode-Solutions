class Solution {
public:
    bool isPrime(int n) {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        for(int i = 5 ; i * i <= n ; i += 6) {
            if(n % i == 0) return false;
            if(n % (i+2) == 0) return false;
        }
        return true;
    }
    
    int biggest_prime_before(int n) {
        while(n-- > 0) {
            if(isPrime(n)) return n;
        }
        return -1;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        int zer = biggest_prime_before(nums[0]);
        if(zer != -1) nums[0] -= zer;
        for(int i = 1 ; i < n ; i++) {
            int el = nums[i];
            int current_el = el;
            while(1) {
                int ans = biggest_prime_before(current_el);
                if(ans == -1) break;
                if(el - ans > nums[i-1]) {
                    nums[i] -= ans;
                    break;
                } else {
                    current_el = ans;
                }
            }
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};
