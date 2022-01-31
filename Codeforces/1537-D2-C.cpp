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
int countit(v<int> temp){
    int ans =0;
    for(int i=1; i<temp.size(); i++){
        if(temp[i] >= temp[i-1]) ans++;
    }
    return ans;
}
v<int> res;

v<int> tryit(int minx, v<int> arr){
    v<int> temp;
    temp.push_back(minx);
    arr.erase(find(arr.begin(), arr.end(), minx));
    arr.erase(find(arr.begin(), arr.end(), minx));
    int j=0;
    int N = arr.size();
    for(int i=0;i<N; i++){
        if(arr[i]>=minx) {
            j=i; break;
        }
    }
    int fj=j;
    while(j<N){
        temp.push_back(arr[j]);
        j++;
    }
    j=0;
    while(j<fj){
        temp.push_back(arr[j]);
        j++;
    }
    temp.push_back(minx);
    return temp;
}
void print(int minx, int maxx, v<int> arr){
    v<int> x = tryit(minx, arr);
    v<int> y = tryit(maxx, arr);
    if(countit(x)> countit(y)){
        for(int num: x){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    else{
        for(int num: y){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

v<int> tryit2(int a, int b, v<int> arr){
    v<int> temp;
    temp.push_back(a);
    arr.erase(find(arr.begin(), arr.end(), a));
    arr.erase(find(arr.begin(), arr.end(), b));

    int N = arr.size();
    if(N!=0){
        int j=0;
        for(int i=0;i<N; i++){
            if(arr[i]>=a) {
                j=i; break;
            }
        }
        int fj=j;
        while(j<N){
            temp.push_back(arr[j]);
            j++;
        }
        j=0;
        while(j<fj){
            temp.push_back(arr[j]);
            j++;
        }
    }
    temp.push_back(b);
    return temp;
}
void print2(int minx, int maxx, int a, int b, v<int> arr){
    v<int> x = tryit2(minx, maxx, arr);
    v<int> y = tryit2(a,b, arr);
    if(countit(x)> countit(y)){
        for(int num: x){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    else{
        for(int num: y){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> arr;
        map<int, int> m;
        for(int i=0; i<N; i++){
            int num; cin>>num; arr.push_back(num);
            m[num]++;
        }
        int minx=1<<30; int maxx=- (1<<30);
        for(auto x: m){
            if(x.second>1){
                minx = min(minx, x.first);
                maxx = max(maxx, x.first);
            }
        }
        sort(arr.begin(), arr.end());
        if(minx!=1<<30){
            print(minx, maxx, arr);
            continue;
        }
        int mingap =1<<30;
        for(int i=1; i<N; i++){
            mingap = min(mingap, arr[i] - arr[i-1]);
        }
        for(int i=1; i<N; i++){
            if(arr[i]- arr[i-1] == mingap){
                minx = min(minx, i);
                maxx = max(maxx, i);
            }
        }
        print2(arr[minx-1], arr[minx], arr[maxx-1], arr[maxx], arr);

    }
    return 0;
}

