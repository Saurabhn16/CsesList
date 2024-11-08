#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define P complex<ll>
const ll INF = 1e9 + 7;

ll cross(P a, P b, P c)
{
    P u = b - a;
    P v = c - a;
    ll cp = (conj(u) * v).imag();
    return (cp > 0) - (cp < 0);
}

bool comp(const P &a, const P &b)
{
    return (a.real() == b.real()) ? (a.imag() < b.imag()) : (a.real() < b.real()); // Using real() and imag()
}

bool mid(P a, P b, P c)
{
    vector<P> v = {a, b, c};
    sort(v.begin(), v.end(), comp);
    return (v[1] == c);
}

bool check(P a, P b, P c, P d)
{
    ll cp1 = cross(a, b, c);
    ll cp2 = cross(a, b, d);
    ll cp3 = cross(c, d, a);
    ll cp4 = cross(c, d, b);
    if (cp1 * cp2 < 0 && cp3 * cp4 < 0)
        return true;
    if (cp3 == 0 && mid(c, d, a) && cp4 < 0)
        return true;
    if (cp4 == 0 && mid(c, d, b) && cp3 < 0)
        return true;
    return false;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> vertices, points;

    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        vertices.push_back({a, b});
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    vector<P> polygon;
    for (ll i = 0; i < n; i++)
    {
        polygon.push_back({vertices[i].first, vertices[i].second});
    }

    polygon.push_back(polygon[0]);

    for (ll i = 0; i < m; i++)
    {
        P point = {points[i].first, points[i].second};
        P infinity = {INF, INF};
        ll cnt = 0;
        ll flag = 0;
        for (ll j = 0; j < n; j++)
        {
            ll cp = cross(polygon[j], polygon[j + 1], point);
            if (cp == 0 && mid(polygon[j], polygon[j + 1], point))
            {
                flag = 1;
                break;
            }
            cnt += check(polygon[j], polygon[j + 1], point, infinity);
        }
        if (flag)
            cout << "BOUNDARY" << endl;
        else
            cout << (cnt & 1 ? "INSIDE" : "OUTSIDE") << endl;
    }

    return 0;
}
