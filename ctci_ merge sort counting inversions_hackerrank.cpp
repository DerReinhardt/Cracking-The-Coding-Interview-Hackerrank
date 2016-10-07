#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> mergeSort(vector<int> & v, long long begin, long long end, long long & count) {
    vector<int> merged;
    if(v.size() == 1 || begin >= end) return {v[begin]};
    long long mid = (end - begin) / 2 + begin;
    vector<int> left = mergeSort(v, begin, mid, count);
    vector<int> right = mergeSort(v, mid + 1, end, count);
    
    int i = 0, j = 0, idx = 0;
    int n = left.size(), m = right.size();
    merged.resize(n + m);

    while(i < n && j < m){
        int val;
        if(right[j] < left[i]){ // must we swap?
            count += n + j - idx;   // this is the key: count how many spaces from the right you are moving to the new position to the left in the new array
            val = right[j++];
        }
        else{
            val = left[i++];
        }
        merged[idx++] = val;
    }

    while(i < n){
        merged[idx++] = left[i++];
    }

    while(j < m){
        merged[idx++] = right[j++];
    }

    return merged;  
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        long long count = 0;
        mergeSort(arr, 0, arr.size() - 1, count);
        cout << count << endl;
    }
    return 0;
}
