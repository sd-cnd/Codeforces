#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a)
        {
            cin >> x;
            x %= k;
            if (!x)
            x = k;
        }
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        stable_sort(ord.begin(), ord.end(), [&](int i, int j)
                    { return a[i] > a[j]; });
        for (auto &x : ord)
            cout << x + 1 << ' ';
        cout << endl;
    }
    return 0;
}