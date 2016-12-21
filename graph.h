//
// Created by Yura Braiko on 20.12.16.
//

#ifndef ALEX_GRAPH_H
#define ALEX_GRAPH_H

#include <vector>

using namespace std;

class Graph {
public:
    Graph(char *fileName);

	Graph();

    void readFromConsole();

    int getVertexCount();

    bool isAgeExist(char *a, char *b);

    int getWeight(char *a, char *b);

    vector<char *> getVertexNames();

    void addVertex(char *newPoint);

    void addAge(char *from,char *to,int w);

    bool getMinValue(char *target,char *result,int &w);

    void print();

    vector<vector<char *>> getComonents();

private:
    const static  int vertexNameLength = 10;
    struct age {
    public:
        age(char *_endpoint, int _weight) {

            endpoint = new char[vertexNameLength];
            strcpy(endpoint,_endpoint);
            weight = _weight;
        }

        char *endpoint;
        int weight;
    };

    struct vertex {
    public:
        vertex(char *_name) {
            name = new char[vertexNameLength];
            strcpy(name,_name);
        }

        char *name;
        vector<age> connections;
    };

    vector<char *> vertexName;

    vector<vertex> graph;

    vertex *getVertexByName(char *name);

};


#endif //ALEX_GRAPH_H
