#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long

using namespace std;

// possible knight moves: 2 in one direction and 1 in the other
const ll knight_moves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

struct Move {
    ll r1, c1, r2, c2;
};

void bfs(vector<vector<char>>& board, ll h, ll w, ll kr, ll kc) {
    queue<pair<ll, ll>> q;
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    vector<vector<Move>> parent(h, vector<Move>(w));

    // start bfs from the black king's position
    q.push({kr, kc});
    visited[kr][kc] = true;

    // check all possible knight moves by moving the king with knight moves
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        // checkmate is possible if the king is at a knight's position
        if (board[r][c] == 'N') {
            vector<Move> moves;
            ll pr = r, pc = c;

            // reconstruct the path from the knight to the king
            while (pr != kr || pc != kc) {
                Move m = parent[pr][pc];
                moves.push_back(m);
                tie(pr, pc) = make_pair(m.r2, m.c2);
            }
            cout << "Checkmate in " << moves.size() << endl;
            for (const auto& move : moves) {
                cout << h - move.r1 << " " << move.c1 + 1 << " " << h - move.r2 << " " << move.c2 + 1 << endl;
            }
            return;
        }

        // from current position, take the next move
        for (int i = 0; i < 8; ++i) {
            int nr = r + knight_moves[i][0];
            int nc = c + knight_moves[i][1];

            // check if the move is valid
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && !visited[nr][nc] && (board[nr][nc] == 'N' || !isupper(board[nr][nc]))) {
                visited[nr][nc] = true;
                parent[nr][nc] = {nr, nc, r, c};
                q.push({nr, nc});
            }
        }
    }

    cout << "Resign" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll w, h;
    cin >> w >> h;
    vector<vector<char>> board(h, vector<char>(w));

    // read the board and find the knight's row and column position
    ll kr = -1, kc = -1;
    rep(i, h) {
        rep(j, w) {
            cin >> board[i][j];
            if (board[i][j] == 'k') {
                kr = i;
                kc = j;
            }
        }
    }

    bfs(board, h, w, kr, kc);

    return 0;
}
