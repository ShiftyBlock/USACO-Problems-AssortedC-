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
    int tcs=1;
    cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<N; i++){
            arr.push_back(i);
        }
        for(int i=0; i<N-1; i+=2){
            swap(arr[i], arr[i+1]);
        }
        if(N%2==1){
            swap(arr[N-2], arr[N-1]);
        }
        for(int x: arr){
            cout<<x+1<<" ";
        }
        cout<<endl;

    }
    return 0;
}

