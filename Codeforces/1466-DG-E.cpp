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
            long num; cin>>num; arr.push_back(num);
        }
        v<long> p2;
        long cur2 =1;
        p2.push_back(cur2);
        while(cur2<=(1LL<<60)){
            cur2*=2;
            p2.push_back(cur2);
        }
        v<int> bits(61);
        for(int i=0; i<N; i++){
            long cur  = arr[i];
            for(int j=60;j>=0; j--){
                if(p2[j] <= cur){
                    cur-= p2[j];
                    bits[j]++;
                }
            }
        }
        long ans = 0;
        for(int j=0; j<N; j++){
            long isum = 0;
            for(int i=60; i>=0; i--){
                if(((1LL<<i) & arr[j])>=1){
                    isum+=p2[i]%MOD * bits[i]%MOD;
                    isum%=MOD;
                }
            }
            long ksum = 0 ;
            for(int i=60; i>=0; i--){
                if(((1LL<<i) & arr[j])>=1){
                    ksum+=p2[i]%MOD * N%MOD;
                    ksum%=MOD;
                }
                else{
                    ksum+=p2[i]%MOD * bits[i]%MOD;
                    ksum%=MOD;
                }
            }
            ans+=(isum*ksum)%MOD;
            ans%=MOD;
        }
        ans%=MOD;
        cout<<ans<<endl;
    }
    return 0;
}

