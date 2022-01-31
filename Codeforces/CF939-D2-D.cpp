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
struct djset{
    int N;v<int> arr;
    djset(int n){
        N=n;
        for(int i=0; i<N; i++){
            arr.emplace_back(i);
        }
    }
    int find(int cur){
        if(arr[cur]==cur){
            return cur;
        }
        int myp=find(arr[cur]);
        arr[cur]=myp;
        return myp;
    }
    bool merge(int a, int b){
        int ap=find(a);
        int bp= find(b);
        if(ap==bp) return false;
        arr[ap]=bp;
        return true;
    }

};
int main() {
    setIO("", 0);
    int N; cin>>N;
    djset dj=djset(1000);
    string a,b; cin>>a>>b;
    v<pii> merges;
    for(int i=0; i<N; i++){
        if(dj.merge(a[i], b[i])){
            merges.emplace_back(a[i], b[i]);
        }
    }
    cout<<merges.size()<<endl;
    for(int i=0; i<merges.size(); i++){
        cout<<(char) merges[i].first<<" "<<(char) merges[i].second<<endl;
    }
    return 0;
}

