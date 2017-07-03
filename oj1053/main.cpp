
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;


//ac
struct Point
{
    int x;
    int y;
    int z;
};

int n;
const int MAXN = 100000;
Point points[MAXN];
int curx[MAXN];
int cury[MAXN];


bool cmpPoint(const Point& a,const Point& b){
    if(a.x!=b.x){
        return a.x<b.x;
    }else
        return a.y<b.y;
}


int find(int x,int y){
    Point tofind;
    tofind.x = x;
    tofind.y = y;
    Point* f = lower_bound(points,points+n,tofind,cmpPoint);
    if(f != points+n and f->x==x and f->y==y)
        return f->z;
    return 0;
}



int main(int argc, char const *argv[])
{
    cin>>n;
    for (int i = 0; i < n; ++i){

        scanf("%d %d %d",&points[i].x,&points[i].y,&points[i].z);
    }

    for (int i = 0; i < MAXN; ++i)
        curx[i]=i;
    for (int i = 0; i < MAXN; ++i)
        cury[i]=i;
    int m;
    cin>>m;
    sort(points,points+n,cmpPoint);
    for (int i = 0; i < m; ++i)
    {
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==0){
            swap(curx[x],curx[y]);
        }else if(op==1)
            swap(cury[x],cury[y]);
        else{
            printf("%d\n", find(curx[x],cury[y]));
        }
    }
    return 0;
}

/*

#include <iostream>
#include <stdio.h>

using namespace std;




struct point
{
	int index;
	int value;
	point(int x, int y, int v){index = 100000*x+y; value = v;}
	point(){}
};

int main()
{
	int n, i, x,y,z, m, op;
	binarySearchTree<point> bst;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d", &x,&y,&z);
		bst.insert(point(x,y,z));

	}
	scanf("%d", &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &op,&x,&y);
		switch(op)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		}
	}

    return 0;
}
*/
