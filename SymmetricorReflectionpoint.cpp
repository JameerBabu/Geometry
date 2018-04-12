You are given a line passing through two distinct points (x1, y1) and (x2, y2). Find the point which is symmetric to the point (x, y) relative to the given line.

Input format
In the first line there are two integer numbers x1 and y1. In the second line there are two integer numbers x2 and y2. The third line contains integers x and y. All the numbers do not exceed 109 by absolute value.

Output format
Print coordinates of the requited point with at least 8 digits after a decimal point or single integer -1 if the given point (x, y) is on the given line.

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

void reflect(pdd p, pdd a, pdd b)
{
    pdd bt = sub(b, a);
    dbl xx, yy;
    if(b.X == a.X)
    {
        xx = p.X + 2 * (a.X - p.X);
        yy = p.Y;
    }
    else
    {
        dbl m = (b.Y - a.Y) / (b.X - a.X);
        dbl c = a.Y - m*a.X;
        dbl d = (p.X + (p.Y - c)*m) / (1 + m*m);
        xx = 2 * d - p.X, yy = 2 * d*m - p.Y + 2 * c;
    }
    if(xx == p.X && yy == p.Y)
    {
        cout << "-1" << endl;
        return;
    }
    cout << xx << ' ' << yy << endl;
}

int main()
{
    pdd a, b, p;
    cin >> a.X >> a.Y >> b.X >> b.Y >> p.X >> p.Y;
    cout << setprecision(10) << fixed;
    reflect(p, a, b);
    return 0;
}
