# Routing-in-graphs

## Формулировка задачи

**Дана** сеть дорог в виде ненаправленного разреженного связного графа с числом вершин N (2 <= N <= 1000) и числом рёбер E (1 <= E <= 10000). На рёбрах графа указано время t (1 <= t <= 100), за которое можно проехать участок дороги. На некоторых дорогах также стоят светофоры, которые не позволяют заехать на дорогу, пока горит красный свет (ехать по дороге и выехать с дороги они не мешают). Для каждого светофора известны 2 значения: g (0 <= g <= 10) - длительность зелёного света, r (0 <= r <= 10) - длительность красного света. В каждом периоде длины g+r сначала горит зелёный свет, затем красный. 
Предполагается, что для всех светофоров первый период начинается в момент начала поиска пути. Все значения времени указываются в одной величине.  

**Входные данные** представлены в виде файла следующей структуры:
Первая строка: число вершин N и число рёбер графа E

E строк вида: u v t g r (начальная вершина ребра, конечная вершина ребра, длительность проезда, длительность зелёного света, длительность красного света, если светофора нет, то g = r = 0).

Последняя строка: начальная точка start и конечная точка end для поиска пути.


## Цель проекта
Решить задачу и предоставить удобные средства для тестирования

## Установка и использование
1) Склонируйте репозиторий: git clone https://github.com/pavel-soloviev/Routing-in-graphs.git
2) Перейдите в директорию проекта: cd Routing-in-graphs/
3) В папке tests/data/ лежат файлы с тестами. Формат файла: входные данные и на следующей строчке ожидаемый результат. Пример

4 3  
0 3 33 0 0  
1 3 94 0 0  
2 1 43 4 6  
0 2  
173

Соответственно можно добавлять свои тесты строго в таком формате и с расширением файла .test  

4) Для сборки и тестирования выполните из корневой директории проекта следующие команды:  

mkdir build  
cd build  
cmake ..  
make  
cmake --build .  
ctest  

Для более подробного вывода тестирования выполните ctest с флагом -V

