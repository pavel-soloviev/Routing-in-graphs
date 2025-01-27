// tests/test_utils.h
#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <vector>
#include <string>
#include <tuple>


// Функция для парсинга тестового файла
std::tuple<int, int, std::vector<std::tuple<int, int, int, int, int>>, int, int, int> parseTestFile(const std::string& filename);

#endif // TEST_UTILS_H

