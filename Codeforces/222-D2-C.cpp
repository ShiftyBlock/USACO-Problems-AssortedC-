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
int SIEVE[4001];
v<int> primes;
void sieve(){
    for(int i=2; i<=4000; i++){
        if(SIEVE[i]==-1) continue;
        SIEVE[i] = 1;
        for(int j=2*i; j<=4000; j+=i){
            SIEVE[j] = -1;
        }
    }
    for(int i=0; i<=4000; i++){
        if(SIEVE[i]==1) primes.push_back(i);
    }
}
int main() {
    setIO("", 0);
    sieve();
    int N, M; cin>>N>>M;
    v<int> a,b;
    for(int i=0; i<N; i++){
        int num; cin>>num; a.push_back(num);
    }
    for(int i=0; i<M; i++){
        int num; cin>>num; b.push_back(num);
    }
    v<int> frq1(10000001);
    v<int> frq2(10000001);
    for(int i=0; i<N; i++){
        int temp= a[i];
        for(int p: primes){
            while(temp%p==0) {
                temp/=p;
                frq1[p]++;
            }
        }
        if(temp>1) frq1[temp]++;
    }
    for(int i=0; i<M; i++){
        int temp= b[i];
        for(int p: primes){
            while(temp%p==0) {
                temp/=p;
                frq2[p]++;
            }
        }
        if(temp>1) frq2[temp]++;
    }
    for(int i=0; i<10000001; i++){
        int mini = min(frq1[i], frq2[i]);
        frq1[i]-=mini;
        frq2[i] -= mini;
    }
    v<int> p1,p2;
    for(int i=0; i<N; i++){
        int temp = a[i];
        long ans = 1;
        for(int p: primes){
            int ct =0;
            while(temp%p==0) {
                temp/=p;
                ct++;
            }
            while(ct-->0){
                if(frq1[p]>0) ans*=p;
                else break;
                frq1[p]--;
            }
        }
        if(frq1[temp]>0) {
            ans*=temp;
            frq1[temp]--;
        }
        p1.push_back(ans);
    }
    for(int i=0; i<M; i++){
        int temp = b[i];
        long ans = 1;
        for(int p: primes){
            int ct =0;
            while(temp%p==0) {
                temp/=p;
                ct++;
            }
            while(ct-->0){
                if(frq2[p]>0) ans*=p;
                else break;
                frq2[p]--;
            }
        }
        if(frq2[temp]>0) {
            frq2[temp]--;
            ans*=temp;
        }
        p2.push_back(ans);
    }
    cout<<p1.size()<<" "<<p2.size()<<endl;
    for(int x: p1){
        cout<<x<<" ";
    }
    cout<<endl;
    for(int x: p2){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}

