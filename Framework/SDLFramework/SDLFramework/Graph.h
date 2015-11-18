#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "FWApplication.h"
#include <queue>
using namespace std;
class Graph
{
public:
	vector<Vertex*> graph;
	vector<Edge> edges;

	vector <Vertex*> path;

	
	static bool sortByF(Vertex* lhs, Vertex* rhs) 
	{
		return lhs->f() < rhs->f();
	}

	struct cmp
	{
		bool operator()(pair<float, Vertex*> a, pair<float, Vertex*> b) { return a.first < b.first; }
	};

	//std::priority_queue<pair<float, Vertex*>, std::vector<pair<float, Vertex*>>, cmp> openList;
	vector<Vertex*> openList;

	Vertex* current;
	Vertex* last;

	FWApplication* application;

	SDL_Texture* cow;
	SDL_Texture* rabbit;

	Graph(FWApplication* app);
	void Draw();
	vector<Vertex*> Astar();
	~Graph();
};
