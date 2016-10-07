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

int countWays(int n){
	const vector<int> steps = {1, 2, 3};
	vector<int> ways(n + 1, 0);
	ways[0] = 1;

	for(int i = 0; i < n ; i++){
		for(auto step : steps){
			if(i + step <= n){
				ways[i + step] += ways[i];
			}
		}
	}
	
	return ways[n];
}


int main(){
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout << countWays(n) << endl;
    }    
    return 0;
}
