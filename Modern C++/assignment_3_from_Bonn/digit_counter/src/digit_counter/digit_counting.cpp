#include"./digit_counting.h"
#include<cmath>

namespace digit{
    
    double Warp(double number, double factor){
        number = number + factor;
        number = number - factor;
        return number;
    }

    int CountSameSignificantDigits(double a, double b){
        if(a>1 && b>1){
            return -1;
        }

        if(a>1 || b>1){
            return 0;
        }

        if (a<1 && b<1)
        {
            a = std::fabs(a);
            b = std::fabs(b);
            int same = 0;

            for (int i = 1; i <= 100; i++)
            {   
                double after_mul_a = a*10.0;
                double after_mul_b = b*10.0;
                int after_mul_a_int = after_mul_a;
                int after_mul_b_int = after_mul_b;
                if(after_mul_a_int !=after_mul_b_int){
                    break;
                }
                same +=1;
                double a = after_mul_a- (double) after_mul_a_int;
                double b = after_mul_b- (double) after_mul_b_int;
            }

            return same;
        }
        
        
    }

}