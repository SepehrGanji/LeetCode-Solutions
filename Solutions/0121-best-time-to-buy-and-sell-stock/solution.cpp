class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxProf = 0, mini = prices[0];
      for(int i = 1 ; i < prices.size() ; i++) {
        int el = prices[i];
        if(el - mini > maxProf) maxProf = el - mini;
        else if(el < mini) mini = el;
      }

      return maxProf;
    }
};
