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
int N;
v<int> arr;
void psum(v<int> &prefix){
    for(int i=0; i<N;){
        int j=i+1;
        while(j<N){
            if(arr[j] < arr[j-1]){
                j++;
            }
            else break;
        }
        while(i<j){
            prefix[i] = j-i-1;
            i++;
        }
    }
}
int main() {
    setIO("", 0);
    cin>>N;
    for(int i=0; i<N; i++){
        int n; cin>>n; arr.push_back(n);
    }
    v<int> prefix(N);
    psum(prefix);
    reverse(arr.begin(), arr.end());
    v<int> suffix(N);
    psum(suffix);
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
    map<int, int> m;
    for (int i=0; i<N; i++){
        m[prefix[i]]++;
        m[suffix[i]]++;
    }
    int ans = 0;
    for(int i=1; i<N-1; i++){
        if(arr[i]<= arr[i-1] || arr[i]<=arr[i+1]) continue;
        if(prefix[i]!=suffix[i]) continue;
        m[prefix[i]]--;
        if(m[prefix[i]]==0) m.erase(prefix[i]);
        m[suffix[i]]--;
        if(m[suffix[i]]==0) m.erase(suffix[i]);
        int largest = (*(m.rbegin())).first;
        if(largest< max(prefix[i], suffix[i])){
            ans++;
        }
        m[prefix[i]]++;
        m[suffix[i]]++;
    }
    cout<<ans<<endl;


    return 0;
}

