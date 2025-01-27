# Добавляем GoogleTest в проект
add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest googletest)

# Создаем исполняемый файл для тестов
add_executable(tests test_algorithm.cpp ${CMAKE_SOURCE_DIR}/src/algorithm.cpp)

# Подключаем GoogleTest к тестам
target_link_libraries(tests gtest gtest_main)

# Добавляем тесты
add_test(NAME AlgorithmTests COMMAND tests)

