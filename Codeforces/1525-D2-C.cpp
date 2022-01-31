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
int main() {
    setIO("", 0);
    int tcs; cin>>tcs;
    while(tcs-->0){
        int N, M; cin>>N>>M;
        v<int> cor;
        for(int i=0; i<N; i++) {
            int num;
            cin >> num;
            cor.push_back(num);
        }
        v<char> letter;
        for(int i=0; i<N; i++){
            char c; cin>>c;
            letter.push_back(c);
        }
        set<int> leftO, leftE;
        set<int> rightE, rightO;
        for(int i=0; i<N; i++){
            if(letter[i]=='R'){
                if(cor[i]%2==0) leftE.emplace(cor[i]);
                else leftO.emplace(cor[i]);
            }
            if(letter[i]=='L'){
                if(cor[i]%2==0)rightE.emplace(cor[i]);
                else rightO.emplace(cor[i]);
            }
        }
        map<int, int> ans;
        set<int> removes;
        for(int cur: rightE){
            if(leftE.size()>0){
                auto it = leftE.upper_bound(cur);
                if(it==leftE.begin()){
                    continue;
                }
                it--;
                int dist = cur- *it; dist/=2;
                ans[*it]= dist;
                ans[cur]=dist;
                leftE.erase(it);
                removes.emplace(cur);
            }
        }
        for(int x: removes){
            rightE.erase(rightE.find(x));
        }
        removes.clear();
        //odd
        for(int cur: rightO){
            if(leftO.size()>0){
                auto it = leftO.upper_bound(cur);
                if(it==leftO.begin()){
                    continue;
                }
                it--;
                int dist = cur- *it; dist/=2;
                ans[*it]= dist;
                ans[cur]=dist;
                leftO.erase(it);
                removes.emplace(cur);
            }
        }
        for(int x: removes){
            rightO.erase(rightO.find(x));
        }
        removes.clear();

        //goes left == right
        //goes right == left
        //cancel out same direction
        //cost is distance from wall + middle
        v<int> leftOT, leftET;
        v<int> rightET, rightOT;
        for(int x: leftO) leftOT.push_back(x);
        for(int x: leftE) leftET.push_back(x);
        for(int x: rightO) rightOT.push_back(x);
        for(int x: rightE) rightET.push_back(x);
        for(int i=0; i<rightET.size(); i+=2){
            if(i+1 <rightET.size()){
                ans[rightET[i+1]] = (rightET[i+1] - rightET[i])/2 + rightET[i];
                ans[rightET[i]] = (rightET[i+1] - rightET[i])/2 + rightET[i];
            }
        }
        for(int i=0; i<rightOT.size(); i+=2){
            if(i+1 <rightOT.size()){
                ans[rightOT[i+1]] = (rightOT[i+1] - rightOT[i])/2 + rightOT[i];
                ans[rightOT[i]] =  (rightOT[i+1] - rightOT[i])/2 + rightOT[i];
            }
        }
        reverse(leftET.begin(), leftET.end());
        for(int i=0; i<leftET.size(); i+=2){
            if(i+1 <leftET.size()){
                ans[leftET[i]] = (leftET[i] - leftET[i+1])/2 + (M-leftET[i]);
                ans[leftET[i+1]] = (leftET[i] - leftET[i+1])/2 + (M-leftET[i]);
            }
        }
        reverse(leftOT.begin(), leftOT.end());
        for(int i=0; i<leftOT.size(); i+=2){
            if(i+1 <leftOT.size()){
                ans[leftOT[i]] = (leftOT[i] - leftOT[i+1])/2 + (M-leftOT[i]);
                ans[leftOT[i+1]] = (leftOT[i] - leftOT[i+1])/2 + (M-leftOT[i]);
            }
        }
        //goes left == right
        //goes right == left
        //cancel out same direction
        //cost is right-0 + M-left + gap
        if(leftET.size()%2==1 && rightET.size()%2==1){
            int dist = rightET.back() + (M- leftET.back()) + abs((rightET.back() -leftET.back())/2);
            ans[leftET.back()] = dist;
            ans[rightET.back()] = dist;
        }
        if(leftOT.size()%2==1 && rightOT.size()%2==1){
            int dist = rightOT.back() + (M- leftOT.back()) + abs((rightOT.back() -leftOT.back())/2);
            ans[leftOT.back()] = dist;
            ans[rightOT.back()] = dist;
        }
        for(int i=0; i<N; i++){
            if(ans.find(cor[i])==ans.end()) cout<<-1<<" ";
            else cout<<ans[cor[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

