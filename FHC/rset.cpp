#include <bits/stdc++.h>
using namespace std;
int reststops[100000][2];
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

int main(){
    setIO("reststops",0);
    int L,N,rf,rb;
    vector<pair<int,int>> tastiness;
    cin>>L>>N>>rf>>rb;
    //reststops[n][0] is meters from beginning and reststops[n][1] is tastiness
    for(int i=0;i<N;i++){
        cin>>reststops[i][0]>>reststops[i][1];
        tastiness.emplace_back(reststops[i][1],reststops[i][0]);
        //tastiness[i][0] is the tastiness factor
    }

    sort(tastiness.begin(), tastiness.end(), greater<>());

    int speed=rf-rb;
    int distance=0;
    long tunits=0;
    for(int i=0;i<N;i++){
        if(tastiness[i].second>distance){
            long secondsleft=(long) speed*(tastiness[i].second-distance);
            distance=tastiness[i].second;
            tunits+=secondsleft*tastiness[i].first;
        }
    }
    cout<<tunits<<endl;
}