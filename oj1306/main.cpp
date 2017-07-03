#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1010
#define eps 1e-7

//ac

using namespace std;
int n;
double alpha;
struct PointNode
{
    double x,y;
    PointNode(){}
    PointNode(double _x,double _y):x(_x),y(_y){}
    PointNode operator + (const PointNode &a)
    {return PointNode(x+a.x,y+a.y);}
    PointNode operator - (const PointNode &a)
    {return PointNode(x-a.x,y-a.y);}
    PointNode operator * (double rate)
    {return PointNode(x*rate,y*rate);}
    double operator * (const PointNode &a)
    {return x*a.x+y*a.y;}
    double operator ^ (const PointNode &a)
    {return x*a.y-y*a.x;}
};
struct Line
{
    PointNode p,v;
    double k,b;
    Line(){}
    Line(PointNode _a,PointNode _b):p(_a),v(_b-_a)
    {
        k=((p+v).y-p.y)/((p+v).x-p.x);
        b=p.y-k*p.x;
    }
    double pt(double x)
    {
        return k*x+b;
    }
}line[N<<1];
struct Circle
{
    PointNode p;
    double R;
    Circle(){}
    Circle(PointNode _p,double _R):p(_p),R(_R){}
}circles[N];
struct Interval
{
    double l,r;
    Interval(){}
    Interval(double _l,double _r):l(_l),r(_r){}
    friend bool operator < (Interval a,Interval b)
    {
        if(a.l==b.l)return a.r<b.r;
        return a.l<b.l;
    }
}interval[N<<2];

int intervalNum,lines;
void Get_Lines(Circle a,Circle b)
{
    if(fabs(a.p.x-b.p.x)<fabs(a.R-b.R))return;
    if(a.R==b.R)
    {
        line[++lines]=Line(PointNode(a.p.x,a.R),PointNode(b.p.x,b.R));
    }else if(a.R<b.R)
    {
        double height1=sqrt((a.p.x-b.p.x)*(a.p.x-b.p.x)-(b.R-a.R)*(b.R-a.R));
        double height2=b.R*height1/(a.p.x-b.p.x);
        double length1=sqrt(b.R*b.R-height2*height2);
        PointNode aaaa=b.p+PointNode(length1,height2);
        PointNode bbbb=a.p+PointNode(length1*a.R/b.R,height2*a.R/b.R);
        line[++lines]=Line(aaaa,bbbb);
    }else
    {
        double height1=sqrt((a.p.x-b.p.x)*(a.p.x-b.p.x)-(a.R-b.R)*(a.R-b.R));
        double height2=a.R*height1/(a.p.x-b.p.x);
        double length1=sqrt(a.R*a.R-height2*height2);
        PointNode aaaaaa=a.p+PointNode(-length1,height2);
        PointNode bbbbbb=b.p+PointNode(-length1*b.R/a.R,height2*b.R/a.R);
        line[++lines]=Line(bbbbbb,aaaaaa);
    }
}
double getf(double x)
{
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        double dis=fabs(x-circles[i].p.x);
        if(dis>circles[i].R)continue;
        double height=sqrt(circles[i].R*circles[i].R-dis*dis);
        ans=max(ans,height);
    }
    for(int i=1;i<=lines;i++)
    {
        if(x>=line[i].p.x&&x<=(line[i].p+line[i].v).x)
        {
            ans=max(ans,line[i].pt(x));
        }
    }
    return ans;
}
double calculate(double fl,double fm,double fr)
{
    return (fl+fr+4*fm)/6;
}
double Simpson(double l,double mid,double r,double fl,double fm,double fr,double s)
{
    double lm=(l+mid)/2,rm=(mid+r)/2;
    double flm=getf(lm),frm=getf(rm);
    double g1=calculate(fl,flm,fm)*(mid-l),g2=calculate(fm,frm,fr)*(r-mid);
    if(fabs(g1+g2-s)<eps)return s;
    else return Simpson(l,lm,mid,fl,flm,fm,g1)+Simpson(mid,rm,r,fm,frm,fr,g2);
}
double h[N],sums[N];
int main()
{
    scanf("%d%lf",&n,&alpha);
    for(int i=n+1;i>=1;i--)scanf("%lf",&h[i]);
    for(int i=n+1;i>=1;i--)sums[i]=sums[i+1]+h[i];
    for(int i=n;i>=1;i--)scanf("%lf",&circles[i].R);
    double l=0x7f7f7f7f,r=0;
    PointNode thetop(sums[1]*(1/tan(alpha)),0);
    r=max(r,thetop.x);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            circles[1].p=PointNode(sums[2]*(1/tan(alpha)),0);
            l=min(circles[1].p.x-circles[1].R,l);
            r=max(circles[1].p.x+circles[1].R,r);
            if(circles[1].p.x+circles[1].R>=thetop.x)continue;
            double length=circles[1].R*circles[1].R/(thetop.x-circles[1].p.x);
            double height=sqrt(circles[1].R*circles[1].R-length*length);
            line[++lines]=Line(PointNode(circles[1].p.x+length,height),thetop);
        }else
        {
            circles[i].p=PointNode(sums[i+1]*(1/tan(alpha)),0);
            l=min(circles[i].p.x-circles[i].R,l);
            r=max(circles[i].p.x+circles[i].R,r);
            Get_Lines(circles[i-1],circles[i]);
        }
    }
    double mid=(l+r)/2;
    double fl=getf(l),fr=getf(r),fm=getf(mid);
    double ans=Simpson(l,mid,r,fl,fm,fr,calculate(fl,fm,fr)*(r-l));
    printf("%.2lf\n",2*ans);
}
