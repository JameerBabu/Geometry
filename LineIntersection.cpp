2 - coincide
1 - intersect
0 - doesn't intersect or parallel

#include <bits/stdc++.h>
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
	if (b==0) return a;
	else return gcd(b,a%b);
}

dbl len(pll p){	return sqrt(p.X*p.X + p.Y*p.Y);}
dbl len(pdd p){	return sqrt(p.X*p.X + p.Y*p.Y);}

ll len2(pll p){	return (p.X*p.X + p.Y*p.Y);}
dbl len2(pdd p){ return (p.X*p.X + p.Y*p.Y);}

pdd norm(pll p){ dbl lenp = len(p);	return mp(p.X/lenp, p.Y/lenp);}
pll normi(pll p){ ll d = gcd(p.X, p.Y);	return mp(p.X/d, p.Y/d);}
pdd norm(pdd p){ dbl lenp = len(p); return mp(p.X/lenp, p.Y/lenp);}

dbl norm(dbl a){	// norms angle in [-PI,PI)
	while(a < -PI) a += 2*PI;
	while(a >= PI) a -= 2*PI;
}

pdd rotate(pll p,dbl a){ return mp(p.X*cos(a) - p.Y*sin(a), p.X*sin(a) + p.Y*cos(a));}
pdd rotate(pdd p,dbl a){ return mp(p.X*cos(a) - p.Y*sin(a), p.X*sin(a) + p.Y*cos(a));}

ll dot(pll p,pll q){ return p.X*q.X + p.Y*q.Y;}
dbl dot(pdd p,pdd q){ return p.X*q.X + p.Y*q.Y;}

ll cross(pll p,pll q){ return p.X*q.Y - p.Y*q.X;}
dbl cross(pdd p,pdd q){ return p.X*q.Y - p.Y*q.X;}

dbl uangle(pll p, pll q){return acos(dot(p,q)/len(p)/len(q));}
dbl uangle(pdd p, pdd q){return acos(dot(p,q)/len(p)/len(q));}

dbl angle(pll p,pll q){	return atan2(cross(p,q),dot(p,q));}
dbl angle(pdd p,pdd q){	return atan2(cross(p,q),dot(p,q));}


pll sub(pll p, pll q){
	return mp(p.X - q.X, p.Y - q.Y);
}
pdd sub(pdd p, pdd q){
	return mp(p.X - q.X, p.Y - q.Y);
}

struct line{
	ll a,b,c;
};

pdd inter(line l1, line l2){
	ll A = cross(mp(l1.a, l1.b), mp(l2.a,l2.b));
	ll B = cross(mp(l1.a, l1.c), mp(l2.a,l2.c));
	ll C = cross(mp(l1.c, l1.b), mp(l2.c,l2.b));


	dbl x = -(dbl)C / A;
	dbl y = -(dbl)B/A;

	return mp(x,y);
}


// bool segment_inter(p1,q1, p2,q2){
// 	if (max(p1.X, q1.X) < min(p2.X, q2.X)) return false;
// 	if (max(p2.X, q2.X) < min(p1.X, q1.X)) return false;
// 	if (max(p1.Y, q1.Y) < min(p2.Y, q2.Y)) return false;
// 	if (max(p2.Y, q2.Y) < min(p1.Y, q1.Y)) return false;

// 	sign(cross(q1-p1,p2-p2)) * sign(cross()) <=0

// }

bool in(ll x, ll p, ll q){
	return (x>=p && x<=q);
}


line lineFromPoints(pll p1, pll p2){
	line l;
	l.a = p2.Y - p1.Y;
	l.b = p1.X - p2.X;
	l.c = -(p1.X*l.a + p1.Y*l.b);

	return l;
}

int main(){

	pll p1,p2, q1,q2;
	cin >> p1.X >> p1.Y;
	cin >> p2.X >> p2.Y;
	cin >> q1.X >> q1.Y;
	cin >> q2.X >> q2.Y;


	pll dir1 = normi(sub(p2,p1));
	pll dir2 = normi(sub(q2,q1));

	
	if(dir1==dir2){
		if (cross(sub(q1,p1), sub(q2,p1)) == 0) cout << 2 << endl;
		else cout << 0 << endl;
		return 0;
	}

	line l1 = lineFromPoints(p1,p2);
	line l2 = lineFromPoints(q1,q2);
	pdd ans = inter(l1,l2);

	cout << 1 << endl;
	cout << setprecision(6) << fixed << ans.X << " " << ans.Y << endl;

	return 0;
}
