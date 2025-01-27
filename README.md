# Routing-in-graphs

Формулировка задачи
**Дана** сеть дорог в виде ненаправленного разреженного связного графа с числом вершин N (2 <= N <= 1000) и числом рёбер E (1 <= E <= 10000). На рёбрах графа указано время t (1 <= t <= 100), за которое можно проехать участок дороги. На некоторых дорогах также стоят светофоры, которые не позволяют заехать на дорогу, пока горит красный свет (ехать по дороге и выехать с дороги они не мешают). Для каждого светофора известны 2 значения: g (0 <= g <= 10) - длительность зелёного света, r (0 <= r <= 10) - длительность красного света. В каждом периоде длины g+r сначала горит зелёный свет, затем красный. 
Предполагается, что для всех светофоров первый период начинается в момент начала поиска пути. Все значения времени указываются в одной величине.

Цель проекта
Решить задачу и предоставить удобные средства для тестирования
