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
bool valid(int N, v<int> arr){
    int K = 2*N;
    bool val = true;
    for(int i=0; i<K; i++){
        if(arr[i] == (arr[(i+1)%K] + arr[(i-1+K)%K])/2) {
            val=false;
        }
    }
    return val;
}
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        for(int i=0; i<2*N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int i=0; int j=2*N-1;
        int turn =0;
        while(i!=j){
            if(turn==0) {
                cout<<arr[i]<<" ";
                i++;
            }
            if(turn==1){
                cout<<arr[j]<<" ";
                j--;
            }
            turn++;
            turn%=2;
        }
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}

