#include<bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;

    while(test--) {
        string s = "";
        cin >> s;

        string t = s;

        int size = s.length();

        int countZero = 0;
        int countOne = 0;

        for(auto it : s) {
            if(it == '0') {
                countZero++;
            }
            if(it == '1'){
                countOne++;
            }
        } 

        if(countZero == countOne) {
            cout << "0" << endl;
        } 
        else {
            int ans = 0;

            for (int i = 0; i < size; i++) {
                if(s[i] == '0' && countOne != 0) {
                    t[i] = '1';
                    countOne--;
                } 
                else if(s[i] == '1' && countZero != 0) {
                    t[i] = '0';
                    countZero--;
                }
            }

            for(int i = 0; i < size; i++) {
                if(s[i] == t[i]) {
                    ans = i;
                    break;
                }
            }
            cout << size - ans << endl;
        }
    }
   
    return 0;
}
