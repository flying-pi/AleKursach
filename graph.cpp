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
    for (int i = 0; i < graph.size(); i++) {
        vertexName.push_back(graph[i].name);
    }
}

Graph::Graph() {

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
    vertexName.clear();
    for(int i=0;i<graph.size();i++)
        vertexName.push_back(graph[i].name);
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

void Graph::addVertex(char *newPoint) {
    graph.push_back(newPoint);
}

void Graph::addAge(char *from, char *to, int w) {
    vertex *fromVertex = getVertexByName(from);
    vertex *toVertex = getVertexByName(to);

    for (int i = 0; i < fromVertex->connections.size(); i++) {
        if (strcmp(fromVertex->connections[i].endpoint, to) == 0)
            return;
    }

    fromVertex->connections.push_back(age(to, w));
    toVertex->connections.push_back(age(from, w));
}

bool Graph::getMinValue(char *target, char *result, int &w) {
    vertex *targetVertex = getVertexByName(target);
    if (targetVertex->connections.size() == 0)
        return false;
    w = targetVertex->connections[0].weight;
    strcpy(result, targetVertex->connections[0].endpoint);
    for (int i = 1; i < targetVertex->connections.size(); i++)
        if (targetVertex->connections[i].weight < w) {
            w = targetVertex->connections[i].weight;
            strcpy(result, targetVertex->connections[i].endpoint);
        }
    return true;
}

vector<vector<char *>> Graph::getComonents() {
    vector<vector<char *>> result;
    vector<char *> allVertex = getVertexNames();
    bool *worked = new bool[allVertex.size()];
    for(int i=0;i<allVertex.size();i++)
        worked[i] = false;
    worked[0] = true;
    vector<char *> worckedItems;
    worckedItems.push_back(allVertex[0]);
    int countSelectedItem = 1;
    while(countSelectedItem!=allVertex.size()){
        result.push_back(vector<char *>());
        while (worckedItems.size()!=0){
            result[result.size()-1].push_back(worckedItems[0]);
            vertex *currentVertex = getVertexByName(worckedItems[0]);
            worckedItems.erase(worckedItems.begin());
            for(int i=0;i<currentVertex->connections.size();i++){
                for(int e=0;e<allVertex.size();e++){
                    if(strcmp(allVertex[e],currentVertex->connections[i].endpoint) == 0) {
                        if (worked[e])
                            continue;
                        worked[e] = true;
                        worckedItems.push_back(allVertex[e]);
                        countSelectedItem++;
                    }

                }
            }
        }
        for(int i=0;i<allVertex.size();i++) {
            if (worked[i])
                continue;
            worckedItems.clear();
            worckedItems.push_back(allVertex[i]);
            worked[i] = true;
            countSelectedItem++;
            break;
        }
    }
    return result;
}

void Graph::readFromConsole() {
    printf("Input edge count:");
    int ecount;
    scanf("%i", &ecount);
    char from[12], to[12];
    int w;
    for (int i = 0; i < ecount; i++) {
        scanf("%s%s%i", from, to, &w);
        vertex *fromVertex = getVertexByName(from);
        fromVertex->connections.push_back(age(to, w));

        vertex *toVertex = getVertexByName(to);
        toVertex->connections.push_back(age(from, w));
    }
    for (int i = 0; i < graph.size(); i++) {
        vertexName.push_back(graph[i].name);
    }
}
