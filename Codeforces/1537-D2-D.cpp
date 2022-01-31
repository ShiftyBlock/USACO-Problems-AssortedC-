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
int dp[100000];
v<int> primes;
void sieve(){
    for(int i=1; i<100000; i++){
        if(dp[i] == -1) continue;
        dp[i] = 1;
        for(int j=2*i; j<100000; j+=i){
            dp[j] = -1;
        }
    }
    for(int i=0; i<100000; i++){
        if(dp[i] == 1){
            primes.push_back(i);
        }
    }
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        int twos = 0;
            while(N%2==0) {
                twos++;
                N/=2;
            }


        if((twos>0 && twos%2==0) || (twos>0 && N>1)){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
    }
    return 0;
}

