//
// Created by Yura Braiko on 20.12.16.
//

#ifndef ALEX_BORUVKA_H
#define ALEX_BORUVKA_H

#include "graph.h"

class Boruvka {
public:
    Boruvka(Graph *graph);
    void findTree();

private:
    Graph *graph;
};


#endif //ALEX_BORUVKA_H
