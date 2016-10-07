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
O(n) space
O(nlogn) time
The idea is to keep track of the median by keeping the array kinda sorted between two heaps:
One max heap for the smaller elements, and a min heap for the greater ones.
The median will be between the two roots since the biggest of the smallest and the smallest of the biggest
meet at the half of the sorted array. ZOMG.
Depending on how the new element is compared against the roots we should push.
If the element is smaller than the left heap it means that the median might move to the right because of ther new insertion,
so depending on how balanced the heaps are we should move the root of the left heap or just insert
The tricky part is the balance. If both heaps have the same length in means that the median is the average of both roots since
we sould have an even number of total elements. If it is not balanced the median will be the left root since that is where the mid element
is.
*/



bool mycompare(const int & a, const int & b){
	return b < a;
}

void moveToHeap(vector<int> & hMax, vector<int> & hMin, bool toRight){ 	// move the root of one heap to another. The bool variable determines to which
	if(toRight){
		hMin.push_back(hMax.front());
    	std::push_heap(hMin.begin(), hMin.end(), mycompare);
    	std::pop_heap(hMax.begin(), hMax.end());
    	hMax.pop_back();
	}
	else{
		hMax.push_back(hMin.front());
       	std::push_heap(hMax.begin(), hMax.end());
       	std::pop_heap(hMin.begin(), hMin.end(), mycompare);
       	hMin.pop_back();
	}
	
}

void pushHeap(int x, vector<int> & h, bool max){	// push x into a heap. The bool variable determines which
	h.push_back(x);
	if(max){
		std::push_heap(h.begin(), h.end());
	}
	else{
		std::push_heap(h.begin(), h.end(), mycompare);
	}    
}


int main(){
    int n;
    cin >> n;    

    vector<int> hMax;
    vector<int> hMin;    

    for(int a_i = 0;a_i < n;a_i++){
    	int x;
       cin >> x;       

       bool balanced = hMax.size() == hMin.size();

       if(!hMax.size()){ // left empty
       		pushHeap(x, hMax, 1);
       }

       else if(!hMin.size()){	//right empty
       		if(x > hMax.front()){	// x > left
       			pushHeap(x, hMin, 0); //push right
       		}
       		else{	// x < left
       			moveToHeap(hMax, hMin, 1);	// move to right
       			pushHeap(x, hMax, 1);	// push left
       		}

       }

       else if(x <= hMax.front()){	// should go left side
       		if(!balanced){
       			moveToHeap(hMax, hMin, 1);	// move to right
       		}       		
       		pushHeap(x, hMax, 1);	// push left       			    		
       }

       else if(x >= hMin.front()){ // should go right side
       		if(balanced){
       			moveToHeap(hMax, hMin, 0);	// move to left       			
       		}
       		pushHeap(x, hMin, 0); //push right       		
       }

       else{	// is between both heaps
       		if(balanced){
       			pushHeap(x, hMax, 1);	// push left
       		}
       		else{
       			pushHeap(x, hMin, 0); //push right
       		}
       }      

       float res;
       
       if(balanced){
       		res = hMax.front();
       }
       else{
       		res = (hMin.front() - hMax.front()) * 0.5 + hMax.front();
       }

       printf("%.1f\n", res);

    }    

    return 0;
}
