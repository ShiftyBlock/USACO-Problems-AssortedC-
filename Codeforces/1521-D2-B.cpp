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
        for(int i=0; i<N; i++){
            int num; cin>>num;arr.push_back(num);
        }
        cout<<N-1<<endl;
        v<int> roll; roll.push_back(1000000009);roll.push_back(1000000007);
        for(int i=0; i<N-1; i++){
            cout<<i+1<<" "<<i+2<<" "<<roll[i%2]<<" "<<min(arr[i], arr[i+1])<<endl;
            arr[i+1] = min(arr[i], arr[i+1]);
        }
    }
    return 0;
}

