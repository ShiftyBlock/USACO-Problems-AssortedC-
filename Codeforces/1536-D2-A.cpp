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
        set<int> s;
        bool negative = false;
        for(int i=0; i<N; i++){
            int n; cin>>n;
            arr.push_back(n);
            s.emplace(n);
            if(n<0) negative=true;
        }
        if(negative) {
            cout<<"NO"<<endl;
            continue;
        }
        while(true){
            if(s.size()>300) break;
            for(int i=0; i<arr.size(); i++){
                for(int j=0; j<arr.size(); j++){
                    if(arr[i]==arr[j]) continue;
                    s.emplace(abs(arr[i]- arr[j]));
                }
            }
            if(arr.size()==s.size()) break;
            arr.clear();
            for(int x: s){
                arr.push_back(x);
            }
        }

        if(s.size()<=300){
            cout<<"YES"<<endl;
            cout<<s.size()<<endl;
            for(int x: s){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

