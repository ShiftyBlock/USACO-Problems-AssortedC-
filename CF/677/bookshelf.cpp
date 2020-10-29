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

int main() {
    setIO("", 0);

    int tcs;
    cin>>tcs;
    while(tcs-->0){
    	int N; v<int> arr;
    	cin>>N;
    	for (int i = 0; i < N; ++i)
    	{
    		int num; cin>>num;
    		arr.push_back(num);
    	}
    	int idx1=-1;
    	int idx2=-1;
    	int sum=0;
    	for (int i = 0; i < N; ++i)
    	{
    		if(idx1==-1 && arr[i]==1) idx1=i;
    		else if(idx2==-1 && arr[i]==1) idx2=i;
    		if(idx2!=-1 && idx1!=-1){
    			sum+=idx2-idx1-1;
    			idx1=idx2; idx2=-1;
    		}
    	}
    	cout<<sum<<endl;
    }
    return 0;
}
















