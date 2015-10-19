#include "DemoScene.h"
#include "Demo3DView.h"

DemoScene::DemoScene() {
	auto view = std::make_shared<Demo3DView>();
	addView(std::move(view));
}

DemoScene::~DemoScene() {
    FTLOG("DemoScene Destroyed");
}