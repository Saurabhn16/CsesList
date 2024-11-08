// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Point {
    int x;
    int y;
};

int polygonArea(const vector<Point>& v) {
    int n = v.size();
    int area = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; 
        area += v[i].x * v[j].y - v[i].y * v[j].x;
    }
    return abs(area) ;  // Return the absolute value divided by 2
}

signed main() {
    fast;
    int t;
    cin >> t;
    vector<Point> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i].x >> v[i].y;
    }

    // Calculate and print the area of the polygon
    int area = polygonArea(v);
    cout << fixed << setprecision(1) << area << "\n";

    return 0;
}
