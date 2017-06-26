#include "function.h"
#include "Scene.h"

void mainloop(Window * win)
{
	Scene scene(win);

	while (true)
	{

		scene.enent();

		scene.update();

		if (scene.isOver())
			break;

		scene.rend();
	}
}