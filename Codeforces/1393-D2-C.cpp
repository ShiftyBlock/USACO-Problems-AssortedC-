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
        v<int> ct(N+1);
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
            ct[num]++;
        }
        int mx = 0;
        for(int i=0; i<=N; i++){
            mx = max(mx, ct[i]);
        }
        int count = 0;
        for(int i=0; i<=N; i++){
            if(ct[i]==mx) count++;
        }
        //ignore duplicates
        N-=mx*count;
        N/=mx-1;
        N+=count-1;
        cout<<N<<endl;

    }
    return 0;
}

