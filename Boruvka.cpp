//
// Created by Yura Braiko on 20.12.16.
//

#include <iostream>
#include "Boruvka.h"


Boruvka::Boruvka(Graph *graph) {
    this->graph = graph;
}

Graph *Boruvka::findTree() {
    Graph *tree = new Graph();
    vector<char *> vertexes = graph->getVertexNames();
    for (int i = 0; i < vertexes.size(); i++)
        tree->addVertex(vertexes[i]);

    char *connectionPoint = new char[10];
    int w;
    for (int i = 0; i < vertexes.size(); i++) {
        if (!graph->getMinValue(vertexes[i], connectionPoint, w)) {
            cout << endl << "ERROR!!! this is not linked graph";
            return nullptr;
        }
        tree->addAge(vertexes[i], connectionPoint, w);
    }

    tree->print();

    vector<vector<char *>> components = tree->getComonents();
    for (int i = 0; i < components.size(); i++) {
        for (int j = 0; j < components[i].size(); j++)
            cout << components[i][j] << "\t";
        cout << endl;
    }
    while (components.size() > 1) {
        char *minFrom;
        char *minTo;
        int minW = -1;
        for (int i = 0; i < components[0].size(); i++) {
            for (int j = 0; j < components[1].size(); j++) {
                cout << components[0][i] << " :: " << components[1][j] << endl;
                w = graph->getWeight(components[0][i], components[1][j]);
                if (w == -1)
                    continue;
                if(minW == -1 || w<minW){
                    minW = w;
                    minFrom = components[0][i];
                    minTo = components[1][j];
                }
            }
        }
        if(minW == -1){
            cout << "ERROR!! this is not linked graph";
            return nullptr;
        }
        tree->addAge(minFrom,minTo,minW);
        for(int i=0;i<components[0].size();i++)
            components[1].push_back(components[0][i]);
        components.erase(components.begin());
        return tree;
    }



/*

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
