class Solution {
public:
    int lengthLongestPath(std::string input) {
        vector<int> stack = {0};
        int maxLen = 0;
        stringstream ss(input);
        string part;

        while (getline(ss, part, '\n')) {
            int level = part.find_last_of('\t') + 1; 
            while (level + 1 < stack.size()) {
                stack.pop_back();
            }
            int length = stack.back() + part.length() - level + 1;
            stack.push_back(length);

            if (part.find('.') != string::npos) {
                maxLen = max(maxLen, length - 1); 
            }
        }
        return maxLen;
    }
};
