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
        v<int> arr;
        for(int i=N-1; i>=0; i--){
            arr.push_back(i+1);
        }
        if(N%2==1){
            int temp = arr[N/2];
            arr[N/2] = arr[N-1];
            arr[N-1] = temp;
        }
        for(int num: arr){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}

