#include <iostream>
#include <vector>
#include <tuple>
#include "algorithm.h"

int main() {
    int n, e;
    std::cin >> n >> e;

    std::vector<std::tuple<int, int, int, int, int>> edges; // (u, v, t, g, r)
    edges.reserve(e);

    for (int i = 0; i < e; ++i) {
        int u, v, t, g, r;
        std::cin >> u >> v >> t >> g >> r;
        edges.emplace_back(u, v, t, g, r);
    }

    int start, end;
    std::cin >> start >> end;

    int result = shortest_path(n, edges, start, end);
    std::cout << result << std::endl;

    return 0;
}
