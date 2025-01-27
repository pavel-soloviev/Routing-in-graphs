#include "gtest/gtest.h"
#include "../src/algorithm.h"

TEST(ShortestPathTest, BasicTest) {
    std::vector<std::tuple<int, int, int, int, int>> edges = {
        {0, 3, 33, 0, 0},
        {1, 3, 94, 0, 0},
        {2, 1, 43, 4, 6}
    };
    int result = shortest_path(4, edges, 0, 2);
    EXPECT_EQ(result, 173);
}

