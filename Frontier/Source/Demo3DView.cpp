#include "Demo3DView.h"
#include <Rendering/Camera/FTCamera2D.h>
#include <Rendering/Text/FTLabel.h>
#include <Rendering/FTDirector.h>

Demo3DView::Demo3DView() : FTView(new FTCamera2D(),FTRect<float>(0,0,1,1)), nodes_(new FTArray<FTNode>()) {
	camera_->release();

	// Pretty barebones at the moment - will likely add more in future
	FTLabel* label = new FTLabel("Fonts/Vera.ttf", L"Hello World",64);
	label->setPosition(FTDirector::getSharedInstance()->getWindowSize() / 2.0f);
	nodes_->add(label);
	label->release();
}

Demo3DView::~Demo3DView() {
	nodes_->release();
}

void Demo3DView::draw() {
	FTView::draw();
	for (auto it = nodes_->begin(); it != nodes_->end(); ++it) {
		(*it)->visit(camera_);
	}
}