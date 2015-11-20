#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "FWApplication.h"
#include <queue>
#include "Entity.h"
using namespace std;
class Graph
{
public:
	vector<Vertex*> graph;
	vector<Edge> edges;

	vector <Vertex*> path;

	struct cmp
	{
		bool operator()(pair<float, Vertex*> a, pair<float, Vertex*> b) { return a.first > b.first; }
	};

	std::priority_queue<pair<float, Vertex*>, std::vector<pair<float, Vertex*>>, cmp> openList;
	//vector<Vertex*> openList;

	FWApplication* application;

	Entity* cow;
	Entity* rabbit;
	Entity* pill;
	Entity* weapon;

	Graph(FWApplication* app);
	void Draw();
	void Update();
	void Collision();
	void ClearLists();
	vector<Vertex*> Astar(Entity* chaser, Entity* chased);
	~Graph();
};
