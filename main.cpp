//
// Created by syringa85 on 22. 6. 10.
//

#include<iostream>
#include<tuple>
#include<array>
#include<map>
#include<vector>
#include<cmath>
#include<ctime>

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

bool isPrime(Int n);
bool divisibleByN(Int M, Int N);
bool divisibleBy3(Int M);

void factorization(Int n);


int main(void) {
    
    factorization(2*2*2*3*3*3*3*5*7*13);

    return 0;
}

// Classifying;

bool isPrime(Int n) {
    
    Int posN = abs(n);
    if (posN == 2)
        return true;
    else if (posN % 2 == 0) {
        return false;
    }
    
    Int limit = static_cast<Int>(std::sqrt(posN));
    for (Int p = 3; p <= limit; p += 2) {
        if (posN % p == 0)
            return false;
        
    }
    return true;
}

bool divisibleBy3(Int M)
{   

    return false;
}

void factorization(Int n)
{

    std::map<Int, Int> factors;

    Int posN = abs(n);
    Int prime = 2;

    while (posN > 1) {
        if (posN % prime == 0) {
            factors[prime]++;
            posN /= prime; 
        }
        else {
            
            while (!isPrime(++prime));
        }
    }
    for (auto& factor : factors) {
        std::cout << factor.first << '^' << factor.second << std::endl;
    }
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
            std::array<Int, 2> xy = { 1, c / b };
        }
        else {
            ans.isOK = false;
        }
    }
    else {
        Int r0 = abs(a), r1 = abs(b);
        std::array<Int, 2> coeff0 = { 1, 0 }, coeff1 = { 0, 1 };




        while (r0 % r1 != 0) {
            std::printf("|r0: %d|\t|r1: %d|\t", r0, r1);
            Int q = r0 / r1;
            std::array<Int, 2> coeff2;



            coeff2[0] = coeff0[0] - 1 * q * coeff1[0];
            coeff2[1] = coeff0[1] - 1 * q * coeff1[1];

            Int r2 = r0 % r1;
            r0 = r1;
            r1 = r2;
            coeff0 = coeff1;
            coeff1 = coeff2;
            std::printf("|A coeff: %d|\t|B Coeff: %d|\t|q: %d\t|r1: %d|\n", coeff1[0], coeff1[1], q, r1);
        }

        gcd = r1;

        if (c % gcd == 0) {
            Int factor = c / gcd;
            coeff1[0] *= factor;
            coeff1[1] *= factor;
            ans.isOK = true;
            ans.answer = coeff1;

        }
        else {
            ans.isOK = false;
        }

    }
    return ans;


}