// Stack follows LIFO approch: `Last in First Out`
#include <iostream> 
#include <stack>
#include <vector>
using namespace std;

vector<int> slice(const vector<int>& arr, int x, int y){
    auto start = arr.begin() + x;
    auto end = arr.begin() + y;
    return vector<int>(start, end);
}

vector<int> merge(const vector<int>& ls, vector<int>& rs){
    int i = 0, j = 0;
    vector<int> res;
    res.reserve(l.size() + r.size());
    while(i < ls.size() && j < rs.size()){
        if(ls[i] < rs[j]){
            res.push_back(ls[i]);
            i++;
        }
        else{
            res.push_back(rs[j]);
            j++;
        }
    }
    res.insert(res.end(), l.begin() + i, l.end());
    res.insert(res.end(), r.begin() + j, r.end());
    return res;
}

vector<int> mergeSort(const vector<int>& arr) {
    int size = arr.size();

    if(size <= 1){
        return arr;
    }

    int mid = size / 2;

    vector<int> l = slice(arr, 0, mid);
    vector<int> r = slice(arr, mid, size);

    vector<int> ls = mergeSort(l);
    vector<int> rs = mergeSort(r);

    return merge(ls, rs);
}

vector<int> mergeSortEff(vector<int>& nums, int s, int e) {
    int n = s + e;
    if(n < 2) return vector<int>(nums.begin() + start, nums.begin() + end);
    int m = s / 2;
    vector<int> ls = mergeSortEff(nums, 0, m);
    vector<int> rs = mergeSortEff(nums, m, s);
    return merge(ls, rs);
}

int main(){
    vector<int> v = {3,4,1,6,9,2,5,8,1,2,4};
    cout << "SORTED VECTOR WITH MERGE SORT: " << endl;
    vector<int> sortedArr = mergeSort(v);
    for(int num : sortedArr) {
        cout << num << " ";
    }
    return 0;
}