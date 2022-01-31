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
int sieve[500001];
v<int> primes;
void generate_primes(){
    sieve[0] = -1;
    sieve[1] = -1;
    for(int i=2; i<=200001; i++){
        if(sieve[i]==-1) continue;
        sieve[i] = 1;
        for(int j=i*2; j<=200001; j+=i){
            sieve[j] = -1;
        }
    }

    for(int i=0; i<200001; i++){
        if(sieve[i] == 1) primes.push_back(i);
    }
}

int main() {
    setIO("", 0);
    int N; cin>>N;
    generate_primes();
    v<int> arr(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    long ans=1;
    sort(arr.begin(), arr.end());
    for(int num:primes){
        long cur = num;
        bool kill = false;
        while(!kill){
            bool valid=true;
            for(int i=0; i<N; i++){
                if(arr[i]%cur !=0){
                    if(valid == false){
                        kill=true;
                        break;
                    }
                    valid=false;
                }
            }
            if(kill) break;
            cur*=num;
        }
        cur/=num;
        ans*=cur;
    }
    cout<<ans<<endl;
    return 0;
}

