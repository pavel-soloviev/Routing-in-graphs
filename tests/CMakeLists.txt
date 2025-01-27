# Добавляем GoogleTest в проект
add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest googletest)

# Создаем исполняемый файл для тестов
add_executable(tests test_algorithm.cpp test_utils.cpp ${CMAKE_SOURCE_DIR}/src/algorithm.cpp)

# Подключаем GoogleTest к тестам
target_link_libraries(tests gtest gtest_main)

# Добавляем тесты
add_test(NAME AlgorithmTests COMMAND tests)

# Указываем полный путь к директории с данными
set(DATA_DIR "${CMAKE_SOURCE_DIR}/tests/data")

# Передаем путь в компилятор через макрос
add_compile_definitions(DATA_DIR="${DATA_DIR}")
