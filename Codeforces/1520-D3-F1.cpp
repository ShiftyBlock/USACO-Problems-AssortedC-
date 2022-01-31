/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define long long long
#define v vector

int main() {
    int N, T; cin>>N>>T;
    while(T-->0){
        int K; cin>>K;
        int low = 1;
        int high = N;
        int total =0; cin>>total;
        //binary search
        int curk = 0;
        while(curk!=K && low<high){
            int mid = (low+high)/2;
            cout<<"? "<<low<<" "<<mid<<endl;
            int sum; cin>>sum;
            if((mid-low+1)-sum  +curk >=K){
                high = mid;
            }
            else{
                curk += (mid-low+1)- sum;
                low = mid+1;
            }
        }
        cout<<"! "<<low<<endl;
    }
    return 0;
}

