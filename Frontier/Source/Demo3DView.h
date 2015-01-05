#pragma once
#include <Rendering/Scene/FTView.h>
#include <FTArray.h>

class FTNode;

class Demo3DView : public FTView {
public:
	Demo3DView();
	~Demo3DView();

	virtual void draw() override;

protected:
	FTArray<FTNode>* nodes_;
};
