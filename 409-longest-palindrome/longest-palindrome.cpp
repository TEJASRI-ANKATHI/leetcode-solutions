class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        bool odd = false;

        for(char c : s)
            mp[c]++;

        for(auto x : mp) {
            ans += x.second / 2 * 2;
            if(x.second % 2)
                odd = true;
        }

        if(odd) ans++;

        return ans;
    }
};