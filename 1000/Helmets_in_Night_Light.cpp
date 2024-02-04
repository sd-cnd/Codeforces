#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p;
    cin >> n >> p;

    vector<pair<pair<int, int>, int>> v(n);
    // Resize the vector to size n

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.second;
    }

    for (int i = 0; i < n; i++)
    {
        v[i].second = 0;
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         { return a.first.second == b.first.second ? a.first.first > b.first.first : a.first.second < b.first.second; });

    for (const auto &item : v)
    {
        cout << "(( " << item.first.first << ", " << item.first.second << " ), " << item.second << ") " << endl;
    }

    int cost = p;

    priority_queue<pair<pair<int, int>, int>> pq;

    
    v[0].second = 1;

    while (!pq.empty())
    {
        auto current = pq.top();
        pq.pop();

        cost += current.first.second;

        for(int i = 0; i < current.first.first; i++) {
            if(v[i].second != 1) {
                pq.push(v[i]);
                v[i].second = 1;
            }
        }
                
          
    }

    cout<<cost<<endl;

    return 0;
}




