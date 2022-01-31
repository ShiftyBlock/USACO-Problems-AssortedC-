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
int sieve[100000];
int main() {
    setIO("", 0);
    // set up sieve to get all of the prime numbers from 1... sqrt(1e9)
    v<int> primes;
    sieve[0]=1;
    sieve[1]=1;
    for(int i=2; i<=sqrt(1e9); i++){
        if(sieve[i]==-1) continue;
        sieve[i]=0;
        primes.push_back(i);
        for(int j=i*2; j<100000; j+=i){
            sieve[i]=-1;
        }
    }
    int Q; cin>>Q;
    while(Q-->0){
        int L,R; cin>>L>>R;
        int up=sqrt(R);

        for(int m=L; m<=R; m++){
            bool isprime=true;
            if(m==1) continue;
            int idx=0;
            while(idx<primes.size() && primes[idx]<=sqrt(m)){
                isprime&= (m%primes[idx]!=0);
                if(!isprime) break;
                idx++;
            }
            if(isprime){
                cout<<m<<endl;
            }
        }
        cout<<endl;

    }

    return 0;
}

