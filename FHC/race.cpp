#include "bits/stdc++.h"

using namespace std;
// [lower, upper]
long sum(long lower, long upper){
    return (upper)*(upper+1)/2 - (lower)*(lower-1)/2;
}
int main()
{
   // freopen("race.in", "r", stdin);
    //freopen("race.out", "w", stdout);
    int distance, n;
    cin >> distance >> n;
    int end_speed;
    for (int i = 0; i < n; i++)
    {
        cin >> end_speed;
        int ans = 0;
        int current_speed = 0;
        long distance_travelled = 0;
        while (distance-distance_travelled > 0)
        {
            //stationary = accelerate
            int distance_needed_a = sum(end_speed+1, current_speed+1);
            int distance_needed_s = sum(end_speed+1, current_speed);
            //solve for accel

            if (distance - distance_travelled> distance_needed_a)
            {
                current_speed++;
                ans++;
                distance_travelled += current_speed;
            }
            else if (distance - distance_travelled > distance_needed_s)
            {
                distance_travelled += current_speed;
                ans++;
            }
            else
            {
                current_speed--;
                ans++;
                distance_travelled += current_speed;
            }
        }
        cout << ans << endl;
    }

}