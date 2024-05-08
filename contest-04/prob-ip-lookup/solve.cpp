#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

struct TrieNode {
    TrieNode *children[2] = {nullptr};
    bool isSubnet = false;

    TrieNode() = default;

    ~TrieNode() {
        delete children[0];
        delete children[1];
    }
};

// insert IP or subnet into trie
void insert(TrieNode *root, const string &ip) {
    TrieNode *current = root;
    for (char c : ip) {
        if (c == '*') {
            current->isSubnet = true;
            return;
        }
        ll idx = c - '0';
        if (current->children[idx] == nullptr) {
            current->children[idx] = new TrieNode();
        }
        current = current->children[idx];
    }
}

// lookup IP in trie
bool lookup(TrieNode *root, const string &ip) {
    TrieNode *current = root;
    for (char c : ip) {
        if (current->isSubnet) {
            return true;
        }
        ll idx = c - '0';
        if (current->children[idx] == nullptr) {
            return false;
        }
        current = current->children[idx];
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll noOfActiveIPs, noOfEmployeIPs;
    cin >> noOfActiveIPs;

    string ip;
    TrieNode *root = new TrieNode();

    // insert all active IPs into trie
    for (ll i = 0; i < noOfActiveIPs; ++i) {
        cin >> ip;
        insert(root, ip);
    }

    cin >> noOfEmployeIPs;

    // lookup all employee IPs in trie
    for (ll i = 0; i < noOfEmployeIPs; ++i) {
        cin >> ip;
        cout << (lookup(root, ip) ? "Yes" : "No") << endl;
    }

    delete root;
    return 0;
}
