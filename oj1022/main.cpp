#include <iostream>

using namespace std;


//AC
// 쳲������������ʣ�����һ��������������������һ����������

int main()
{
	long long N;
	cin>>N;
	int n = N % 2040;

	int *fib = new int[n+1];
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;

	for(int i = 2; i <= n; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
		fib[i] %=2010;
	}


		cout<<fib[n]<<endl;


    return 0;
}
