#include "gtest/gtest.h"
#include "../src/algorithm.h"
#include "test_utils.h"
#include <filesystem>
#include <string>
#include <vector>

// Структура для хранения данных теста
struct TestData {
    std::string filename;
    int N, E, start, end, expected_result;
    std::vector<std::tuple<int, int, int, int, int>> edges;

    TestData(const std::string& filename, int N, int E, int start, int end, int expected_result, const std::vector<std::tuple<int, int, int, int, int>>& edges)
        : filename(filename), N(N), E(E), start(start), end(end), expected_result(expected_result), edges(edges) {}
};

// Список тестов
std::vector<TestData> test_data;

// Функция для добавления тестов из директории
void addTestsFromDirectory(const std::string& directory) {
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".test") {
            std::string filename = entry.path().string();

            auto [N, E, edges, start, end, expected_result] = parseTestFile(filename);

	    std::cout << "Parsed test file successfully:\n";
	    std::cout << "Filename:" << filename << std::endl;
            std::cout << "N: " << N << ", E: " << E << ", start: " << start << ", end: " << end << "\n";


	    TestData data(filename, N, E, start, end, expected_result, edges);
            test_data.push_back(data);
        }
    }
}

// Создаем отдельный тест для каждого файла
class ShortestPathTest : public ::testing::TestWithParam<TestData> {};

TEST_P(ShortestPathTest, TestFromFile) {
    const TestData& data = GetParam();
    int result = shortest_path(data.N, data.edges, data.start, data.end);

    std::cout << "File: " << data.filename << "\n";
    std::cout << "Computed result: " << result << ", Expected result: " << data.expected_result << "\n";

    EXPECT_EQ(result, data.expected_result);
}

// Генерируем тесты
INSTANTIATE_TEST_SUITE_P(FromFiles, ShortestPathTest, ::testing::ValuesIn(test_data));

// Загружаем данные для тестов перед выполнением
int main(int argc, char** argv) {

    addTestsFromDirectory(DATA_DIR);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
