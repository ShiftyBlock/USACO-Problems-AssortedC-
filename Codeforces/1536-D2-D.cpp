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
        set<int> s;
        int MIN=-(1<<30);
        int MAX = 1<<30;
        s.insert(arr[0]);
        bool valid = true;
        auto x = s.begin();
        for(int i=1; i<N; i++){
            if(*x == arr[i]){
                s.insert(MIN); s.insert(MAX);
                MIN--; MAX++;
                x = s.find(arr[i]);
                continue;
            }
            if(*x < arr[i]){
                x++;
                if(x==s.end()) {
                    s.insert(arr[i]);
                    s.insert(MAX);
                }
                else{
                    if(*x > arr[i]){
                        s.insert(arr[i]);
                        s.insert(MAX);

                    }
                    if(*x==arr[i]) {
                        s.insert(MAX);
                        MAX++;
                        s.insert(MAX);
                    }
                    if(*x< arr[i]){
                        valid=false;
                        break;
                    }
                }
                MAX++;
                x = s.find(arr[i]);
                continue;
            }
            if(*x > arr[i]){
                if(x==s.begin()){
                    s.insert(arr[i]);
                    s.insert(MIN);
                }
                else{
                    x--;
                    if(*x > arr[i]){
                        valid=false;
                        break;

                    }
                    if(*x==arr[i]) {
                        s.insert(MIN);
                        MIN--;
                        s.insert(MIN);
                    }
                    if(*x< arr[i]){
                        s.insert(arr[i]);
                        s.insert(MIN);
                    }
                }
                MIN--;
                x = s.find(arr[i]);
            }

        }
        if(valid){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

