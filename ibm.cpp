// for ibm coding assesment practice
#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <set>
#include <stack>

using namespace std;

int minFlips(string s){
    int flip = 0, w = 2;
    for(int i = 0; i < s.length(); i = i + w){
        if(s[i] != s[i+1]) flip++;
    }
    return flip;
}

void arrayChalange(vector<long> arr){
    int n = arr.size();
    vector<long> ans(n, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            ans[i] += abs(arr[j] - arr[i]);
        }
    }

    for(auto i: ans){
        cout << i << endl;
    }
}

int sub(int n, int count=0){
    if (n <= 1) return count;
    return sub(n-2, count+1);
}

int findMinimumMoves(string s){
    vector<int> v(26, 0);
    for(int i = 0; i < s.length(); i++){
        v[s[i] - 'a']++;
    }
    int ans = 0;
    for(auto& i: v){
        ans += sub(i);
    }
    cout << ans << endl;
    return ans;
}

int findTriplets(vector<int> arr, int d){
    int count = 0;
    for(int i = 0; i < arr.size()-2; i++){
        for(int j = i + 1; j < arr.size()-1; j++){
            for(int k = j + 1; k < arr.size(); k++){
                if((arr[i] + arr[j] + arr[k]) % d == 0) count++;
            }
        }
    }
    cout << count << endl;
    return count;
}

bool isOdd(int n){
    return (n % 2 == 1);
}

vector<int> oddEvenTransform(vector<int>& arr, int n){
    if(!isOdd(n)){
        cout << n << endl;
        return arr;
    }
    for(int i = 0; i < arr.size(); i++){
        if(isOdd(arr[i])) arr[i] += 3;
        else arr[i] -= 3;
    }
    for(auto& i : arr){
        cout << i << endl;
    }
    return arr;
}

vector<int> allocateCycles(vector<vector<int>> &students , vector<vector<int>> &cycles) {
    int s = students.size();
    int c = cycles.size();

	vector<vector<int>> d(s, vector<int>(c));
	vector<int> ans;

    set<int> assigned;
	
	// [[1,4,1], [1,2,1], [1,2,3]]
	for(int i = 0; i < students.size(); i++){
		for(int j = 0; j < cycles.size(); j++){
			int dis1 = abs(students[i][0] - cycles[j][0]);
			int dis2 = abs(students[i][1] - cycles[j][1]);
			 d[i][j] = dis1 + dis2;
		}
	}

	for (int i = 0; i < s; i++) {
        int minDistance = INT_MAX;
        int minCycleIndex = -1;
        for (int j = 0; j < c; j++) {
            if (d[i][j] < minDistance && assigned.find(j) == assigned.end()) {
                minDistance = d[i][j];
                minCycleIndex = j;
            }
        }
        ans.push_back(minCycleIndex);
        assigned.insert(minCycleIndex);
    }

	for(auto i: ans){
		cout << i << endl;
	}

	return ans;
}

string decodeString(string s) {
    stack<pair<int, int>> st;
    int i = 0;
    while(!s.empty()){
        if( s[i] == '[' ){
            st.push(make_pair(s[i-1] - '0' , i));
            i++;
        }
        if(s[i] == ']') {
            int cb = st.top().second, j = i - 1;
            int till = cb - 1;
            string ss = "";
            while(j > cb){
                ss += s[j];
                j--;
            }
            j = 0;
            string ans = "";
            while(j < st.top().first){
                ans += ss;
                j++;
            }
            s.replace(cb - 1, (i - till)+1, ans);
            cout << "REPLACE S: " << s << endl;
            st.pop();
        }
        i++;
    }

    cout << "Main: " << s << endl;
    return s;
}

vector<string> triangleType(const vector<string>& arr){
    vector<string> result;
    for(auto& sides: arr){
        std::stringstream ss(sides);
        vector<int> v;
        while(ss >> num){
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        int a = v[0], b = v[1], c = v[2];
    
        if (a + b <= c) {
            result.push_back("None of these");
        }
    
        if (a == b && b == c) {
            result.push_back("Equilateral");
        } 
        else if (a == b || b == c || a == c) {
            result.push_back("Isosceles");
        } 
        else {
            result.push_back("None of these");
        }
    }
    return result;
}

int main(){
    // vector<vector<int>> s = { {1,1}, {1,3}, {2,2} };
    // vector<vector<int>> c = { {1,2}, {3,3}, {2,1} };
    // cout << minFlips("101011") << endl;
    // arrayChalange(s);
    // findMinimumMoves("baabacaa");
    // findTriplets(s, 5);
    // oddEvenTransform(s, 3);
    // allocateCycles(s, c);
    decodeString("3[a2[c]]");
    return 0;
}