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

int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr;
    v<int> bits(21);
    for(int i=0; i<N; i++){
        int num; cin>>num;
        int cnt =0;
        while(num!=0){
            bits[cnt] += num%2;
            num/=2;
            cnt++;
        }
    }
    for(int num=0; num<N; num++){
        long cur =0;
        for(int i=20; i>=0; i--){
            if(bits[i]>0){
                bits[i]--;
                cur+=pow(2, i);
            }
        }
        arr.emplace_back(cur);
    }
    long ans = 0;
    for(int i=0; i<N; i++){
        ans+=arr[i]*(long) arr[i];
    }
    cout<<ans<<endl;
    return 0;
}

