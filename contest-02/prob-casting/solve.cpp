#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll numberOfBlocks;
        cin >> numberOfBlocks;
        vector<ll> characters(numberOfBlocks, 0);

        rep(i, numberOfBlocks) {
            char c;
            cin >> c;

            if (c == 'W') {
                characters[i] = 1;
            }
        }

        // check if all blocks are already the same color
        if (find(all(characters), 0) == characters.end() || find(all(characters), 1) == characters.end()) {
            cout << "YES\n0" << endl;
        } else {
            // switch all blocks to white
            vector<ll> usedSpells;
            rep(i, numberOfBlocks - 1) {
                if (characters[i] == 0) {
                    characters[i] = 1;
                    characters[i + 1] = 1 - characters[i + 1];
                    usedSpells.push_back(i + 1);
                }
            }

            // check if last block is white as well as it can't be switched at all
            if (characters[characters.size() - 1] == 1) {
                cout << "YES\n"
                     << usedSpells.size() << endl;
                for (auto& spell : usedSpells) {
                    cout << spell << " ";
                }
            } else {
                // check if all blocks can be switched to black
                if ((characters.size() - 1) % 2 == 0) {
                    // if length without last block is even, we can switch all to black
                    for (ll i = 0; i < characters.size() - 1; i += 2) {
                        characters[i] = 0;
                        characters[i + 1] = 1 - characters[i + 1];
                        usedSpells.push_back(i + 1);
                    }
                    cout << "YES\n"
                         << usedSpells.size() << endl;
                    for (auto& spell : usedSpells) {
                        cout << spell << " ";
                    }

                } else {
                    // if length without last block is odd, switching is not possible
                    cout << "NO";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
