# Создаем исполняемый файл для основной программы
add_executable(traffic_lights main.cpp algorithm.cpp)

# Устанавливаем целевую директорию для бинарного файла
set_target_properties(traffic_lights PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

