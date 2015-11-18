#include "Graph.h"
#include <algorithm>
#include <iostream>
using namespace std;



Graph::Graph(FWApplication* app)
{
	application = app;
	cow = application->LoadTexture("./../Resources/cow-1.png");
	rabbit = application->LoadTexture("./../Resources/rabbit-2.png");

	Vertex* v = new Vertex(50, 50, "A");
	graph.push_back(v);

	Vertex* v1 = new Vertex(150, 75, "B");
	graph.push_back(v1);

	Vertex* v2 = new Vertex(200, 175, "C");
	graph.push_back(v2);

	Vertex* v3 = new Vertex(60, 300, "D");
	graph.push_back(v3);

	Vertex* v4 = new Vertex(150, 400, "E");
	graph.push_back(v4);

	Vertex* v5 = new Vertex(350, 275, "F");
	graph.push_back(v5);

	Vertex* v6 = new Vertex(275, 300, "G");
	graph.push_back(v6);

	Vertex* v7 = new Vertex(400, 60, "H");
	graph.push_back(v7);

	Vertex* v8 = new Vertex(400, 400, "I");
	graph.push_back(v8);

	Vertex* v9 = new Vertex(500, 40, "J");
	graph.push_back(v9);

	Vertex* v10 = new Vertex(40, 550, "K");
	graph.push_back(v10);

	Vertex* v11 = new Vertex(75, 450, "L");
	graph.push_back(v11);

	Vertex* v12 = new Vertex(175, 525, "M");
	graph.push_back(v12);

	Vertex* v13 = new Vertex(250, 375, "N");
	graph.push_back(v13);

	Vertex* v14 = new Vertex(350, 350, "O");
	graph.push_back(v14);

	Vertex* v15 = new Vertex(575, 425, "P");
	graph.push_back(v15);

	Vertex* v16 = new Vertex(525, 125, "Q");
	graph.push_back(v16);

	Vertex* v17 = new Vertex(475, 175, "R");
	graph.push_back(v17);

	Vertex* v18 = new Vertex(675, 275, "S");
	graph.push_back(v18);

	Vertex* v19 = new Vertex(725, 350, "T");
	graph.push_back(v19);

	Vertex* v20 = new Vertex(700, 150, "U");
	graph.push_back(v20);

	Vertex* v21 = new Vertex(700, 500, "V");
	graph.push_back(v21);

	Vertex* v22 = new Vertex(600, 40, "W");
	graph.push_back(v22);

	Vertex* v23 = new Vertex(450, 550, "X");
	graph.push_back(v23);

	v->addPartner(v1, edges);
	v->addPartner(v3, edges);
	v1->addPartner(v2, edges);
	v1->addPartner(v7, edges);
	v2->addPartner(v3, edges);
	v2->addPartner(v5, edges);
	v3->addPartner(v4, edges);
	v3->addPartner(v11, edges);
	v4->addPartner(v6, edges);
	v4->addPartner(v11, edges);
	v4->addPartner(v12, edges);
	v5->addPartner(v6, edges);
	v5->addPartner(v7, edges);
	v5->addPartner(v14, edges);
	v5->addPartner(v17, edges);
	v6->addPartner(v14, edges);
	v6->addPartner(v13, edges);
	v7->addPartner(v9, edges);
	v7->addPartner(v16, edges);
	v8->addPartner(v13, edges);
	v8->addPartner(v15, edges);
	v8->addPartner(v17, edges);
	v9->addPartner(v16, edges);
	v9->addPartner(v22, edges);
	v10->addPartner(v11, edges);
	v10->addPartner(v12, edges);
	v12->addPartner(v13, edges);
	v12->addPartner(v15, edges);
	v12->addPartner(v23, edges);
	v13->addPartner(v12, edges);
	v14->addPartner(v17, edges);
	v15->addPartner(v16, edges);
	v15->addPartner(v21, edges);
	v15->addPartner(v23, edges);
	v15->addPartner(v18, edges);
	v16->addPartner(v17, edges);
	v16->addPartner(v22, edges);
	v16->addPartner(v18, edges);
	v18->addPartner(v20, edges);
	v18->addPartner(v21, edges);
	v19->addPartner(v20, edges);
	v19->addPartner(v21, edges);
	v20->addPartner(v22, edges);

	current = v;
	last = v21;
}

void Graph::Draw(){
	for (size_t i = 0; i < graph.size(); i++)
	{
		if (graph[i]->inOpenList){
			application->SetColor(Color(0,255,0,0));
		}
		if (graph[i]->inClosedList){
			application->SetColor(Color(255, 0, 0, 0));
		}
		if(std::find(path.begin(), path.end(), graph[i]) != path.end()){
			application->SetColor(Color(0, 0, 255, 0));
		}
		application->DrawRect(graph[i]->xPos, graph[i]->yPos, graph[i]->width, graph[i]->height, true);
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText(graph[i]->letter, graph[i]->xPos - 10, graph[i]->yPos + 10);
	}
	for (size_t i = 0; i < edges.size(); i++)
	{
		application->DrawLine(edges[i].startXpos, edges[i].startYpos, edges[i].endXpos, edges[i].endYpos);
	}

	application->DrawTexture(cow, current->getCenterPoint().first, current->getCenterPoint().second, 75, 75);
	application->DrawTexture(rabbit, last->getCenterPoint().first, last->getCenterPoint().second, 75, 75);
}

vector<Vertex*> Graph::Astar(){
	path.clear();
	openList.clear();

	for (size_t i = 0; i < graph.size(); i++){
		graph[i]->g = 9999;
		graph[i]->h = graph[i]->BerekenAfstand(graph[i], last);
		graph[i]->parent = nullptr;
		graph[i]->inClosedList = false;
		graph[i]->inOpenList = false;
	}
	current->g = 0;
	openList.push_back(current);
	Vertex* temp;

	while (openList.size() != 0){
		temp = openList[0];
		int pos = 0;
		for (size_t i = 1; i < openList.size(); i++)
		{
			if (openList[i]->f() < temp->f()){
				temp = openList[i];
				pos = i;
			}
		}
		openList.erase(openList.begin() + pos);

		temp->inClosedList = true;

		if (temp == last){
			break;
		}

		for each (Vertex* var in temp->partners)
		{
			if (!var->inClosedList){
			float newCost = temp->g + temp->BerekenAfstand(temp, var);
				if (newCost < var->g || !var->inOpenList){ // ook bool
					var->g = newCost;
					var->h = var->BerekenAfstand(var, last);
					var->parent = temp;
					openList.push_back(var);
					if (!var->inOpenList){
						var->inOpenList = true;
						openList.push_back(var);
					}
				}
			}
		}

	}
	Vertex* c = last;
	while (c != nullptr){
		path.push_back(c);
		c = c->parent;
	}
	return path;
}

Graph::~Graph()
{
}