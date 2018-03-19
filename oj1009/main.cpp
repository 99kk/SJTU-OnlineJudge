#include <iostream>
#include <iomanip>
using namespace std;


//ac

int *date, *value, m, n;
int binarySearch(int t, int low, int high)
{
	int i = 0;
	if(t >= date[high]) return value[high];
	for(i = 1;  i <= high; i++)
	{
		if(t < date[i]) return value[i-1];
	}
	return value[high];


/*
	if(t == date[high]) return value[high];
	if(low == high || (date[low]<= t && t < date[low+1])  ) return value[low];

	int mid = (low+ high) / 2;
	if(t < date[mid]) return binarySearch(t, low, mid);
	else return binarySearch(t, mid, high);
		*/
}


int main()
{
	double totalProfit = 0;
    int *dateBuyAndSell, *numBuyAndSell, *buyOrSell, d,  i, j, t, a, v;
    cin>>m;
    dateBuyAndSell = new int[m]; numBuyAndSell = new int[m]; buyOrSell = new int[m];
    for(i = 0; i < m; i++)
		cin>>dateBuyAndSell[i]>>numBuyAndSell[i]>>buyOrSell[i];

	cin>>n;

	date = new int[n]; value = new int[n];
	for(i = 0; i < n; i++)
		cin>>date[i]>>value[i];

	for(i = 0; i < m; i++)
	{
		float curTrade = 0, stampDuty = 0 , commission = 0, transfer = 0, communication = 1.0;
		int price = binarySearch(dateBuyAndSell[i], 0, n-1);

		//cout<< dateBuyAndSell[i]<<" "<<price<<endl;

		curTrade = numBuyAndSell[i] * 100.0 * price;

		commission = 5 > curTrade*0.002 ? 5 : curTrade*0.002;

		transfer = numBuyAndSell[i] * 100.0 / 1000.0;

		stampDuty = curTrade * 0.001;

		if(buyOrSell[i] == 1)
		{
			totalProfit = totalProfit - curTrade - commission - transfer - communication;
		}
		else
		{
			totalProfit = totalProfit + curTrade - commission - transfer - communication - stampDuty;
		}
	}


	if(totalProfit >= 0)
	{
		cout.setf(ios::fixed);
		cout<<fixed<<setprecision(2)<<totalProfit<<endl;
	}

	else
	{
		cout.setf(ios::fixed);
		cout<<fixed<<setprecision(2)<<totalProfit<<endl;
	}

    return 0;
}
