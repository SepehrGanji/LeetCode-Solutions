class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int ans = 0, current_gas = 0;
    int total_gas = 0, total_cost = 0;
    for(int i = 0 ; i < n ; i++) {
        total_gas += gas[i];
        total_cost += cost[i];

        current_gas += (gas[i] - cost[i]);

        if(current_gas < 0) {
            ans = i+1;
            current_gas = 0;
        }
    }
    if(total_cost > total_gas) return -1;
    return ans;
}
};
