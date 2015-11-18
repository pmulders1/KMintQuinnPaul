#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"

int main(int args[])
{
	srand(time(0));
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;

	}

	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));

	Graph graph = Graph(application);
	vector<Vertex*> path = graph.Astar();
	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){

				default:
					graph.current = path[path.size() -1];
					path.erase(path.end() - 1);

					if (graph.current == graph.last){
						int temp = rand() % graph.graph.size();
						while (graph.graph[temp] == graph.last){
							temp = rand() % graph.graph.size();
						}
						graph.last = graph.graph[temp];
						path = graph.Astar();
					}
					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));

		graph.Draw();

		application->SetColor(Color(255, 255, 255, 255));
		
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}