#include <vector>
#include <stack>
#include <iostream>
#include <regex>
#include <map>
using namespace std;
// Given a array of distinct integers print all pairs with same absolute diffrence
// void printPairsWithAbsDiff(vector<int> nums)
// {
//     multimap<int, pair<int, int>> mp;
//     multimap<int, int> freq;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             int diff = abs(nums[i] - nums[j]);
//             // mp[{nums[i], nums[j]}] = abs(nums[i] - nums[j]);
//             mp.insert({diff, {nums[i], nums[j]}});
//         }
//     }
//     for (auto &pair : mp)
//     {
//         // cout << "(" << pair.second.first << ", " << pair.second.second << ") ->" << pair.first << endl;
//         if (freq.count(pair.second))
//         {
//             freq[pair.second]++;
//         }
//         else
//         {
//             freq[pair.second] = 1;
//         }
//     }
// }

// int evalRPN(vector<string> &tokens)
// {
//     stack<int> ds; // digitStack
//     regex reg("[0-9]");
//     for (auto token : tokens)
//     {
//         if (regex_match(token, reg))
//         {
//             ds.push(stoi(token));
//         }
//         else
//         {
//             switch (token)
//             {
//             case "+":
//                 int sum = 0;
//                 while (ds.empty())
//                 {
//                     sum += ds.top()
//                                ds.pop()
//                 }
//                 ds.push(sum);
//                 break;
//             case "-":
//                 int sum = 0;
//                 while (ds.empty())
//                 {
//                     sum -= ds.top()
//                                ds.pop()
//                 }
//                 ds.push(sum);
//                 break;
//             case "*":
//                 int sum = 1;
//                 while (ds.empty())
//                 {
//                     sum *= ds.top()
//                                ds.pop()
//                 }
//                 ds.push(sum);
//                 break;
//             case "/":
//                 int sum = 1;
//                 while (ds.empty())
//                 {
//                     sum /= ds.top()
//                                ds.pop()
//                 }
//                 ds.push(sum);
//                 break;
//             }
//         }
//     }
// }

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

class Solution {
public:
    void topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> m;

        for(auto n: nums){
            auto temp = m.find(n);
            if(temp != m.end()){
                m[n]++;
            }
            else {
                m.emplace(n, 1);
            }
        }

        for(auto mv: m){
            cout << mv.first << " , " << mv.second << endl;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> v = {30,38,30,38,36,40,35,30,28};
    // printPairsWithAbsDiff(v);
    // dailyTemperatures(v);
    sol.topKFrequent(v, 2);
    return 0;
}
