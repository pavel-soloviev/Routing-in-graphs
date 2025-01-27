cmake_minimum_required(VERSION 3.10)

# Название проекта
project(TrafficLights)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл для основного приложения
add_subdirectory(src)

# Подключаем тесты
enable_testing()
add_subdirectory(tests)

