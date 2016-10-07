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

bool isPrime(int n){	
	if(n == 1) return false;
	if(n <= 3) return true;
	int limit = sqrt(n);
	for(int i = 2; i <= limit; i++){
		if(!(n % i)) return false;
	}

	return true;
}

int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        cout << (isPrime(n) ? "Prime" : "Not prime") << endl;
    }
    return 0;
}
