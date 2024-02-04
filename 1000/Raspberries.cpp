#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test = 0;
    cin >> test;

    while (test--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);

        int ans = k, count = 0;

        for (int i = 0; i < n; i++)
        {
            int element;
            cin >> element;

            if(element % 2 == 0) count++;

            if(element % k == 0) ans = 0;

            ans = min(ans, k - element % k);
        }

        if(k == 4) {
            if(count >= 2) {
                ans = 0;
            }
            else if(count == 1) {
                ans = min(ans, 1);
            }
            else {
                ans = min(ans, 2);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}