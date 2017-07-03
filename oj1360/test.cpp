#include <iostream>
#include <algorithm>
using namespace std;

struct Period
{
    int start;
    int end;
};

//°´ÕÕendÅÅÐò
int cmp_period(const void* _a, const void* _b){
    Period* a = (Period*) _a;
    Period* b = (Period*) _b;
    //if((*a).end != (*b).end)
        return (*a).end - (*b).end;
       //else
     //   return (*a).start - (*b).start;
}

Period ps[100001];

int main(int argc, char const *argv[])
{

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i){

        cin>>ps[i].start>>ps[i].end;
    }

    qsort(ps,n,sizeof(Period),cmp_period);
    int ans = 1;
    int cur = ps[0].end;
    for (int i = 1; i < n; ++i)
    {
        if(ps[i].start >= cur){
            cur = ps[i].end;
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
