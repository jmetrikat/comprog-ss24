#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

const string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll ms, passwordLength, previousTime;
    string password = "A", response = "";

    for (int i = 1; i <= 20; i++) {
        cout << password << endl;
        getline(cin, response);
        ms = stoi(response.substr("ACCESS DENIED ("s.size()));
        if (ms == 5) {
            password += "A";
        } else {
            passwordLength = i;
            break;
        }
    }

    previousTime = ms;
    rep(i, passwordLength) {
        for (char c : CHARSET) {
            password[i] = c;
            cout << password << endl;
            getline(cin, response);

            if (response.find("ACCESS GRANTED") != string::npos) {
                return 0;
            }

            ms = stoi(response.substr("ACCESS DENIED ("s.size()));
            if (ms > previousTime) {
                previousTime = ms;
                break;
            }
        }
    }

    cout << password << endl;

    return 0;
}
