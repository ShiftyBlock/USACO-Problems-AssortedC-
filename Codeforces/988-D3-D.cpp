/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
#define long long long
#define v vector
#define endl "\n"

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
    v<int> arr;
    set<int> s;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
        s.emplace(num);
    }
    //adjacent elements in set must have same difference of a power of 2
    // and only size 3 or 2
    sort(arr.begin(), arr.end());
    long curpow = 1;
    int best = 1;
    v<int> ans;
    while (curpow< 2*1e9){
        for(int i=0; i<N; i++){
            if(s.find(arr[i]+curpow) != s.end()){
                if(s.find(arr[i]+curpow*2) != s.end()){
                    cout<<3<<endl;
                    cout<<arr[i]<<" "<<arr[i]+curpow<<" "<<arr[i]+curpow*2<<endl;
                    return 0;
                }
                else{
                    if(best<2){
                        best = 2;
                        ans.push_back(arr[i]);
                        ans.push_back(arr[i]+curpow);
                    }
                }
            }
        }
        curpow*=2;
    }
    if(best == 2){
        cout<<best<<endl;
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    if(best==1){
        cout<<best<<endl;
        cout<<arr[0]<<endl;
    }
    return 0;
}

