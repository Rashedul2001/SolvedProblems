#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if ((str[0] == '0' and str[1] == '1') or (str[n - 1] == '0' and str[n - 2] == '1'))
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (str[i] == '0' and str[i + 1] == '1' and str[i - 1] == '1')
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            for (int j = i; j != last; j--)
            {
                cout << j << ' ';
            }
            cout << i + 1 << ' ';
            last = i + 1;
        }
    }

    for (int i = n; i != last; i--)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
