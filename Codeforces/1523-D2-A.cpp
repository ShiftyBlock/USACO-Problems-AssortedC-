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
        int N, M; cin>>N>>M;
        v<int> arr;
        for(int i=0; i<N; i++){
            char c; cin>>c;
             arr.push_back(c-'0');
        }
        v<int> left, right;
        int last = -(1<<30);
        for(int i=0; i<N; i++){
            if(arr[i]==1) last = i;
            left.push_back(i-last);
        }
        last = 1<<30;
        for(int i=N-1; i>=0; i--){
            if(arr[i]==1) last = i;
            right.push_back(last-i);
        }
        reverse(right.begin(), right.end());
        for(int i=0; i<N; i++){
            if((M>=left[i] || M>=right[i]) && left[i]!=right[i]) arr[i] = 1;
        }
        for(int i=0; i<N; i++){
            cout<<arr[i];
        }
        cout<<endl;


    }

    return 0;
}

