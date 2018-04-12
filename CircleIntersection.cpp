0 - do not intersect
1 - intersect at one point
2 - intersect at two points


#define _USE_MATH_DEFINES
#include <cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvb vector<vector<bool> >

#define ll long long
#define dbl long double
#define pll pair<ll,ll>
#define pdd pair<dbl,dbl>
#define X first
#define Y second

#define MAX 1e10
#define MOD 1000000007
#define PI M_PI

const dbl EPS = 1e-9;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b%a, a);
}

dbl len(pll p){ return sqrt(p.X*p.X + p.Y*p.Y); }
dbl len(pdd p){ return sqrt(p.X*p.X + p.Y*p.Y); }

ll len2(pll p){ return (p.X*p.X + p.Y*p.Y); }
dbl len2(pdd p){ return (p.X*p.X + p.Y*p.Y); }

pdd norm(pll p){ dbl lenp = len(p);	return mp(p.X / lenp, p.Y / lenp); }
pll normi(pll p){ ll d = gcd(p.X, p.Y);	return mp(p.X / d, p.Y / d); }
pdd norm(pdd p){ dbl lenp = len(p); return mp(p.X / lenp, p.Y / lenp); }


pdd rotate(pll p, dbl a){ return mp(p.X*cos(a) - p.Y*sin(a), p.X*sin(a) + p.Y*cos(a)); }
pdd rotate(pdd p, dbl a){ return mp(p.X*cos(a) - p.Y*sin(a), p.X*sin(a) + p.Y*cos(a)); }

ll dot(pll p, pll q){ return p.X*q.X + p.Y*q.Y; }
dbl dot(pdd p, pdd q){ return p.X*q.X + p.Y*q.Y; }

ll cross(pll p, pll q){ return p.X*q.Y - p.Y*q.X; }
dbl cross(pdd p, pdd q){ return p.X*q.Y - p.Y*q.X; }

dbl uangle(pll p, pll q){ return acos(dot(p, q) / len(p) / len(q)); }
dbl uangle(pdd p, pdd q){ return acos(dot(p, q) / len(p) / len(q)); }

dbl angle(pll p, pll q){ return atan2(cross(p, q), dot(p, q)); }
dbl angle(pdd p, pdd q){ return atan2(cross(p, q), dot(p, q)); }


pll sub(pll p, pll q){
    return mp(p.X - q.X, p.Y - q.Y);
}
pdd sub(pdd p, pdd q){
    return mp(p.X - q.X, p.Y - q.Y);
}

int main()
{
    int t;
    cin >> t;
    cout << setprecision(12);
    while(t--)
    {
        dbl x[2], y[2], r[2];
        for(int i = 0; i < 2; ++i)
            cin >> x[i] >> y[i] >> r[i];
        if(x[0] == x[1] && y[0] == y[1] && r[0] == r[1])
        {
            cout << "-1" << endl << endl;
            continue;
        }
        dbl d = len(sub(pll(x[0], y[0]), pll(x[1], y[1])));
        if(d > (r[0] + r[1]) || d < abs(r[1] - r[0]))
        {
            cout << "0" << endl << endl;
            continue;
        }
        dbl ex = (x[1] - x[0]) / d;
        dbl ey = (y[1] - y[0]) / d;
        dbl tx = (r[0] * r[0] - r[1] * r[1] + d*d) / (2 * d);
        dbl ty = sqrt(r[0] * r[0] - tx*tx);
        pdd P1(x[0] + tx*ex - ty*ey, y[0] + tx*ey + ty*ex);
        pdd P2(x[0] + tx*ex + ty*ey, y[0] + tx*ey - ty*ex);
        if(P1 == P2)
        {
            cout << "1" << endl;
            cout << P1.X << ' ' << P1.Y << endl << endl;
        }
        else
        {
            cout << "2" << endl;
            if(P1.X > P2.X || (P1.X == P2.X && P1.Y > P2.Y))
                swap(P1, P2);
            cout << P1.X << ' ' << P1.Y << endl;
            cout << P2.X << ' ' << P2.Y << endl << endl;
        }
    }
    return 0;
}
