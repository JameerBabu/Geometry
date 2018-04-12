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

dbl distptseg(pdd a, pdd b, pdd p)
{
    pdd n = sub(b, a);
    pdd pa = sub(a, p);
    dbl c = dot(n, pa);
    if(c > 0.0f)
        return sqrt(dot(pa, pa));
    pdd bp = sub(p, b);
    if(dot(n, bp) > 0.0f)
        return sqrt(dot(bp, bp));
    dbl x = c / dot(n, n);
    n.X *= x;
    n.Y *= x;
    pdd e = sub(pa, n);
    return sqrt(dot(e, e));
}

int main()
{
    pdd a, b, p;
    cin >> p.X >> p.Y >> a.X >> a.Y >> b.X >> b.Y;
    cout << setprecision(8) << fixed;
    if(a == b)
        cout << len(sub(p, a));
    else
        cout << distptseg(a, b, p);
    return 0;
}
