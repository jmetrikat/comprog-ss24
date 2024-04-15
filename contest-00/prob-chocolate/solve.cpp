#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int width, height;
    cin >> width >> height;
    cout << width * height - 1 << endl;

    return 0;
}
