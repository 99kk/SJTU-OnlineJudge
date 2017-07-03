#include <iostream>
#include <map>

//AC

using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    if(n <= k) return 0;
    int i, *a = new int[n+1];

	map<int, int> tags;
	map<int,int>::iterator itr;
    for(i = 1; i <= n; i++)
	{
		cin>>a[i];
	}


    int temNum = 0;

    int pre = 1, post, curLonest = 0;
    for(i = 1; temNum <= k and i <= n; i++)
	{
		itr = tags.find(a[i]);
		if(itr == tags.end())
		{
			temNum++;
			tags[a[i]] = 1;
		}
		else
		{
			tags[a[i]]++;
		}
	}
	post = i-1;

	while(post< n)
	{
		post++;
		itr = tags.find(a[post]);
		if( itr != tags.end())
		{
			tags[a[post]]++;
		}
		else
		{
			while(tags[a[pre]] > 1 and pre <= post)
			{
				if(curLonest < tags[a[pre]]) curLonest = tags[a[pre]];

				tags[a[pre]]--;
				pre++;
			}

			tags.erase(a[pre]);
			pre++;

			tags[a[post]] = 1;
		}
	}


for(  itr = tags.begin(); itr!=tags.end();itr++ )
			{
				if(itr->second > curLonest) curLonest = itr->second;
			}

	cout<<curLonest;





    return 0;
}
