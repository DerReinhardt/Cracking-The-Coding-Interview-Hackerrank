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

/*
The DP solution is based on the idea of using previous calculations. 
Each row represents a combination of coins. The first row represents using only the first coin of the set.
The second row represents using and not using the second coin, hence it includes the previous row for the "not using"
The columns represent an amount of money.
So, A[i][j] means the possible ways to represent the money j by using the combinations up until i.
For the withThisCurrency variable we have to check that the variable j is >= the current coin because
we cannot use a bigger coin for a smaller quantity. If the amount is bigger we then use coins[i] rows back. This is
the way of calculating the j's that are divisible by that coin. If you look closely, each i coin will be filling
the next i column with the value of 1, meaning that you need only that 1 coin to represent that amount of money.
The withoutThisCurrency variable uses the previous calculated values for all the rows except the first one.
O(nm) space
O(nm) time
*/
long long make_change(vector<int> coins, int money) {
    vector<vector<long long>> A(coins.size(), vector<long long>(money + 1));

    for(long long i = 0; i < A.size(); i++){
    	A[i][0] = 1; // only one way to make zero money
    	for(long long j = 1; j < A[i].size(); j++){
    		long long withoutThisCurrency = (i > 0 ? A[i - 1][j] : 0); // meaning, use the value calculated on the previous row for this $j money
    		long long withThisCurrency = (j >= coins[i] ? A[i][j - coins[i]] : 0);
    		A[i][j] = withoutThisCurrency + withThisCurrency;
    	}
    }

    return A[A.size() - 1][money];

}

/*
O(m) space
O(nm) time
*/
long long make_change2(vector<int> coins, int money) {
    long long ways[money + 1] = {0}; ways[0] = 1;
    for (auto c: coins) {
        for (auto i = c; i<= money; ++ i) {
            ways[i] += ways[i - c];
        }
    }
    return ways[money];
}


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }
    cout << make_change(coins, n) << endl;
    return 0;
}
