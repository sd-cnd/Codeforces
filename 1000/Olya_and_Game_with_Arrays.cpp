#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test = 0;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;

        vector<vector<int>> arrays;

        for (int i = 0; i < n; ++i)
        {
            int m;
            cin >> m;

            vector<int> arr(m);
            for (int j = 0; j < m; ++j)
            {
                cin >> arr[j];
            }

            arrays.push_back(arr);
        }

        int minElement = arrays[0][0];

        for (size_t i = 0; i < arrays.size(); ++i)
            {
                for (size_t j = 0; j < arrays[i].size(); ++j)
                {
                    if (arrays[i][j] < minElement)
                    {
                        minElement = arrays[i][j];
                    }
                }
            }

        for (auto &subArray : arrays)
        {
            sort(subArray.begin(), subArray.end());
        }

        if (n == 1)
        {
            cout << arrays[0][0] << endl;        
        }
        else
        {
            int smallestSecondIndex = numeric_limits<int>::max(); 
            for (const auto &subArray : arrays)
            {
                if (subArray.size() >= 2)
                {
                    smallestSecondIndex = min(smallestSecondIndex, subArray[1]);
                }
            }

            int sum = 0;

            for (int i = 0; i < n; i++)
            {
                if (arrays[i][1] != smallestSecondIndex)
                {
                    sum += arrays[i][1];
                }
                else
                {
                    sum += minElement;
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}