// tests/test_utils.cpp
#include "test_utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <tuple>

std::tuple<int, int, std::vector<std::tuple<int, int, int, int, int>>, int, int, int> parseTestFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл " + filename);
    }

    int N, E, start, end, expected_result;
    file >> N >> E;

    std::vector<std::tuple<int, int, int, int, int>> edges;
    for (int i = 0; i < E; ++i) {
	int u, v, t, g, r;
        file >> u >> v >> t >> g >> r;
	std::tuple<int, int, int, int, int> another_tuple(u, v, t, g, r);
        edges.push_back(another_tuple);
    }

    file >> start >> end;
    file >> expected_result;

    return {N, E, edges, start, end, expected_result};
}
