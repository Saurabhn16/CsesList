// saurabh_1610
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct Point {
    int x, y;
};

// Function to find the orientation of the ordered triplet (p, q, r).
// Returns 0 if collinear, 1 if clockwise, 2 if counterclockwise.
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2;  // Clockwise or Counterclockwise
}

// Function to check if point r lies on the segment pq
bool onSegment(Point p, Point q, Point r) {
    return (r.x >= min(p.x, q.x) && r.x <= max(p.x, q.x) &&
            r.y >= min(p.y, q.y) && r.y <= max(p.y, q.y));
}

// Function to check if line segments p1q1 and p2q2 intersect
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case: check if the orientations are different
    if (o1 != o2 && o3 != o4) return true;

    // Special cases for collinear points
    if (o1 == 0 && onSegment(p1, q1, p2)) return true;
    if (o2 == 0 && onSegment(p1, q1, q2)) return true;
    if (o3 == 0 && onSegment(p2, q2, p1)) return true;
    if (o4 == 0 && onSegment(p2, q2, q1)) return true;

    // No intersection found
    return false;
}

void ans(bool v) {
    if (v) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

signed main() {
    fast;
    int t;
    cin>>t;
    while(t--){
    Point p1, q1, p2, q2;
    cin >> p1.x >> p1.y >> q1.x >> q1.y;
    cin >> p2.x >> p2.y >> q2.x >> q2.y;
    ans(doIntersect(p1, q1, p2, q2));
    }
    return 0;
}
