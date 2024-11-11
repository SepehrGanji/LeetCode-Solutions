#define ll long long

class Solution {
public:
    unordered_map<ll, ll> mp;
    set<pair<ll, ll>> main, others;
    ll sum = 0;
    ll x;

    void add_el(ll count, ll value) {
        main.insert({count, value});
        sum += count * value;
        if(main.size() > x) {
            auto smallest = *main.begin();
            sum -= smallest.first * smallest.second;
            others.insert(smallest);
            main.erase(smallest);
        }
    }

    void remove_el(ll count, ll value) {
        auto curr = make_pair(count, value);
        if(main.find(curr) != main.end()) {
            sum -= count*value;
            main.erase(curr);
            if(others.size() > 0 && main.size() < x) {
                auto largest = *others.rbegin();
                sum += largest.first * largest.second;
                main.insert(largest);
                others.erase(largest);
            }
        } else {
            others.erase(curr);
        }
    }


    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        this->x = x;
        vector<ll> ans;
        int i = 0;
        for(int j = 0 ; j < n ; j++) {
            if(mp[nums[j]] > 0) remove_el(mp[nums[j]], nums[j]);
            mp[nums[j]]++;
            add_el(mp[nums[j]], nums[j]);
            if(j - i + 1 > k) {
                remove_el(mp[nums[i]], nums[i]);
                mp[nums[i]]--;
                if(mp[nums[i]] > 0) {
                    add_el(mp[nums[i]], nums[i]);
                }
                i++;
            }
            if(j - i + 1 == k) ans.push_back(sum);
        }

        return ans;
    }
};
