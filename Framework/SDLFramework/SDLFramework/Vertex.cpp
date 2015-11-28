#include "Edge.h"

Vertex::Vertex(int xPos, int yPos, string letter) : xPos(xPos), yPos(yPos), width(25), height(25), letter(letter)
{
}

void Vertex::addPartner(Vertex* v, vector<Edge>& edges){
	partners.push_back(v);
	v->partners.push_back(this);

	edges.push_back(Edge(this->getCenterPoint().first, this->getCenterPoint().second, v->getCenterPoint().first, v->getCenterPoint().second, this, v));
}

pair<int, int> Vertex::getCenterPoint(){
	int centerX = xPos + width / 2;
	int centerY = yPos + height / 2;
	return make_pair(centerX, centerY);
}

float Vertex::BerekenAfstand(Vertex* s, Vertex* end){
	int dx, dy;
	float distance;
	dx = end->getCenterPoint().first - s->getCenterPoint().first;
	dy = end->getCenterPoint().second - s->getCenterPoint().second;

	distance = sqrt((double)dx*dx + dy*dy);
	return distance;
}

Vertex::~Vertex()
{
}
