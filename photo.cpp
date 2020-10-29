#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define endl "\n"
#define rep(i,a,b) for(int i=a; i<b; i++)
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
int N, M;
const int MAXN=2e6+1;
int dp[MAXN];
int main() {
    setIO("photo",0);
    
    cin>>N>>M;
    v<pii> photo;
    v<int> big, small; big.assign(N+1, 1<<30); small.assign(N+1,1<<30);
    rep(i, 0, M){
    	int a,b;
    	cin>>a>>b;
    	photo.emplace_back(a,b);
    	big[a]= min(big[a], b);
    	small[a]= max(small[a], b);
    }
    sort(photo.begin(), photo.end());
    for (int i = 1; i <= N; ++i)
    {
    	small[i]= max(small[i], small[i-1]);
    }
    for (int i = N-1; i >=0; --i)
    {
    	big[i]= min(big[i], big[i+1]);
    }
    int i=N;

    while(i>=0){
    	int best=-1;
    	for(int j=i+1; j<=N; j++){
    		if(big[i]>=j && j>small[i]) best=max(best, dp[j]);
    	}
    	if(best==-1) dp[i]=-1;
    	else dp[i]= best+1;
    	i--;
    }
    
    
    cout<<dp[0]<<endl;

    return 0;
}











































