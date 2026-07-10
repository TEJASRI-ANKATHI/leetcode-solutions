class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> mp;

        for(string word : words)
            mp[word]++;

        auto cmp = [](pair<string,int>& a, pair<string,int>& b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        };

        priority_queue<pair<string,int>,
                       vector<pair<string,int>>,
                       decltype(cmp)> pq(cmp);

        for(auto &it : mp)
            pq.push(it);

        vector<string> ans;

        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};