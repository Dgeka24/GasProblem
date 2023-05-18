#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MAX = 1e18;
struct edge {
    ll from, to, cost, time;
    edge(ll f_, ll to_, ll cost_, ll time_) {
        from = f_;
        to = to_;
        cost = cost_;
        time = time_;
    }
};
ll n, m, s;
vector<vector<edge>> g;
ll mx_cost = 0;
vector<ll> cost;
vector<ll> duration;
vector<ll> res;
void dijkstra() {
    vector<vector<ll>> dist(n + 1, vector<ll>(mx_cost + 1, MAX));
    priority_queue<pair<ll, pair<ll,ll>>> q;
    s = min(s, mx_cost);
    dist[1][s] = 0;
    q.push({0, {1, s}});
    while(!q.empty()) {
        auto p = q.top();
        q.pop();
        ll i = p.second.first;
        ll j = p.second.second;
        if (p.first > dist[i][j]) {
            continue;
        }
        for (auto e : g[i]) {
            if (e.cost <= j && dist[e.to][j - e.cost] > dist[i][j] + e.time) {
                dist[e.to][j - e.cost] = dist[i][j] + e.time;
                q.push({-dist[e.to][j - e.cost], {e.to, j - e.cost}});
            }
        }
        ll new_fuel = j;
        ll new_time = 0;
        while (new_fuel <= mx_cost) {
            new_fuel += cost[i];
            new_time += duration[i];
            if (new_fuel >= mx_cost) {
                new_fuel = mx_cost;
                if (dist[i][new_fuel] > dist[i][j] + new_time) {
                    dist[i][new_fuel] = dist[i][j] + new_time;
                    q.push({-dist[i][new_fuel], {i, new_fuel}});
                }
                break;
            }
            if (dist[i][new_fuel] > dist[i][j] + new_time) {
                dist[i][new_fuel] = dist[i][j] + new_time;
                q.push({-dist[i][new_fuel], {i, new_fuel}});
            }
        }
    }
    for (ll i = 2; i <= n; i++) {
        ll ans = MAX;
        for (ll j = 0; j <= mx_cost; j++) {
            ans = min(ans, dist[i][j]);
        }
        cout << ans << "\n";
    }
}

void clear_all() {
    g.clear();
    mx_cost = 0;
    cost.clear();
    duration.clear();
    res.clear();
}

void solve(int test_number){
    clear_all();
    const std::string filename_input = "tests/input/input" + std::to_string(test_number) + ".txt";
    const std::string filename_output = "tests/output/output" + std::to_string(test_number) + ".txt";
    freopen(filename_input.c_str(), "r", stdin);
    freopen(filename_output.c_str(), "w", stdout);
    cin >> n >> m >> s;
    g.resize(n + 1);
    for (ll i = 0; i < m; i++) {
        ll from, to, cost1, time;
        cin >> from >> to >> cost1 >> time;
        mx_cost = max(mx_cost, cost1);
        g[from].emplace_back(from, to, cost1, time);
        g[to].emplace_back(to, from, cost1, time);
    }
    mx_cost *= (n - 1);
    cost.resize(n + 1);
    duration.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> cost[i];
        cin >> duration[i];
    }
    res.resize(n + 1);
    dijkstra();
}


