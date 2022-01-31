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
int temp[71];
v<int> primes;
void sieve(){
    for(int i=2; i<=70; i++){
        if(temp[i]==-1) continue;
        temp[i] = 1;
        for(int j=2*i; j<=70; j+=i){
            temp[j]=-1;
        }
    }
    for(int i=2; i<=70; i++){
        if(temp[i]==1) primes.push_back(i);
    }
};
long modpow(long a, long b){
    long ans = 1;
    while(b>0){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
        a%=MOD;
        ans%=MOD;
    }
    return ans;
}
//eddy is a scammer
long dp[2][1<<19];
int main() {
    setIO("", 0);
    sieve();
    int N; cin>>N;
    v<int> arr;
    v<int> frq(71);
    for(int i=0; i<N; i++){
        int num; cin>>num;
        frq[num]++;
        arr.push_back(num);
    }
    //sort(arr.begin(), arr.end());
    v<int> bits(71);
    for(int i=0; i<N; i++){
        int num= arr[i];
        int bit = 0;
        for(int j=0; j<primes.size(); j++){
            int ct = 0;
            while(num%primes[j]==0) {
                num/=primes[j];
                ct++;
            }
            if(ct%2==1) bit+=1<<j;
        }
        bits[arr[i]]=(bit);
    }
    v<long> pows;
    for(int i=0; i<=100000; i++){
        pows.push_back(modpow(2, i));
    }
    dp[0][0] = 1;
    for(int i=0 ;i<=70; i++){
        for(int mask=0; mask<1<<19; mask++){
            int bit = bits[i];
            int idx = (i+1)%2;
            int ix = i%2;
            if(frq[i]==0){
                dp[idx][mask]+=dp[ix][mask];
            }
            else{
                long m = pows[frq[i]-1];
                dp[idx][mask^bit] += m* dp[ix][mask];
                dp[idx][mask]+=m* dp[ix][mask];
            }
            dp[idx][mask]%=MOD;
            dp[idx][mask^bit]%=MOD;
        }
        for(int mask=0; mask<1<<19; mask++){
            dp[i%2][mask] = 0;
        }
    }
    cout<<dp[1][0]-1<<endl;
    return 0;
}

