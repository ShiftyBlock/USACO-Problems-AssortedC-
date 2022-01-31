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
struct segtree{
    int N; v<int> arr;
    segtree(int n){
        N=n;
        arr.assign(4*N, 0);
    }
    void update(int i, int val){
        update(i,val,0,0,N);
    }
    void update(int i, int val, int cur, int lx, int rx){
        if(rx-lx==1){
            arr[cur]=val;
            return;
        }
        int mid = (lx+rx)/2;
        if(mid>i){
            update(i, val, cur*2+1, lx, mid);
        }
        else{
            update(i, val, cur*2+2, mid, rx);
        }
        arr[cur]= arr[2*cur+1]+ arr[2*cur+2];
    }
    int sum(int l, int r){
        return sum(l,r,0,0,N);
    }
    int sum(int l, int r, int cur, int lx, int rx){
        if(rx<=l || lx>=r) return 0;
        if(lx>=l && rx<=r){
            return arr[cur];
        }
        int mid = (lx+rx)/2;
        return sum(l,r, 2*cur+1, lx, mid) + sum(l,r,2*cur+2, mid, rx);
    }
};
//idea
//process in descending order
// query the numbers to the right
// the query is a sum
// from (index, N)
int main() {
    setIO("", 0);
    int N; cin>>N;
    segtree st(N);
    v<int> arr(N);
    v<pii> process;
    for(int i=0; i<N; i++){
        int num; cin>>num;
        arr[i]= num-1;
        process.emplace_back(make_pair(arr[i], i));
    }
    //add queries to queue
    for(int i=0; i<N; i++){
        if(arr[i]>i){
            process.emplace_back(i, -(1<<30));
        }
    }
    sort(process.begin(), process.end());
    long ans=0;
    //we're processing numbers in order of their value
    // and so we can guarantee that all numbers in segtree are >= queried sum
    // by adding queried sum into our queries as a variable
    //so then all you have to do is query l,r and ignore the sum variable
    for(int i=process.size()-1; i>=0; i--){
        if(process[i].second==-(1<<30)){
            ans+=st.sum(process[i].first+1, min(N, arr[process[i].first]+1));
        }
        else{
            st.update(process[i].second, 1);
        }
    }
    cout<<ans<<endl;
    return 0;
}

