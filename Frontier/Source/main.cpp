#include "FTEngine.h"
#include "DemoScene.h"

int main() {
	int ret = -1;
	if (FTEngine::setup()) {
		FTScene *scene = new DemoScene();
		FTDirector::getSharedInstance()->setCurrentScene(scene);
		scene->release();

		ret = FTDirector::getSharedInstance()->run();
		FTEngine::cleanup();
	}
	return ret;
}
