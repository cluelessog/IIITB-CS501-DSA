// computing x^n in logn complexity
//============================================================================
// Name        : Hela.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int pow(int x,int n){

	if(n == 0){
		return 1;
	}else if(n%2==0){  //if n is even, simply do square of it.
		return pow(x*x,n/2);
	}else{
		return x*pow(x*x,n/2); // if n is odd, we need to multiply extra by one x
	}
}
int main() {
	int x,n;
	cin >> x >> n;
	int result = pow(x,n);
	cout<< result << endl;
	return 0;
}
