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
        free_edges.erase(std::make_pair(j, i));
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

void gen_small_test(int test_number) {
    int minimum_n = 2;
    int maximum_n = 10;
    int minimum_start_fuel = 0;
    int maximum_start_fuel = 50;
    int minimum_cost = 1;
    int maximum_cost = 10;
    int minimum_roadtime = 1;
    int maximum_roadtime = 10;
    int minimum_fuel = 1;
    int maximum_fuel = 10;
    int minimum_duration = 1;
    int maximum_duration = 10;
    std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    std::ofstream output;
    output.open(filename_input);
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(minimum_n, maximum_n);
    int n = nodes_amount_gen(gen);
    std::uniform_int_distribution<> edges_amount_gen(n - 1, std::min(MAX_M, n * (n - 1) / 2));
    int m = edges_amount_gen(gen);
    std::uniform_int_distribution<> start_amount_gen(0, maximum_start_fuel);
    int s = start_amount_gen(gen);
    std::set<std::pair<int, int>> free_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            free_edges.insert(std::make_pair(i, j));
        }
    }
    output << n << " " << m << " " << s << "\n";
    std::uniform_int_distribution<> cost(minimum_cost, maximum_cost);
    std::uniform_int_distribution<> roadtime(minimum_roadtime, maximum_roadtime);
    for (int i = 2; i <= n; i++) {
        std::uniform_int_distribution<> vertex(1, i - 1);
        int j = vertex(gen);
        free_edges.erase(std::make_pair(j, i));
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
    std::uniform_int_distribution<> fuel(minimum_fuel, maximum_fuel);
    std::uniform_int_distribution<> duration(minimum_duration, maximum_duration);
    for (int i = 1; i <= n; i++) {
        int f = fuel(gen);
        int d = duration(gen);
        output << f << " " << d << "\n";
    }
    output.close();
}

void gen_bamboo_test(int test_number) {
    int minimum_n = 6;
    int maximum_n = MAX_N;
    int minimum_start_fuel = 0;
    int maximum_start_fuel = MAX_FUEL;
    int minimum_cost = 1;
    int maximum_cost = MAX_COST;
    int minimum_roadtime = 1;
    int maximum_roadtime = MAX_TIME;
    int minimum_fuel = 1;
    int maximum_fuel = MAX_FUEL;
    int minimum_duration = 1;
    int maximum_duration = MAX_DURATION;
    std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    std::ofstream output;
    output.open(filename_input);
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(minimum_n, maximum_n);
    int n = nodes_amount_gen(gen);
    std::uniform_int_distribution<> edges_amount_gen(n - 1, n - 1 + 5);
    int m = edges_amount_gen(gen);
    std::uniform_int_distribution<> start_amount_gen(0, maximum_start_fuel);
    int s = start_amount_gen(gen);
    std::set<std::pair<int, int>> free_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            free_edges.insert(std::make_pair(i, j));
        }
    }
    output << n << " " << m << " " << s << "\n";
    std::uniform_int_distribution<> cost(minimum_cost, maximum_cost);
    std::uniform_int_distribution<> roadtime(minimum_roadtime, maximum_roadtime);
    for (int i = 2; i <= n; i++) {
        int j = i - 1;
        free_edges.erase(std::make_pair(j, i));
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
    std::uniform_int_distribution<> fuel(minimum_fuel, maximum_fuel);
    std::uniform_int_distribution<> duration(minimum_duration, maximum_duration);
    for (int i = 1; i <= n; i++) {
        int f = fuel(gen);
        int d = duration(gen);
        output << f << " " << d << "\n";
    }
    output.close();
}

