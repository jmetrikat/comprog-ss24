#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

const double INF = numeric_limits<double>::infinity();
const double MAX_DISTANCE = 10.0;

struct Point {
    ll x, y;
};

double euclideanDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        ll n;
        cin >> n;

        // read 2D town coordinates
        vector<Point> towns(n);
        rep(i, n) {
            cin >> towns[i].x >> towns[i].y;
        }

        // construct distance matrix
        vector<vector<double>> dist(n, vector<double>(n, INF));
        rep(i, n) {
            dist[i][i] = 0.0;
            for (ll j = i + 1; j < n; ++j) {
                double d = euclideanDistance(towns[i], towns[j]);
                if (d <= MAX_DISTANCE) {
                    dist[i][j] = d;
                    dist[j][i] = d;
                }
            }
        }

        // flyod warshall algorithm to find all pairs shortest path
        rep(k, n) {
            rep(i, n) {
                rep(j, n) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // check if all towns are connected and find the maximum minimum distance
        bool isConnected = true;
        double maxMinDist = 0.0;

        rep(i, n) {
            rep(j, n) {
                if (dist[i][j] == INF) {
                    isConnected = false;
                    break;
                }
                if (i != j) {
                    maxMinDist = max(maxMinDist, dist[i][j]);
                }
            }
            if (!isConnected) break;
        }

        if (isConnected) {
            cout << fixed << setprecision(4) << maxMinDist << endl;
        } else {
            cout << "Send Kurdy" << endl;
        }
    }
    return 0;
}
