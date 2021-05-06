#include <bits/stdc++.h>
using namespace std;

int main()
{
    // block 1
    set<int> s;
    for(int i = 0; i < 26; i++) {
        int bit[5] = {};
        int ind = 4, val = i;
        while (val > 0) {
            if (val % 2 == 1) bit[ind] = 1;
            val /= 2;
            ind--;
        }
        int ans[5] = {};

        // bit[0] = MSB;
        // bit[4] = LSB;
        int a = bit[0];
        int b = bit[1];
        int c = bit[2];
        int d = bit[3];
        int e = bit[4];


        ans[0] = ((!a) & (c) & (!d) & (!e)) |
        ((!a) & (!b) & (!c) & (e)) |
        ((!a) & (d) & (e)) |
        ((!a) & (!c) & (d)) |
        ((!a) & (!b) & (d));


        ans[1] = ((b) & (!c) & (d) & (e)) |
        ((a) & (!b) & (!c) & (!d)) |
        ((!a) & (!b) & (!c) & (!e)) |
        ((c) & (!d) & (e)) |
        ((!c) & (!d) & (!e));


        ans[2] = ((a) & (!b) & (!d) & (!e)) |
        ((!a) & (b) & (!c) & (!e)) |
        ((!a) & (!b) & (d) & (e)) |
        ((a) & (!b) & (!c)) |
        ((!a) & (!c) & (!d));


        ans[3] = ((!a) & (!b) & (!c) & (e)) |
        ((a) & (c) & (!d)) |
        ((!b) & (c) & (!e)) |
        ((!b) & (!d) & (!e)) |
        ((a) & (b)) |
        ((a) & (!e));


        ans[4] = ((!a) & (!b) & (!d) & (e)) |
        ((!a) & (b) & (!c) & (!d)) |
        ((!a) & (!c) & (d) & (!e)) |
        ((a) & (c) & (d)) |
        ((a) & (!d) & (!e)) |
        ((c) & (!d) & (!e));

        for (int j = 0; j < 5; j++)
            cout << bit[j] ;
        cout << " --->  ";
        for (int j = 0; j < 5; j++) 
            cout << ans[j];
        cout << "  ||  ";

        int newChar = ans[4]*1 + ans[3]*2 + ans[2]*4 + ans[1]*8 + ans[0]*16; 
        s.insert(newChar);
        cout << (char)(i + 'a') << " --->  " << (char)(newChar + 'a') << '\n';
    }
    cout << s.size() << '\n';
    for (auto  i : s)
        cout << i << ' ' ;
    return 0;
}

