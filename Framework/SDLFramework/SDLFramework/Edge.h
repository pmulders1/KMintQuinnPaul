#pragma once
#include "Vertex.h"

class Edge
{
public:
	int startXpos;
	int startYpos;
	int endXpos;
	int endYpos;
	Vertex* v;
	Vertex* v1;

	Edge(int startXpos, int startYpos, int endXpos, int endYpos, Vertex* v, Vertex* v1);

	~Edge();
};

