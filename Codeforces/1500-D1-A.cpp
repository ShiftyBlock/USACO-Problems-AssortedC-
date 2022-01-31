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
v<pii> p[10000001];
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }
    bool valid = false;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            p[arr[i]+arr[j]].emplace_back(i,j);
            if(p[arr[i]+arr[j]].size()>=2){
                set<int> temp;
                for(pii x: p[arr[i]+arr[j]]){
                    temp.emplace(x.first);
                    temp.emplace(x.second);
                }
                if(temp.size()<4) continue;
                v<int> s;
                for(auto x: temp){
                    s.emplace_back(x);
                }
                sort(s.begin(), s.end());
                while(next_permutation(s.begin(), s.end())){
                    if(arr[s[0]]+ arr[s[1]] == arr[s[2]]+ arr[s[3]]){
                        cout<<"YES"<<endl;
                        cout<<s[0]+1<<" "<<s[1]+1<<" "<<s[2]+1<<" "<<s[3]+1<<endl;
                        valid = true;
                        break;
                    }
                }
                if(valid) break;
            }
            if(valid) break;
        }
        if(valid) break;
    }
    if(!valid ) cout<<"NO"<<endl;
    return 0;
}

