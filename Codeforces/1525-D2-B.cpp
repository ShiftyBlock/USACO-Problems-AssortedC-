/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define endl "\n"
#define long long long
#define v vector

long MOD = 1e9+7;

void setIO(string name, int submit) {
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }

}

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
       int N; cin>>N;
       v<int> arr;
        v<int> sorted;
       for(int i=0; i<N; i++){
           int num; cin>>num; arr.push_back(num);
           sorted.push_back(num);
       }
       sort(arr.begin(), arr.end());
       bool valid = true;
       for(int i=0; i<N; i++){
           if(sorted[i] != arr[i]) valid = false;
       }
       if(valid){
           cout<<0<<endl;
           continue;
       }
       if((sorted[0] == arr[0]) || (sorted[N-1]== arr[N-1])){
           cout<<1<<endl;
           continue;
       }
       if((sorted[0] == arr[N-1]) && (sorted[N-1]== arr[0])){
           cout<<3<<endl;
           continue;
       }
       cout<<2<<endl;
    }
    return 0;
}

