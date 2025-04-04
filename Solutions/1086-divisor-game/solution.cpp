class Solution {
public:
    bool isPrime(int x) {
        if(x == 2 || x == 3) return true;
        if(x % 2 == 0 || x % 3 == 0) return false;
        for(int i = 5 ; i * i < x ; i++) if(x % i == 0) return false;
        return true;
    }
    
    bool divisorGame(int n) {
        vector<bool> winners(1001, false);
        
        winners[1] = false; // bob
        winners[2] = true; // alice
        
        for(int i = 3 ; i <= n ; i++) {
            if(!isPrime(i)) {
                for(int j = 1 ; j * j <= i ; j++) {
                    if(i % j == 0 && winners[i-j] == false) winners[i] = true;
                }
            }    
        }
        
        return winners[n];
    }
};
