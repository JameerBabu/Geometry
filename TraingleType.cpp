#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#define ll long long
using namespace std;

struct point
{
    ll x, y;
}; 

point sub(point p, point q){
    return point{p.x - q.x, p.y - q.y};
}

ll dot(point a, point b)
{
    return a.x*b.x + a.y*b.y;
}

ll cross(point a, point b)
{
    return a.x*b.y - b.x*a.y;
}

int main()
{
    point p[3];
    ll dt[3];
    for(int i = 0; i < 3; ++i)
        cin >> p[i].x >> p[i].y;
    for(int i = 0; i < 3; ++i)
        dt[i] = dot(sub(p[(i + 1) % 3], p[i]), sub(p[(i + 2) % 3], p[i]));
    for(int i = 0; i < 3; ++i)
    {
        if(dt[i] == 0)
        {
            cout << "RIGHT" << endl;
            return 0;
        }
        if(dt[i] < 0)
        {
            cout << "OBTUSE" << endl;
            return 0;
        }
    }
    cout << "ACUTE" << endl;
    return 0;
}
