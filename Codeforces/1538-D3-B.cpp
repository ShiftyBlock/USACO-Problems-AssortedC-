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
        v<int> arr;
        long sum = 0;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
            sum+=num;
        }
        sort(arr.begin(), arr.end());
        if(sum%N!=0){
            cout<<-1<<endl;
            continue;
        }
        long target = sum/N;
        int count = 0;
        for(int i=0; i<N; i++){
            if(arr[i]>target) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}

