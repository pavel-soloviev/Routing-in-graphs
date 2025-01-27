#include "algorithm.h"
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Функция для нахождения кратчайшего пути с учётом светофоров
int shortest_path(int n, const std::vector<std::tuple<int, int, int, int, int>>& edges, int start, int end) {

    //список смежности
    std::vector<std::vector<std::tuple<int, int, int, int>>> graph(n); // (сосед, время, зелёный свет, красный свет)
    for (const auto& edge : edges) {
        int u, v, t, g, r;
        std::tie(u, v, t, g, r) = edge;
        graph[u].emplace_back(v, t, g, r);
        graph[v].emplace_back(u, t, g, r);
    }

    // Массив минимального времени для каждой вершины
    std::vector<int> min_time(n, INF);
    min_time[start] = 0;

    using pii = std::pair<int, int>; //пара <int, int> для краткости
    std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [current_time, current_node] = pq.top();
        pq.pop();

        if (current_time > min_time[current_node]) {
            continue;
        }

        for (const auto& neighbor_info : graph[current_node]) {
            int neighbor, travel_time, green, red;
            std::tie(neighbor, travel_time, green, red) = neighbor_info;

            // Рассчёт времени ожидания на светофоре
            int period = green + red;
            int wait_time = 0;
            if (period > 0) { // Если светофор есть
                int time_in_cycle = current_time % period;
                if (time_in_cycle >= green) { // На красном свете
                    wait_time = period - time_in_cycle;
                }
            }

            // Общее время до соседа
            int neighbor_time = current_time + travel_time + wait_time;

            if (neighbor_time < min_time[neighbor]) {
                min_time[neighbor] = neighbor_time;
                pq.emplace(neighbor_time, neighbor);
            }
        }
    }

    if (min_time[end] == INF) {
        return -1;
    } else {
        return min_time[end];
    }
}
