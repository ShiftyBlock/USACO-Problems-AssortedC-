#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define long long long
#define v vector
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pq priority_queue
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
v<pii> hotels, offers;
int N, M, O;
//sorted in ascemnding order
map<pii, int> i_have_a_crush_on_william_lin_because_he_is_absolutely_adorable_and_is_really_fucking_cute_like_seriously_how_can_you_not_fall_in_love_with_such_a_cutie;
int main() {
    setIO("hot", 0);
    cin>>N>>M>>O;
    
    for (int i = 0; i < N; ++i)
    {
    	int cost, time;
    	cin>> cost>>time;
    	hotels.push_back(make_pair(time,cost));
        //throw the pair into the map
        i_have_a_crush_on_william_lin_because_he_is_absolutely_adorable_and_is_really_fucking_cute_like_seriously_how_can_you_not_fall_in_love_with_such_a_cutie[make_pair(time,cost)]++;
    }
    for (int i = 0; i < M; ++i)
    {
    	int cost, time;
    	cin>> cost>>time;
    	offers.push_back(make_pair(cost, time));
    }
    sort(hotels.begin(), hotels.end()); sort(offers.begin(), offers.end());
    long sum=0;
    v<int> q;
    for(int i=M-1; i>=0; i--){
        //iterator to the first hotel that can hold my offer
        auto best= i_have_a_crush_on_william_lin_because_he_is_absolutely_adorable_and_is_really_fucking_cute_like_seriously_how_can_you_not_fall_in_love_with_such_a_cutie.lower_bound(make_pair(offers[i].s,-1));
        //if it doesnt exist
        if(best== i_have_a_crush_on_william_lin_because_he_is_absolutely_adorable_and_is_really_fucking_cute_like_seriously_how_can_you_not_fall_in_love_with_such_a_cutie.end()) continue;
        int ppl= (best->f).f;
        int money= (best->f).s;
        q.push_back(offers[i].f-money);
        if(best->s==1) i_have_a_crush_on_william_lin_because_he_is_absolutely_adorable_and_is_really_fucking_cute_like_seriously_how_can_you_not_fall_in_love_with_such_a_cutie.erase(best);
        else  i_have_a_crush_on_william_lin_because_he_is_absolutely_adorable_and_is_really_fucking_cute_like_seriously_how_can_you_not_fall_in_love_with_such_a_cutie[best->f]--;
        
    }
    sort(q.begin(), q.end());
    while(O-->0){
        if(q[q.size()-1]<0) break;
        sum+= q[q.size()-1]; q.pop_back();
    }
    
    cout<<sum<<endl;
    

    return 0;
}
















