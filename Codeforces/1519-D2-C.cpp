/*
ID: davidzh8
PROG: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define pii pair<long,long>
//#define endl "\n"
#define long long long
#define v vector

void setIO(string name, int submit) {
    /*
    if (submit) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
    else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }*/

}
v<long> adj[200001];
v<long> prefix[200001];
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N; cin>>N;
        v<int> school;
        v<int> skill;
        for(int i=0; i<N; i++){
            int jkl; cin>>jkl; jkl--;
            school.push_back(jkl);
        }
        for(int i=0; i<N; i++){
            int jkl; cin>>jkl;
            skill.push_back(jkl);
        }
        for(int i=0; i<N; i++){
            adj[school[i]].push_back(skill[i]);
        }
        for(int i=0; i<N; i++){
            sort(adj[i].begin(), adj[i].end());
            reverse(adj[i].begin(), adj[i].end());
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<adj[i].size(); j++){
                if(j==0) prefix[i].push_back(adj[i][j]);
                else{
                    prefix[i].push_back(prefix[i][j-1] + adj[i][j]);
                }
            }
        }
       /* for(int i=0; i<N; i++){
            for(int j=0; j<adj[i].size(); j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<adj[i].size(); j++){
                cout<<prefix[i][j]<<" ";
            }
            cout<<endl;
        }*/
        set<int> proc;
        for(int i=0; i<N; i++){
            proc.insert(i);
        }
        for(int i=1; i<=N; i++){
            long sum =0;
            v<int> removes;
            for(int num: proc){
                int siz = prefix[num].size();
                int pref = siz/i; pref *= i;
                if(pref==0) {
                    removes.push_back(num);
                    continue;
                }
                else{
                    sum+=prefix[num][pref-1];
                }
            }
            for(int num: removes){
                proc.erase(proc.find(num));
            }
            cout<<sum<<" ";
        }
        cout<<endl;

        for(int i=0; i<=N; i++){
            adj[i].clear();
            prefix[i].clear();
        }
    }
    return 0;
}

