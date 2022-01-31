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
//write up an editorial for this
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
    int N;
    v<int> arr;
    v<int> size;
    djset(int n){
        N=n;
        for(int i=0; i<N; i++){
            arr.push_back(i);
            size.push_back(1);
        }
    }
    int find(int cur){
        if(cur==arr[cur]) return cur;
        int par = find(arr[cur]);
        arr[cur] = par;
        return par;
    }
    bool merge(int a, int b){
        int A = find(a);
        int B = find(b);
        if(A==B) return false;
        if(size[A]<size[B]){
            swap(A,B);
        }
        arr[B]=A;
        size[A]+=size[B];
        return true;
    }
    int sz(int num){
        return size[find(num)];
    }
};
int main() {
    setIO("", 0);
    int N; cin>>N;
    v<pii> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.emplace_back(num, i);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    djset dj(N);
    v<bool>purpleCrayon(N);
    v<int> ans;
    for(int i=0; i<N; ){
        int j=i;
        int size = 1;
        while(arr[i].first == arr[j].first){
            purpleCrayon[arr[j].second]=true;
            if(arr[j].second>0 && purpleCrayon[arr[j].second-1]){
                dj.merge(arr[j].second, arr[j].second-1);
            }
            if(arr[j].second<N-1 && purpleCrayon[arr[j].second+1]){
                dj.merge(arr[j].second, arr[j].second+1);
            }
            size=max(size,dj.sz(arr[j].second));
            j++;
        }
        while(i<j){
            ans.push_back(size);
            i++;
        }
    }
    int j=0;
    for(int i=1; i<=N; ){
        if(ans[j]>=i){
            cout<<arr[j].first<<" ";
            i++;
        }
        else{
            j++;
        }
    }
    cout<<endl;

    return 0;
}

