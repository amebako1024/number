//
// Created by syringa85 on 22. 6. 10.
//

#include<iostream>

using Int = int;

inline Int abs(Int a) {
	return a >= 0 ? a : -1 * a;
}


Int euclid(Int a, Int b);





int main(void) {

    
	return 0;
}

Int euclid(Int a, Int b)
{

	Int gcd;
	//gcd s.t >0


	if (a == 0 && b == 0) {
		gcd = -1;
	}
	else if (a == 0 && b != 0) {
		gcd = abs(b);
	}
	else {
		Int r0 = abs(a), r1 = abs(b);
		while (r1 != 0) {
			Int r2 = r0 % r1;
			r0 = r1;
			r1 = r2;
		}


		gcd = r0;
	}
	return gcd;


}