void gen_cactus_test(int test_number) {
    int minimum_n = 10;
    int maximum_n = MAX_N;
    int minimum_start_fuel = 0;
    int maximum_start_fuel = MAX_FUEL;
    int minimum_cost = 1;
    int maximum_cost = MAX_COST;
    int minimum_roadtime = 1;
    int maximum_roadtime = MAX_TIME;
    int minimum_fuel = 1;
    int maximum_fuel = MAX_FUEL;
    int minimum_duration = 1;
    int maximum_duration = MAX_DURATION;
    std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    std::ofstream output;
    output.open(filename_input);
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(minimum_n, maximum_n);
    int n = nodes_amount_gen(gen);
    std::uniform_int_distribution<> edges_amount_gen(n - 1, n - 1 + 10);
    int m = edges_amount_gen(gen);
    std::uniform_int_distribution<> start_amount_gen(0, maximum_start_fuel);
    int s = start_amount_gen(gen);
    std::set<std::pair<int, int>> free_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            free_edges.insert(std::make_pair(i, j));
        }
    }
    output << n << " " << m << " " << s << "\n";
    std::uniform_int_distribution<> cost(minimum_cost, maximum_cost);
    std::uniform_int_distribution<> roadtime(minimum_roadtime, maximum_roadtime);
    for (int i = 2; i <= n; i++) {
        int j = 1;
        free_edges.erase(std::make_pair(j, i));
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
    std::uniform_int_distribution<> fuel(minimum_fuel, maximum_fuel);
    std::uniform_int_distribution<> duration(minimum_duration, maximum_duration);
    for (int i = 1; i <= n; i++) {
        int f = fuel(gen);
        int d = duration(gen);
        output << f << " " << d << "\n";
    }
    output.close();
}

void gen_dense_test(int test_number) {
    int minimum_n = 10;
    int maximum_n = 20;
    int minimum_start_fuel = 0;
    int maximum_start_fuel = MAX_FUEL;
    int minimum_cost = 1;
    int maximum_cost = MAX_COST;
    int minimum_roadtime = 1;
    int maximum_roadtime = MAX_TIME;
    int minimum_fuel = 1;
    int maximum_fuel = MAX_FUEL;
    int minimum_duration = 1;
    int maximum_duration = MAX_DURATION;
    std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    std::ofstream output;
    output.open(filename_input);
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(minimum_n, maximum_n);
    int n = nodes_amount_gen(gen);
    std::uniform_int_distribution<> edges_amount_gen(n * (n - 1) / 2, n * (n - 1) / 2);
    int m = edges_amount_gen(gen);
    std::uniform_int_distribution<> start_amount_gen(0, maximum_start_fuel);
    int s = start_amount_gen(gen);
    std::set<std::pair<int, int>> free_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            free_edges.insert(std::make_pair(i, j));
        }
    }
    output << n << " " << m << " " << s << "\n";
    std::uniform_int_distribution<> cost(minimum_cost, maximum_cost);
    std::uniform_int_distribution<> roadtime(minimum_roadtime, maximum_roadtime);
    for (int i = 2; i <= n; i++) {
        int j = 1;
        free_edges.erase(std::make_pair(j, i));
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
    std::uniform_int_distribution<> fuel(minimum_fuel, maximum_fuel);
    std::uniform_int_distribution<> duration(minimum_duration, maximum_duration);
    for (int i = 1; i <= n; i++) {
        int f = fuel(gen);
        int d = duration(gen);
        output << f << " " << d << "\n";
    }
    output.close();
}

void gen_full_test(int test_number) {
    int minimum_n = 45;
    int maximum_n = MAX_N;
    int minimum_start_fuel = 0;
    int maximum_start_fuel = MAX_FUEL;
    int minimum_cost = 1;
    int maximum_cost = MAX_COST;
    int minimum_roadtime = 1;
    int maximum_roadtime = MAX_TIME;
    int minimum_fuel = 1;
    int maximum_fuel = MAX_FUEL;
    int minimum_duration = 1;
    int maximum_duration = MAX_DURATION;
    std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    std::ofstream output;
    output.open(filename_input);
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(minimum_n, maximum_n);
    int n = nodes_amount_gen(gen);
    std::uniform_int_distribution<> edges_amount_gen(n - 1, std::min(MAX_M, n * (n - 1) / 2));
    int m = edges_amount_gen(gen);
    std::uniform_int_distribution<> start_amount_gen(0, maximum_start_fuel);
    int s = start_amount_gen(gen);
    std::set<std::pair<int, int>> free_edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            free_edges.insert(std::make_pair(i, j));
        }
    }
    output << n << " " << m << " " << s << "\n";
    std::uniform_int_distribution<> cost(minimum_cost, maximum_cost);
    std::uniform_int_distribution<> roadtime(minimum_roadtime, maximum_roadtime);
    for (int i = 2; i <= n; i++) {
        int j = 1;
        free_edges.erase(std::make_pair(j, i));
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
    std::uniform_int_distribution<> fuel(minimum_fuel, maximum_fuel);
    std::uniform_int_distribution<> duration(minimum_duration, maximum_duration);
    for (int i = 1; i <= n; i++) {
        int f = fuel(gen);
        int d = duration(gen);
        output << f << " " << d << "\n";
    }
    output.close();
}