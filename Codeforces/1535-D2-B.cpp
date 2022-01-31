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
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> even, odd;
        for(int i=0; i<N; i++){
            int num; cin>>num;
            if(num%2==0) even.push_back(num);
            else odd.push_back(num);
        }
        v<int>arr;
        for(int num: even){
            arr.push_back(num);
        }
        for(int num: odd){
            arr.push_back(num);
        }
        int p=0;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(__gcd(arr[i], 2*arr[j])>1)p++;
            }
        }
        cout<<p<<endl;
    }
    return 0;
}

