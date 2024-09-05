class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int cand = 0, cnt = 0;
    for(auto el: nums) {
        if(cnt == 0) cand = el, cnt = 1;
        else {
            if(el == cand) cnt++;
            else cnt--;
        }
    }
    return cand;
}
};
