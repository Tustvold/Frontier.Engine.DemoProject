#include "DemoScene.h"
#include "Demo3DView.h"

DemoScene::DemoScene() {
	FTView* view = new Demo3DView();
	addView(view);
	view->release();
}

DemoScene::~DemoScene() {
}