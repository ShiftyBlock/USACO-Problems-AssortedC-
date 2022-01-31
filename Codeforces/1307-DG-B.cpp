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
        int N, K; cin>>N>>K;
        v<int> arr;
        bool valid=false;
        for(int i=0; i<N; i++){
            int a; cin>>a;
            arr.push_back(a);
            if(a==K){
                cout<<1<<endl;
                valid=true;
            }
        }
        if(valid) continue;
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        if(arr[0] > K){
            cout<<2<<endl;
            continue;
        }
        int moves = ceil((double)K/arr[0]);
        cout<<moves<<endl;

    }
    return 0;
}

