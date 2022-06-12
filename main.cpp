//
// Created by syringa85 on 22. 6. 10.
//

#include<iostream>
#include<tuple>
#include<array>

using Int = int;
using Int2d = std::array<Int, 2>;

template <typename T>
struct Answer {
    bool isOK;
    T answer;
};



inline Int abs(Int a) {
	return a >= 0 ? a : -1 * a;
}


Int euclid(Int a, Int b);

Answer<std::array<Int, 2>> solveLinIntEq(Int a, Int b, Int c);



int main(void) {
    Int a=12453, b=2347, c= 1;
    Answer<Int2d> ans = solveLinIntEq(a, b, c);
    if(ans.isOK) std::printf("%d, %d\n", ans.answer[0], ans.answer[1]);

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
		while (r0 % r1 != 0) {
			Int r2 = r0 % r1;
			r0 = r1;
			r1 = r2;
		}


		gcd = r1;
	}
	return gcd;


}


Answer<std::array<Int, 2>>  solveLinIntEq(Int a, Int b, Int c) {

    Answer<std::array<Int, 2>>  ans;


    Int gcd;

    if (a == 0 && b == 0) {
        ans.isOK = false;

    }
    else if (a == 0 && b != 0) {
        if (c % b == 0) {
            ans.isOK = true;
            std::array<Int, 2> xy = {1, c/b};
        } else {
            ans.isOK = false;
        }
    }
    else {
        Int r0 = abs(a), r1 = abs(b);
        std::array<Int, 2> coeff0 = {1, 0}, coeff1= {0, 1};




        while (r0 %r1 != 0) {
            std::printf("|r0: %d|\t|r1: %d|\t",r0, r1);
            Int q = r0 / r1;
            std::array<Int, 2> coeff2;



            coeff2[0] = coeff0[0] -1 * q * coeff1[0];
            coeff2[1] = coeff0[1] -1 * q * coeff1[1];

            Int r2 = r0 % r1;
            r0 = r1;
            r1 = r2;
            coeff0 = coeff1;
            coeff1 = coeff2;
            std::printf("|A coeff: %d|\t|B Coeff: %d|\t|q: %d\t|r1: %d|\n", coeff1[0], coeff1[1], q, r1);
        }

        gcd = r1;

        if ( c % gcd == 0) {
            Int factor = c / gcd;
            coeff1[0] *= factor;
            coeff1[1] *= factor;
            ans.isOK = true;
            ans.answer = coeff1;

        } else {
            ans.isOK = false;
        }

    }
    return ans;


}