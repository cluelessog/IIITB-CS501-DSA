/*
 * iterativeexponentiation.cpp
 *
 *  Created on: 13-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;

int pow(int x,int n){

	int y = 1;
	while(n>0){
		if( n%2 != 0){ // when n is even, we do nothing, but when it is odd, extra multiplication by x is needed.
			y = y*x;
		}
		x = x*x; // square it anyway
		n /= 2; // half the number (think in binary way, every division knocks off the rightmost bit)
	}
	return y; // take 101 = 5 as example and iterate over the while loop to verify
}

int main(){
	int x,n;
	cin >> x >> n;
	int result = pow(x,n);
	cout << result << endl;
}





