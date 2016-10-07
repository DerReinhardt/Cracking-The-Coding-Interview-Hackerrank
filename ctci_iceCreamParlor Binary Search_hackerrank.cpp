#include <bits/stdc++.h>
using namespace std;

class IceCream {
    
    public: 
        int flavor; 
        int index;

        IceCream(int flavor, int index) {
            this -> flavor = flavor;
            this -> index = index;
       }
};

bool mycompare(const IceCream & ic1, const IceCream & ic2){
    return ic2.flavor < ic1.flavor;
}
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {   
   while(first <= last){
        cout << first << " " << last << endl;
        int m = (last - first) / 2 + first;
        cout << m << endl;
        auto ice = arr[m];
        if(ice.flavor == search){
            cout << "found at " << m << endl;
            return ice.index;
        }
        else if(ice.flavor < search){
            first = m + 1;
        }
        else{
            last = m - 1;
        }
   }
   return -1;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i));
        }

        sort(arr.begin(), arr.end(), mycompare);        
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << (min(arr[i].index, index) + 1) << " " << (max(arr[i].index, index) + 1) << endl;
                    break;

                }
            }
        }

    }

}

