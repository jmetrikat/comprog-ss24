#include <bits/stdc++.h>

#define rep(a, b) for (ll a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ll long long
#define Graph vector<vector<ll>>
#define WeightedGraph vector<vector<pair<ll, ll>>>

using namespace std;

struct Point {
    double x, y;
};

struct Circle {
    Point center;
    double radius;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double pointLineDistance(Point a, Point b, Point c) {
    // distance from point c to the line defined by points a and b
    double area = abs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
    double AB = distance(a, b);
    return area / AB;
}

bool intersects(Point a, Point b, Circle circle) {
    // orthogonal distance from circle center to line needs to be smaller than radius
    double dist = pointLineDistance(a, b, circle.center);
    // dotproduct (cosine of angle) needs to be positive (otherwise the angle is obtuse (90-270 degrees))
    double cos = (b.x - a.x) * (circle.center.x - a.x) + (b.y - a.y) * (circle.center.y - a.y);

    // combine both conditions; alternatively to 2nd, the ballon can directly be hit from the start
    return (dist < circle.radius && (cos > 0 || distance(a, circle.center) < circle.radius));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        Point crossbow, target;
        cin >> crossbow.x >> crossbow.y >> target.x >> target.y;

        int n;
        cin >> n;
        vector<Circle> balloons(n);
        rep(i, n) {
            cin >> balloons[i].center.x >> balloons[i].center.y >> balloons[i].radius;
        }

        int count = 0;
        for (const auto &balloon : balloons) {
            if (intersects(crossbow, target, balloon)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
