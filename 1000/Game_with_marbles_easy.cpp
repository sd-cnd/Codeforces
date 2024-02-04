#include <bits/stdc++.h>
using namespace std;

long long int score(long long int a, long long int b) {
    return a - b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long int n;
        cin >> n;

        vector<long long int> a(n), b(n);

        vector<pair<long long int, int>> summation;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            summation.push_back(make_pair(a[i] + b[i], i));
        }

        sort(summation.rbegin(), summation.rend());

        int index = 0;

        for (int i = 0; i < n; i++) {
            if (index % 2 == 0) {
                a[summation[i].second] -= 1;
                b[summation[i].second] = 0;
            } else {
                a[summation[i].second] = 0;
                b[summation[i].second] -= 1;
            }
            index++;
        }

        long long int sumA = accumulate(a.begin(), a.end(), 0LL);
        long long int sumB = accumulate(b.begin(), b.end(), 0LL);

        long long int answer = score(sumA, sumB);

        cout << answer << endl;
    }

    return 0;
}
