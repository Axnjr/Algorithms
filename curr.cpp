#include <vector>
#include <iostream> 
#include <map>
using namespace std;
// Alex and Chris are learning to infiltrate a secure system.
// Starting with a string of code, Alex will remove any substring
// with an odd number of vowels. Chris then removes any
// substring from the remaining code with an even number of
// vowels. This learning continues until one of them is unable
// to make a move. Given an array of n strings of code,
// determine the winner of each round and report the results
// as either "Alex" or "Chris" accordingly. Assume both act
// optimally.
// Note: The vowels considered are 'a', 'e', 'i', 'o', and 'u'.
// Example
// Given n = 3and s = ["ljis", "Ihr", "gms"].
// . In the 1st round, the whole string "ljis" contains 1 vowel
// (odd), so Alex chooses the whole string. Now the string is ""
// (empty string), and Chris cannot make a move, hence Alex
// wins the round.
// . In the 2nd round, the string "Ihr" does not contain any vowel
// hence Alex cannot make a move. Therefore Chris wins the
// round.
// . In 3rd round, the string "gms" does not contain any vowel, so
// again Chris wins the round.
// 2nd round
// 1st round
// 3rd round
// "ihr
// *gms"
// -
// gms"
// Chanen atring
// Deeon't coniin any vowel
// nound
// Doanft conten any vol
// Chra wina Ihe
// round
// Chrts wna the
// tound
// Hence the answer is ["Alex", "Chris", "Chris"].


// Given a array of distinct integers print all pairs with same absolute diffrence
void printPairsWithAbsDiff(vector<int> nums){
    map<pair<int, int>, int> mp;
    for(int i = 0; i < nums.size() ; i++){
        for(int j = 1; j < nums.size() ; j++){
            mp[{nums[i], nums[j]}] = abs(nums[i] - nums[j]);
        }
    }
    for(auto& pair : mp){
        cout << "(" << pair.first.first << ", " << pair.first.second << ") -> " << pair.second << endl;
    }
}

int main() {
    vector<int> v = {6,2,4,10};
    printPairsWithAbsDiff(v);
    return 0;
}
