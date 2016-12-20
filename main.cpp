#include <iostream>
#include "graph.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
    Graph graph("/Users/yurabraiko/dev/temp/c++/Alex/testGraph.txt");
    graph.print();
    return  0;
}