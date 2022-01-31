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
// N is even. Take advantage of this fact.
// Let a and b be 2 integers.
// Our goal is to turn them into -a -b
// Here is the algebra to do so
// a, b
// a+b, b
// a+b, b-(a+b) -> a+b, -a
// a+b-a, -a -> b, -a
// b-a, -a
// b-a, -a- (b-a) -> b-a, -b
// b-a-b, -b
// -a, -b

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        cout<<N/2 * 6<<endl;
        for(int i=0; i<N; i+=2){
            int j= i+2;
            cout<<1<<" "<<i+1<<" "<<j<<endl;
            cout<<2<<" "<<i+1<<" "<<j<<endl;
            cout<<1<<" "<<i+1<<" "<<j<<endl;
            cout<<1<<" "<<i+1<<" "<<j<<endl;
            cout<<2<<" "<<i+1<<" "<<j<<endl;
            cout<<1<<" "<<i+1<<" "<<j<<endl;
        }
    }
    return 0;
}

