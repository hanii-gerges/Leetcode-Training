class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        string ans = "";
        for (int i = 0;i < s.size(); i++) {
            char c = s[i];
            bool flag = true;
                for ( int j = 0; j < strs.size(); j++) {
                    if (strs[j][i] != c) {
                        flag = false;
                        break;
                    }
                }
            if (flag) ans+=c;
            else break;
        }
        
        return ans;
    }
};