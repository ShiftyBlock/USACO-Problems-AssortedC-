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
int arr[32];
int main() {
    setIO("", 0);
    v<long> p2;
    long num = 1;
    while(num<=1e11){
        p2.push_back(num);
        num*=2;
    }
    int tcs; cin>>tcs;
    while(tcs-->0){
        //iterate through a and try to add largest power of 2
        long a,b; cin>>a>>b;
        memset(arr, 0, 32);
        v<int> B(32);
        for(int k=0; k<300; k++){
            long ta= a;
            for(int i=31; i>=0; i--){
                if(ta>= p2[i]) {
                    ta-= p2[i];
                    arr[i] = 1;
                }
            }
            for(int i=31; i>=0; i--){
                if(arr[i]==1 && a+p2[i] <= b) {
                    a+= p2[i];
                    break;
                }
            }
            for(int i=0; i<32; i++){
                arr[i] = 0;
            }
        }
        if(a==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}

