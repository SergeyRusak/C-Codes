// Graph project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "Graph.h"
int main()
{
    std::string path = "F:/Desktop/TestGraph.txt";
    ifstream inpfile(path);
    Graph graph;
    set<Node> nodes;
    graph.addNode(new Node("21"));
    cout << graph.getNodebyName("21")->getName();
    string a;
    do {
        getline(inpfile, a);// для пропуска test и source
    } while (a == "");
    while (inpfile.good())
    {
        int s, t;
        inpfile >> s >> t;
        Node ns(to_string(s)), nt(to_string(t));
        if (nodes.find(ns) == nodes.end()) {
            nodes.insert(ns);
            graph.addNode(&ns);
        }
        else {
            ns = *graph.getNodebyName(to_string(s));
        }
        if (nodes.find(nt) == nodes.end()) {
            nodes.insert(nt);
            graph.addNode(&nt);
        }
        else {
            nt = *graph.getNodebyName(to_string(t));
        }
        graph.addEdge(&ns, &nt);
    }
    
    
}
