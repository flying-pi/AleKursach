//
// Created by Yura Braiko on 20.12.16.
//

#include "Boruvka.h"


Boruvka::Boruvka(Graph *graph) {
this->graph = graph;
}

void Boruvka::findTree() {
/*
 * 1 - создаешь новый обьект графа который будет являтся деревом
 * 2 - в классе граффа создаешь метод для добавление новой точки и для добавление соединение(метод принимает куда
 * откуда и вес,  метод должен не допускать дублирования,  вставить там проверку)
 * 3 -  пишешь функцию в класе граффа которая принимает как указатели ссылку на имя и ссылку на вес и возражает булевое значение
 * смысл функции в переданые ссылочные переменные записать имя ендпоинта и его вес.  Возращает правду если минимальное соединение есть
 * и лож в противном случае(если где-то будет лож - то нужно просто стопать алгоритм потому что это означает что у тебя просто висит
 * точка и что дерево там вообще построить нельзя
 * 4 -  на этом этапе у тебя в граффе должны образоватся компоненты(в новом графе).  Пишешь функцию в классе граффа для поиска
 * компонент - вовзращать должна vector<vector<char*>> внутрений вектор  - последовательность имен вершин в компоненте
 * а внешний  - список всех компонент.
 * 5 - в случае если у тебя компонент 1 штука то остановить алгоритм - это твое дерево.
 * 6 - взять две первые компоненты и перебрать все возможные соединение с точек первые в точки второй,  например
 * 1:{A,D} 2:{C,B} нужно перебрать возможные связи между AC,AB,DC,DB. Если в результате перебора не нашлось ни одного соединения
 * то опять остонавливать алгоритм с ошибкой что не связаный граф. Если что функция веса у нас есть))
 * 6.1 после того как была найдена связь две первых компоненты сливаются в одну и идем к пункту 5.
 */
}