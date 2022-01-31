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
const int MAXN= 2000001;
int sieve[MAXN];
int main() {
    setIO("", 0);
    // Our goal is to find non prime factors
    // to do this, we will first calculate a sieve
    // the sieve will store the smallest prime factor for a given i
    sieve[0]=0;
    sieve[1]=1;
    for(int i=2; i<=sqrt(MAXN); i++){
        if(sieve[i]!=0) continue;
        sieve[i]=i;
        for(int j=i*2; j<MAXN; j+=i){
            if(sieve[j]==0) sieve[j]=i;
        }
    }
    for(int i=2; i<MAXN; i++){
        if(sieve[i]==0) sieve[i]=i;
    }
    //now that we have finished finding the smallest prime factor
    // all we need to do is calculate the following
    // 1. the number of different primes
    // 2. the count of each different prime
    // 3. Since you can rearrange a prime factorization in Π(x+1) where x is the exponent in a^x
    // We do x+1 because you have to include the number 1
    map<int, int> count;
    int Q; cin>>Q;
    while(Q-->0){
        int X; cin>>X;
        while(X!=1){
            int factor = sieve[X];
            if(count.find(factor)!=count.end()) {
                count[factor]++;
            }
            else count.emplace(factor, 1);
            X/=factor;
        }
        long primes=0;
        long nonprimes=1;
        for(auto item: count){
            int value= item.second;
            primes++;
            nonprimes*=(value+1);
        }
        cout<<nonprimes-primes<<endl;
        count.clear();
    }

    return 0;
}

