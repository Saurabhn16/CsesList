#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Point {
    int x;
    int y;
};

// Function to calculate the polygon's area using the shoelace formula
int polygonArea(const vector<Point>& v) {
    int n = v.size();
    int area = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n; 
        area += v[i].x * v[j].y - v[i].y * v[j].x;
    }
    return abs(area); // Return the absolute value of the area
}

// Function to calculate the boundary points using GCD of differences
int countBoundaryPoints(const vector<Point>& v) {
    int n = v.size();
    int boundaryPoints = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        boundaryPoints += __gcd(abs(v[i].x - v[j].x), abs(v[i].y - v[j].y));
    }
    return boundaryPoints;
}

signed main() {
    fast;
    int t;
    cin >> t;
    vector<Point> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i].x >> v[i].y;
    }

  int area = polygonArea(v)/2;
    int boundary = countBoundaryPoints(v);
    
    
    int interiorPoints =( area +1 - (boundary / 2)) ;

    cout << interiorPoints << ' ' << boundary << endl;

    return 0;
}
