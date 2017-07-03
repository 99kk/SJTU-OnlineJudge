#include <iostream>

using namespace std;
//AC
int main()
{
	int M, T, U, F, D, i, time = 0, steps = 0;
	char type;
	cin>>M>>T>>U>>F>>D;

	int ud = D + U, ff = 2 * F;

	for(i = 0; i < T; i++)
	{
		cin>>type;
		switch(type)
		{
			case 'f':{time+= ff;break;}
			default: time+= ud;
		}
		if(time <= M) steps++;

	}
	cout<<steps;
    return 0;
}
