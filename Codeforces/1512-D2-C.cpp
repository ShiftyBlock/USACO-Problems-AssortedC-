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
        int ct =0;
        long take = 1;
        v<long> arr;
        for(int i=1; i<N; i++){
            if(__gcd(i, N)==1){
                ct++;
                take*=i;
                take%=N;
                arr.push_back(take);
            }
        }
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i]%N==1){
                ct=i+1;
                break;
            }
        }
        cout<<ct<<endl;
        for(int i=1; i<N; i++){
            if(ct==0) break;
            if(__gcd(i, N)==1){
                cout<<i<<" ";
                ct--;
            }
        }
    return 0;
}

