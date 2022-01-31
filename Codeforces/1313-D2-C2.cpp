/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define endl "\n"
#define v vector
#define int long long


int MOD = 1e9+7;

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

signed main() {
    setIO("", 0);
    int N; cin>>N;
    v<int> arr;
    for(int i=0; i<N; i++){
        int num; cin>>num; arr.push_back(num);
    }
    stack<pii> orz;
    v<int> prefix(N);
    for(int i=0; i<N; i++){
        if(i==0){
            prefix[i] = arr[i];
            orz.emplace(arr[i], i);
        }
        else{
            int popped = 0;
            while(orz.size()>0 && orz.top().first>arr[i]){
                orz.pop(); popped++;
            }
            if(orz.size()==0){
                prefix[i] =  arr[i] * (i+1);
            }
            else prefix[i] = prefix[orz.top().second] + arr[i] * (i-orz.top().second);
            orz.emplace(arr[i], i);
        }
    }
    reverse(arr.begin(), arr.end());
    orz = stack<pii>();
    v<int> suffix(N);
    for(int i=0; i<N; i++){
        if(i==0){
            suffix[i] = arr[i];
            orz.emplace(arr[i], i);
        }
        else{
            int popped = 0;
            while(orz.size()>0 && orz.top().first>arr[i]){
                orz.pop(); popped++;
            }
            if(orz.size()==0){
                suffix[i] =  arr[i] * (i+1);
            }
            else suffix[i] = suffix[orz.top().second] + arr[i] * (i-orz.top().second);
            orz.emplace(arr[i], i);
        }
    }
    reverse(arr.begin(), arr.end());
    reverse(suffix.begin(), suffix.end());
    /*for(int i=0; i<N; i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<N; i++){
        cout<<suffix[i]<<" ";
    }
    cout<<endl;*/
    int best = 0;
    int k = -1;
    for(int i=0; i<N; i++){
        if(prefix[i] +suffix[i] - arr[i] > best){
            best = prefix[i] +suffix[i] - arr[i];
            k=i;
        }
    }
    int cm = arr[k];
    v<int> ans(N);
    for(int j=k; j>=0; j--){
        ans[j] = min(cm, arr[j]);
        cm= min(cm, arr[j]);
    }
    if(k<N-1){
        cm = arr[k+1];
        for(int j=k+1; j<N; j++){
            ans[j] = min(cm, arr[j]);
            cm = min(cm, arr[j]);
        }
    }
    for(int num: ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}

