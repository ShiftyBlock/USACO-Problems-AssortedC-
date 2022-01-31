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
v<int> primes;
void generatePrimes(int n){
    v<bool> prime(n+1);
    for(int i=0; i<n; i++){
        prime[i] = true;
    }
    for(long i=2; i*i<=n; i++){
        if(prime[i]){
            for(long j=i*2; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }
    for(int i=2; i<n+1; i++){
        if(prime[i]) primes.push_back(i);
    }
}

int main() {
    setIO("", 0);
    generatePrimes(100010);

    int tcs; cin>>tcs;
    while(tcs-->0) {
        long N;
        cin >> N;
        v<long> leftover(primes.size());
        int best = -1;
        int besti = -1;
        for (int i =0; i<primes.size(); i++) {
            int num = primes[i];
            long temp = N;
            int moves = 1;
            while (temp % num == 0 && (temp / num)%num == 0 ) {
                temp /= num;
                moves++;
            }
            leftover[i] = temp;
            if(moves>best){
                best = moves;
                besti= i;
            }
        }
        cout<<best<<endl;
        for(int i=0; i<best-1; i++){
            cout<<primes[besti]<<" ";
        }
        cout<<leftover[besti]<<endl;
    }

    return 0;
}

