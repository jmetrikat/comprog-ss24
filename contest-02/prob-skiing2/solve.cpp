#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()

using namespace std;

// use binary search to find the minimum
long long findSink(long long left, long long right) {
    long long leftIsLower;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        cout << "? " << left << " " << mid << endl;
        cin >> leftIsLower;

        if (leftIsLower == true) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << "? " << left << " " << right << endl;
    cin >> leftIsLower;
    return leftIsLower ? left : right;
}

// use binary search to find the maximum
void findSummit(long long left, long long right) {
    long long leftIsLower, previousIsLower;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        cout << "? " << mid - 1 << " " << mid << endl;
        cin >> previousIsLower;
        cout << "? " << left << " " << mid << endl;
        cin >> leftIsLower;

        if (leftIsLower == false || previousIsLower == false) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << "? " << left << " " << right << endl;
    cin >> leftIsLower;
    cout << "! " << (leftIsLower ? right : left) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    long long numberOfMeasurementPoints;
    cin >> numberOfMeasurementPoints;

    long long lastIsLower, firstIsLower, secondLastIsLower;
    cout << "? " << numberOfMeasurementPoints - 2 << " " << numberOfMeasurementPoints - 1 << endl;
    cin >> secondLastIsLower;
    cout << "? " << numberOfMeasurementPoints - 1 << " " << 0 << endl;
    cin >> lastIsLower;
    cout << "? " << 0 << " " << 1 << endl;
    cin >> firstIsLower;

    if (lastIsLower == true && firstIsLower == false) {
        // check if start point is  local maximum
        cout << "! " << 0 << endl;
        return 0;
    } else if (secondLastIsLower == true && lastIsLower == false) {
        // check if end point is  local maximum
        cout << "! " << numberOfMeasurementPoints - 1 << endl;
        return 0;
    }

    if (firstIsLower == false) {
        findSummit(findSink(0, numberOfMeasurementPoints - 1), numberOfMeasurementPoints - 1);
    } else {
        findSummit(0, numberOfMeasurementPoints - 1);
    }

    return 0;
}
