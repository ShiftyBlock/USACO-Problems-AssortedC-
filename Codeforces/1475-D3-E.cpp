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
#define MOD 1000000007LL

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
long modpow(int n, int k, long M){
    v<long> mult(32);
    v<long> pow2(32);
    mult[0]=1;
    mult[1] = n;
    pow2[0] = 0;
    pow2[1] = 1;
    for(int i=2; i<32; i++){
        mult[i] = mult[i-1] * mult[i-1];
        mult[i] %=M;
        pow2[i] = pow2[i-1] *2;
    }
    int i=31;
    long ans=1;
    while(k>0){
        if(pow2[i]>k) {
            i--;
            continue;
        }
        k-=pow2[i];
        ans*=mult[i];
        i--;
        ans%=M;
    }
    return ans;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, K; cin>>N>>K;
        v<int> arr;
        v<int> freq(N);
        for(int i=0; i<N; i++){
            int num;  cin>>num;num--;
            arr.push_back(num);
            freq[num]++;
        }
        sort(arr.begin(), arr.end());
        v<int> freqT(N);
        for(int i=N-1; i>N-1-K; i--){
            freqT[arr[i]]++;
        }
        /*for(int i=0; i<N; i++){
            cout<<freqT[i]<<" ";
        }
        cout<<endl;*/
        long ans=1;
        for(int i=0; i<N; i++){
            //choose for each
            if(freq[i]==0 || freqT[i]==0) continue;
            long temp=1;
            for(int j=freqT[i]+1; j<=freq[i]; j++){
                temp*=j;
                temp%=MOD;
            }
            long inverse=1;
            for(int j=2; j<=freq[i] - freqT[i]; j++){
                inverse *= modpow(j, MOD-2, MOD);
                inverse%=MOD;
            }
            ans*=temp*inverse;
            ans%=MOD;
        }
        ans%=MOD;
        cout<<ans<<endl;
    }

    return 0;
}

