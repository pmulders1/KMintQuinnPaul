#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "StateFactory.h"
#include <thread>

using namespace std;

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
	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();
		application->SetColor(Color(0, 0, 0, 255));
		graph.Draw();
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
					graph.Update();
					graph.Collision();
					break;
				}
			}
		}
		application->SetColor(Color(255, 255, 255, 255));
		
		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
		//this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
		
	return EXIT_SUCCESS;
}