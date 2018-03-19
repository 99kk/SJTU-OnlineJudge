#include <iostream>

using namespace std;
//ac

int main()
{
    int i, budget[13];
    for(i = 1; i<= 12; i++)
		cin>>budget[i];

	int cash = 0, saved = 0;

	for(i = 1; i<= 12; i++)
	{
		cash += 300;
		cash -= budget[i];
		if(cash < 0)
		{
			cout<< -i<<endl;
			return 0;
		}
		saved += cash / 100 * 100;
		cash %= 100;
	}

	cout<< saved * 1.2 + cash<<endl;

    return 0;
}
