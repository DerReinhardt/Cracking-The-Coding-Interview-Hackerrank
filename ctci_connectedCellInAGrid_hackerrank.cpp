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


void mark(vector< vector<int> >  & grid, int i, int j, int n, int m, int & count){
  if(i < 0 || j < 0 || i >= n || j >= m) return;
  if(grid[i][j]){
    count++;
    grid[i][j] = 0;
    mark(grid, i - 1, j - 1, n, m, count);
    mark(grid, i - 1, j, n, m, count);
    mark(grid, i - 1, j + 1, n, m, count);
    mark(grid, i, j + 1, n, m, count);
    mark(grid, i + 1, j + 1, n, m, count);
    mark(grid, i + 1, j, n, m, count);
    mark(grid, i + 1, j - 1, n, m, count);
    mark(grid, i, j - 1, n, m, count);
  }  
}


int get_biggest_region(vector< vector<int> >  & grid, int n, int m) {
  int maxCount = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j]){
        int count = 0;
        mark(grid, i, j, n, m, count);
        maxCount = max(maxCount, count);
      }      
    }
  }
  return maxCount;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid, n, m) << endl;
    return 0;
}
