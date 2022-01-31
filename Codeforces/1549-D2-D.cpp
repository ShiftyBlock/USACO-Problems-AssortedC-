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
        v<long> arr;
        for(int i=0; i<N; i++){
            long x; cin>>x;
            arr.push_back(x);
        }
        v<long> neg(N);
        for(int i=1; i<N; i++){
            neg[i] = abs(arr[i]- arr[i-1]);
        }
        int ans = 0;
        for(int i=1; i<N;){
            if(neg[i]==1) {
                i++; continue;
            }
            int j=i+1;
            long cur = neg[i];
            if(j<N){
                cur =__gcd(cur, neg[j]);
                while(j<N && __gcd(cur, neg[j])>1){
                    j++;
                    cur = __gcd(cur, neg[j]);
                }
                ans = max(ans, j-i);
                i=j;
            }
            else{
                ans = max(ans, 1);
                i=j;
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}

