//
// Created by usman on 9/13/22.
//

#ifndef CPPALGORITHMS_POWER_H
#define CPPALGORITHMS_POWER_H

class Power {
    static const int MOD = 1000000007;
public:
    static int calculate_power(long long a, long long b) {
        if (b==0) {
            return 1;
        }

        a %= MOD;

        long long  val = calculate_power(a, b/2);
        val *= val;
        val %= MOD;
        if (b%2 ==1) {
            val = val * a % MOD;
        }
        // Write your code here.
        return (int) val;
    }

};

#endif //CPPALGORITHMS_POWER_H
