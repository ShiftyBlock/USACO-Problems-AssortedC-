#include "bits/stdc++.h"

using namespace std;

int n, t;
int final[100];
vector< vector<int> > instructions;

bool check (int min_k, int max_k)
{
    int temp[n];
    int k[n];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        bool works = true;
        fill(temp, temp + n, 0);
        fill(k, k + n, 0);
        temp[i] = 1;
        k[i] = 0;
        int interactions = 0;
        for (int x = 0; x < t; x++)
        {
            interactions++;
            int safe, infected;
            if (temp[instructions[x][1] - 1] != temp[instructions[x][2] - 1])
            {
                if (instructions[x][1] - 1 == 1)
                {
                    infected = instructions[x][1] - 1;
                    safe = instructions[x][2] - 1;
                }
                else
                {
                    infected = instructions[x][2] - 1;
                    safe = instructions[x][1] - 1;
                }
                k[infected]++;
                if (k[infected] <= max_k && k[infected] >= min_k)
                {
                    temp[safe] = 1;
                }
            }
            else if (temp[instructions[x][1] - 1] == 1 && temp[instructions[x][2] - 1] == 1)
            {
                k[instructions[x][1] - 1]++;
                k[instructions[x][2] - 1]++;
            }
        }
        for (int x : temp)
        {
            cout << x << " ";
        }
        cout << endl;
        for (int x = 0; x < n; x++)
        {
            if (temp[x] != final[x])
            {
                works = false;
            }
        }
        if (works == true)
        {
            x++;
        }
    }
    if (x > 0)
    {
        cout << x << " " << min_k;
        if (max_k == t)
        {
            cout << " " << "Infinity" << endl;
        }
        else
        {
            cout << " " << max_k << endl;
        }
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> final[i];
    }
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> input;
        input.push_back(a);
        input.push_back(b);
        input.push_back(c);
        instructions.push_back(input);
    }
    sort(instructions.begin(), instructions.end());
    for (int min_k = 0; min_k < t; min_k++)
    {
        for (int max_k = t; max_k > min_k; max_k--)
        {
            cout << min_k << " " << max_k << endl;
            if (check(min_k, max_k) == true)
            {
                return 1;
            }
        }
    }

}