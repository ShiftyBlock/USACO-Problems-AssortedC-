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
        for(int i=0; i<N; i++){
            int num; cin>>num;
            arr.push_back(num);
        }
        int M; cin>>M;
        v<int> arr2;
        for(int i=0; i<M; i++){
            int num; cin>>num;
            arr2.push_back(num);
        }
        int prefix = 0;
        int best = 0;
        for(int i=0; i<N; i++){
            prefix+=arr[i];
            best = max(best, prefix);
        }
        int prefix2 = 0;
        int best2 = 0;
        for(int i=0; i<M; i++){
            prefix2+=arr2[i];
            best2 = max(best2, prefix2);
        }
        cout<<best+best2<<endl;
    }
    return 0;
}

