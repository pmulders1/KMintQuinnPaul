#include "Edge.h"

Edge::Edge(int startXpos, int startYpos, int endXpos, int endYpos, Vertex* v, Vertex* v1) : startXpos(startXpos), startYpos(startYpos), endXpos(endXpos), endYpos(endYpos), v(v), v1(v1)
{

}

Edge::~Edge()
{
}
