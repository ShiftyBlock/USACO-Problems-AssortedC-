#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define rep(i,a,b) for(int i=a; i<b; i++)
#define endl "\n"
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
pair<int, string> william_lin_is_orz_and_cute_i_love_william_lin[25001];
char s[25001][21];
int main() {
    setIO("printer", 0);
 
    int N;
    scanf("%d", &N);
    v<int> sim; sim.push_back(0);
    int worst=0;
    for (int i = 0; i < N; ++i)
    {
    	scanf("%s",s[i]);
    	if(strlen(s[worst])<strlen(s[i])){
    		worst=i;
    	}
    }
    rep(i,0,N){
    	int same=0;
    	rep(j,0, strlen(s[i])){
    		if(s[worst][j]==s[i][j]) same++;
    		else break;
    	}
    	william_lin_is_orz_and_cute_i_love_william_lin[i]= make_pair( same, s[i]);
    }
	sort(william_lin_is_orz_and_cute_i_love_william_lin,william_lin_is_orz_and_cute_i_love_william_lin+N );
 	v<char> res;
    rep(i, 0,N){
    	int len=william_lin_is_orz_and_cute_i_love_william_lin[i].s.size();
    	
    	//cout<<william_lin_is_orz_and_cute_i_love_william_lin[i].f<<endl;
    	if(i==0){
    		rep(j,0,len){
    			res.push_back(william_lin_is_orz_and_cute_i_love_william_lin[i].s[j]);
    		}
    		res.push_back('P');
    	}
    	else{
    		int plen= william_lin_is_orz_and_cute_i_love_william_lin[i-1].s.size();
    		int same=0;
    		rep(j,0,min(len,plen)){
    			if(william_lin_is_orz_and_cute_i_love_william_lin[i].s[j]!=william_lin_is_orz_and_cute_i_love_william_lin[i-1].s[j]) break;
    			same++;
    		}
    		rep(j,0, plen-same) {
    			res.push_back('-');
    		}
    		rep(j,same, len){
    			res.push_back(william_lin_is_orz_and_cute_i_love_william_lin[i].s[j]);
    		}
    		res.push_back('P');
    	}
    	
    }
    cout<<res.size()<<endl;
    for(char x: res){
    	cout<<x<<endl;
    }
    return 0;
}
 
 