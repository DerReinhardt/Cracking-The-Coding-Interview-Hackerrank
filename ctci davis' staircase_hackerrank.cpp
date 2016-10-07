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

/* DP: From the position i that you are on, use the steps to jump ahead and count the accumulated steps.
There is only one way to jump from position 0, hence ways[0] = 1
From the position 0 jump to 0 + 1 and add the 1 from position 0 to the position 0 + 1. Repeat for steps 2, and 3.
Now, from the position 1 you will have accumulated the ways from the previous position which is 0. Count the jumps ahead too.
It is easy to see that from the i-th position we will have accumulated all the ways previous to i, and from i we can accumulate for
the steps ahead.
*/

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
