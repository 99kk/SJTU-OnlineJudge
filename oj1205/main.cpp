#include <iostream>

using namespace std;

//AC

int Ackerman(int m, int n)
{
	if(m !=0 and n != 0) return Ackerman(m-1, Ackerman(m,n-1));
	if(m != 0 and n == 0) return Ackerman(m-1, 1);
	return n+1;
}



int main()
{
    int m,n;
    cin>>m>>n;
    cout<<Ackerman(m,n);
    return 0;
}
