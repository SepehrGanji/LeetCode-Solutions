class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans = 0; int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        int grps = n / 4; int ptr = n-1;
        for(int i = 0 ; i < grps ; i += 2) {
            ans += pizzas[ptr];
            ptr--;
        }
        for(int i = 1 ; i < grps ; i += 2) {
            ans += pizzas[ptr-1];
            ptr-=2;
        }

        return ans;
    }
};
