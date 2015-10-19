#include "DemoScene.h"
#include "Demo2DView.h"

DemoScene::DemoScene() {
	auto view = std::make_shared<Demo2DView>();
	addView(std::move(view));
}

DemoScene::~DemoScene() {
    FTLOG("DemoScene Destroyed");
}