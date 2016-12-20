//
// Created by Yura Braiko on 20.12.16.
//

#include <iostream>
#include "graph.h"
#include <fstream>

Graph::Graph(char *fileName) {
    char *from = new char[vertexNameLength];
    char *to = new char[vertexNameLength];
    int w;
    ifstream in(fileName);
    while (in >> from >> to >> w) {
        vertex *fromVertex = getVertexByName(from);
        fromVertex->connections.push_back(age(to, w));

        vertex *toVertex = getVertexByName(to);
        toVertex->connections.push_back(age(from, w));
    }
    for(int i=0;i<graph;i++){
        vertexName.push_back(graph[i].name);
    }
}

int Graph::getVertexCount() {
    return graph.size();
}

bool Graph::isAgeExist(char *a, char *b) {
    for (int i = 0; i < graph.size(); i++)
        if (strcmp(a, graph[i].name) == 0) {
            for (int j = 0; j < graph[i].connections.size(); j++) {
                if (strcmp(b, graph[i].connections[j].endpoint) == 0) {
                    return true;
                }

            }
            break;
        }
    return false;
}

int Graph::getWeight(char *a, char *b) {
    for (int i = 0; i < graph.size(); i++)
        if (strcmp(a, graph[i].name) == 0) {
            for (int j = 0; j < graph[i].connections.size(); j++) {
                if (strcmp(b, graph[i].connections[j].endpoint) == 0) {
                    return graph[i].connections[j].weight;
                }

            }
            break;
        }
    return -1;
}

vector<char *> Graph::getVertexNames() {
    return vertexName;
}

void Graph::print() {
    cout << endl << "\t";
    for (int i = 0; i < graph.size(); i++)
        cout << graph[i].name << "\t";
    cout << endl;
    for (int i = 0; i < graph.size(); i++) {
        cout << graph[i].name << "\t";
        for (int j = 0; j < graph.size(); j++) {
            for (int v = 0; v < graph[i].connections.size(); v++) {
                if (strcmp(graph[j].name, graph[i].connections[v].endpoint) == 0) {
                    cout << graph[i].connections[v].weight << "\t";
                    break;
                }
                if (v == graph[i].connections.size() - 1) {
                    cout << "0" << "\t";
                }
            }
        }
        cout << endl;
    }

}

Graph::vertex *Graph::getVertexByName(char *name) {
    for (int i = 0; i < graph.size(); i++)
        if (strcmp(graph[i].name, name) == 0)
            return &graph[i];
    graph.push_back(vertex(name));
    return &graph[graph.size() - 1];
}
