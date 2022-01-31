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
int dp[(int)1e7+1];
v<int> primes;
void sieve(){
    int N = 1e7;
    for(int i=2; i<=sqrt(N)+1; i++){
        if(dp[i]!=0) continue;
        dp[i] = 1;
        for(int j=i*2; j<=sqrt(N)+1; j+=i){
            dp[j] = -1;
        }
    }
    for(int i=0;i <=N; i++){
        if(dp[i]==1){
            primes.push_back(i);
        }
    }

}
int main() {
    setIO("", 0);
    sieve();
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, K; cin>>N>>K;
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            int newnum=1;
            for(int j=0; j<primes.size(); j++){
                int count =0;
                while(num%primes[j]==0){
                    num/=primes[j];
                    count++;
                }
                if(count%2==1) newnum*=primes[j];
            }
            newnum*=num;
            arr.push_back(newnum);
        }
        map<int, int> m;
        int ans=1;
        for(int i=0; i<N; i++){
            if(m.find(arr[i])==m.end()){
                m.emplace(arr[i], 1);
            }
            else{
                ans++; m.clear();  m.emplace(arr[i], 1);
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}

