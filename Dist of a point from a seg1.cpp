#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct point
{
	ll x,y;
};

struct line
{
	ll a,b,c;
};

line lineFromPoints(point p1, point p2){
	line l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = -(p1.x*l.a + p1.y*l.b);
	return l;
}

int main()
{
	point p,a,b;
	
	cin >> p.x >> p.y >> a.x >> a.y >> b.x >> b.y ;
	
	line li = lineFromPoints( a,b);
	
	long double s = sqrt((li.a * li.a) + (li.b * li.b));
	
	ll c = (li.a * p.x )+ (li.b * p.y)+ li.c ;
	
	long double f;
	f= (double) c/s ;
	
	
	cout << fixed << setprecision (6) << abs(f) << endl;
	
	
}
