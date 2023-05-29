#include <bits/stdc++.h>
#include "gentest.cpp"
#include "solution.cpp"

int main() {
    for (int test = 3; test <= 10; test++) {
        gen_small_test(test);
        solve(test);
    }
    for (int test = 11; test <= 20; test++) {
        gen_bamboo_test(test);
        solve(test);
    }
    for (int test = 21; test <= 30; test++) {
        gen_cactus_test(test);
        solve(test);
    }
    for (int test = 31; test <= 40; test++) {
        gen_dense_test(test);
        solve(test);
    }
    for (int test = 41; test <= 60; test++) {
        gen_full_test(test);
        solve(test);
    }


    return 0;
}
