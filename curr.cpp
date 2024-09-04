#include <vector>
#include <stack>
#include <iostream>
#include <regex>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

vector<int> dailyTemperatures(vector<int> &tem)
{
    stack<pair<int, int>> s;
    vector<int> res(tem.size(), 0); // fill the result vector with 0's

    s.push(make_pair(tem[0], 0));

    for (int i = 1; i < tem.size(); i++)
    {
        while (!s.empty() && tem[i] > s.top().first)
        {
            res[s.top().second] = i - s.top().second;
            s.pop();
        }
        s.push(make_pair(tem[i], i));
    }

    return res;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> m; // (val, occurences)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    vector<int> res;

    for (auto n : nums)
    {
        m[n]++;
    }

    for (auto mv : m)
    {
        p.push({mv.second, mv.first});
        if (p.size() > k)
        {
            p.pop();
            // break;
        }
    }

    while (!p.empty())
    {
        res.push_back(p.top().second);
        p.pop();
    }

    for (auto i : res)
    {
        cout << i << endl;
    }

    return res;
}

class Solution {
   public:
    unordered_map<string, vector<string>> mp;
    vector<string> removeAnagrams(vector<string>& words) 
    {
        vector<string> result;
        for(auto& i: words){
            vector<int> count(26, 0);
            for(auto& j: i){
                count[j - 'a']++;
            }
            string key;
            for(auto c: count){
                key += to_string(c);
            }
            mp[key].push_back(i);
        }
        
        for(auto pair: mp){
            if(pair.second.size()){
                string t = pair.second[0];
                result.push_back(t);
            }
        }

        return result;
    }

    bool wordBreak(string s, vector<string>& wd) {
        int minwl = wd[0].length();
        int maxwl = wd[0].length();

        unordered_set<string> set;
        vector<string> ans;

        for(auto d: wd) {
            set.insert(d);
            // cout << int(d.length()) << endl;
            minwl = std::min(minwl, int(d.length()));
            maxwl = std::max(maxwl, int(d.length()));
        }

        string ansstr  = "";
        for(int i = 0; i < s.length(); i++){
            int till = minwl;
            bool ok = false;
            while(till <= maxwl){
                string t = s.substr(i, minwl);
                if(set.find(t) == set.end()){
                    ok = true;
                }
                till++;
            }
            if(!ok) return false;
        }

        return true;
    }

};

int main()
{
    Solution sol;
    vector<string> wd = {"leet","code"};
    // vector<int> v = {30, 38, 30, 38, 36, 40, 35, 30, 28};
    string s1 = "abc", s2 = "lecaabee";
    // printPairsWithAbsDiff(v);
    // dailyTemperatures(v);
    // sol.topKFrequent(v, 2);
    sol.wordBreak("leetcode", wd);
    
    return 0;
}
