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
v<int> primes;
int sieve[(int)1e5+5];
void init(){
    int N = 1e5;
    for(int i=2; i<=N; i++){
        if(sieve[i]==-1) continue;
        sieve[i] = 1;
        for(int j=2*i; j<=N; j+=i){
            sieve[j] = -1;
        }
    }
    for(int i=0; i<=1000; i++){
        if(sieve[i]==1) primes.push_back(i);
    }
}
int main() {
    //special case for 1s
    setIO("", 0);
    init();
    int N, K; cin>>N>>K;
    v<int> arr;
    map<string, int> m;
    long sum = 0;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
        string hash="";
        string antihash="";
        for(int j=0; j<primes.size();j++){
            int ct =0;
            while(num%primes[j]==0){
                num/=primes[j];
                ct++;
            }
            ct%=K;
            if(ct==0)continue;
            string key1 = to_string(primes[j])+":"+to_string(ct)+";";
            string key2 = to_string(primes[j])+":"+to_string(K-ct)+';';
            antihash+= key1;
            hash+=key2;
        }
        if(num!=1){
            antihash+= to_string(num)+":"+to_string(1);
            hash+=to_string(num)+":"+to_string(K-1);
        }
       /* cout<<antihash<<endl;
        cout<<hash<<endl;
        cout<<"index: "<<i<<endl;*/
        //cout<<hash<<" "<<antihash<<" "<<endl;
        if(m.find(antihash)!=m.end()){
            sum+=m[antihash];
        }
        m[hash]++;
    }
    /*
     * oops we count 1
    for(int i=0; i<N; i++){
        if(arr[i]==1){
            if(m.find(1)!=m.end()){
                sum+=m[1];
            }
        }
    }*/
    cout<<sum<<endl;


    return 0;
}

