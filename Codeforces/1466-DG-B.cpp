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
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        set<int> s;
        s.emplace(arr[0]+1);
        for(int i=1; i<N; i++){
            if(s.find(arr[i]+1)==s.end()){
                s.emplace(arr[i]+1);
            }
            else if(s.find(arr[i])==s.end()) s.emplace(arr[i]);
        }
        s.erase(0);
       /* for(int x: s){
            cout<<x<<" ";
        }
        cout<<endl;*/
        cout<<s.size()<<endl;

    }
    return 0;
}

