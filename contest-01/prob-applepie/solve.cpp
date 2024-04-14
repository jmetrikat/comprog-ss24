#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcases, households, pies, count;
    cin >> testcases;

    while (testcases--) {
        priority_queue<tuple<int, int, int>> ponies;
        cin >> households >> pies;
        pies -= households;

        for (int j = 0; j < households; j++) {
            cin >> count;
            ponies.push(make_tuple(count, count, 1));
        }

        for (int k = 0; k < pies; k++) {
            tuple<int, int, int> pony = ponies.top();
            ponies.pop();
            ponies.push(make_tuple(ceil(static_cast<double>(get<1>(pony)) / (static_cast<double>(get<2>(pony)) + 1.0)), get<1>(pony), get<2>(pony) + 1));
            pony = ponies.top();
        }

        tuple<int, int, int> result = ponies.top();
        cout << get<0>(result) << endl;
    }

    return 0;
}
