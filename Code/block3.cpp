#include <bits/stdc++.h>
using namespace std;

int main()
{
    // block 3
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

        // bit[0] = MSB
        // bit[4] = LSB;
         int a = bit[0];
        int b = bit[1];
        int c = bit[2];
        int d = bit[3];
        int e = bit[4];


        ans[0] = ((a) & (c) & (d) & (e)) |
        ((a) & (!c) & (d) & (!e)) |
        ((!a) & (b) & (!c) & (!e)) |
        ((!a) & (!b) & (!d) & (e)) |
        ((!a) & (!b) & (!c) & (!d)) |
        ((b) & (c) & (e)) |
        ((b) & (c) & (!d));


        ans[1] = ((!a) & (!b) & (!c) & (d) & (e)) |
        ((a) & (!d) & (!e)) |
        ((b) & (!d) & (!e)) |
        ((!b) & (c) & (!e)) |
        ((a) & (b));


        ans[2] = ((!a) & (!c) & (!d) & (e)) |
        ((a) & (!c) & (d)) |
        ((a) & (c) & (!e)) |
        ((b) & (c) & (d)) |
        ((b) & (!d) & (e)) |
        ((!b) & (d) & (!e));


        ans[3] = ((a) & (!b) & (!c) & (!e)) |
        ((!a) & (!b) & (c) & (e)) |
        ((!a) & (d) & (e)) |
        ((!a) & (!b) & (d)) |
        ((c) & (d));



        ans[4] = ((a) & (d) & (!e)) |
        ((c) & (!d) & (!e)) |
        ((!c) & (d) & (e)) |
        ((!b) & (c) & (!d)) |
        ((!a) & (!b) & (!c));

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

