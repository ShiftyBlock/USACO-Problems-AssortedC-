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
int pos[10][100001];
int main() {
    setIO("", 0);
    int N, M; cin>>N>>M;
    v<int> p(M);
    v<v<int>> arr;
    for(int i=0; i<M; i++){
        v<int> cur;
        for(int j=0; j<N; j++){
            int num; cin>>num; cur.push_back(num);
        }
        arr.push_back(cur);
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            pos[i][arr[i][j]]=j;
        }
    }
    long ans = 0;
    for(int i=0; i<N; ){
        for(int j=0; j<M; j++){
            p[j] = pos[j][arr[0][i]];
        }
        int idx=i+1;
        while(idx<N){
            bool valid =true;
            for(int j=0; j<M; j++){
                if(p[j]+idx-i>=N){
                    valid= false;
                    break;
                }
                if(arr[j][p[j]+idx-i] == arr[0][idx]) continue;
                else{
                    valid= false;
                    break;
                }
            }
            if(valid) idx++;
            else break;
        }
        long gap = idx-i;
        ans+=gap*(gap+1)/2;
        i=idx;
    }
    cout<<ans<<endl;
    return 0;
}

