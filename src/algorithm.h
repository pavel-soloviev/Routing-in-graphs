#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <tuple>

int shortest_path(
    int n,
    const std::vector<std::tuple<int, int, int, int, int>>& edges,
    int start, int end);

#endif // ALGORITHM_H
