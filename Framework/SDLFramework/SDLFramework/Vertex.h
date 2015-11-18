#pragma once
#include <vector>

using namespace std;

class Edge;

class Vertex
{
public:
	int xPos;
	int yPos;
	int width;
	int height;
	string letter;
	bool inClosedList = false;
	bool inOpenList = false;
	float f(){ return g + h; }
	//Afgelegde afstand van Start naar deze node
	float g;
	//Verwachte afstand van deze node naar eind node
	float h;

	float BerekenAfstand(Vertex* s, Vertex* end);

	vector<Vertex*> partners;
	Vertex* parent;
	void addPartner(Vertex* v, vector<Edge>& edges);
	pair<int, int> getCenterPoint();

	Vertex(int xPos, int yPos, string letter);
	~Vertex();
};

