#pragma once
#include <bits/stdc++.h>

const int MAX_N = 50;
const int MAX_M = 2 * MAX_N;
const int MAX_START_FUEL = 1000 * 1000 * 1000;
const int MAX_COST = 50;
const int MAX_TIME = 1000 * 1000 * 1000;
const int MAX_FUEL = 1000 * 1000 * 1000;
const int MAX_DURATION = 1000 * 1000 * 1000;

void gen_test(int test_number) {
    std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    std::ofstream output;
    output.open(filename_input);
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(2, MAX_N);
    int n = nodes_amount_gen(gen);
    std::uniform_int_distribution<> edges_amount_gen(n - 1, std::min(MAX_M, n * (n - 1) / 2));
    int m = edges_amount_gen(gen);
    std::uniform_int_distribution<> start_amount_gen(0, MAX_START_FUEL);
    int s = start_amount_gen(gen);
    std::set<std::pair<int, int>> free_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            free_edges.insert(std::make_pair(i, j));
        }
    }
    output << n << " " << m << " " << s << "\n";
    std::uniform_int_distribution<> cost(1, MAX_COST);
    std::uniform_int_distribution<> roadtime(1, MAX_TIME);
    for (int i = 2; i <= n; i++) {
        std::uniform_int_distribution<> vertex(1, i - 1);
        int j = vertex(gen);
        free_edges.erase(std::make_pair(i, j));
        int c = cost(gen);
        int t = roadtime(gen);
        output << j << " " << i << " " << c << " " << t << "\n";
    }
    m -= n - 1;
    while (m > 0) {
        int pos = gen() % free_edges.size();
        auto it = free_edges.begin();
        std::advance(it, pos);
        std::pair<int, int> edge = *it;
        int c = cost(gen);
        int t = roadtime(gen);
        output << edge.first << " " << edge.second << " " << c << " " << t << "\n";
        m--;
    }
    std::uniform_int_distribution<> fuel(1, MAX_FUEL);
    std::uniform_int_distribution<> duration(1, MAX_DURATION);
    for (int i = 1; i <= n; i++) {
        int f = fuel(gen);
        int d = duration(gen);
        output << f << " " << d << "\n";
    }
    output.close();

}
