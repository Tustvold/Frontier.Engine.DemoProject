#include "Demo2DView.h"
#include <Rendering/Camera/FTCamera2D.h>
#include <Rendering/Text/FTLabel.h>
#include <Rendering/Scene/Action/FTActionSequence.h>
#include <Rendering/Scene/FTWindowSizeNode.h>
#include <Rendering/Scene/FTLayoutNode.h>
#include <Rendering/Scene/Action/FTMoveToAction.h>
#include <Rendering/Scene/Action/FTCallFuncAction.h>
#include <Rendering/Scene/Action/FTRepeatAction.h>

Demo2DView::Demo2DView() {
    setCamera(std::make_shared<FTCamera2D>());
	
    auto window_size_node = std::make_shared<FTWindowSizeNode>();
    window_size_node->setAnchorPoint(glm::vec2(-0.5f, -0.5f));
    addChild(std::static_pointer_cast<FTNode>(window_size_node));

    auto layout = std::make_shared<FTLayoutNode>();
    window_size_node->addChild(std::static_pointer_cast<FTNode>(layout));


    auto label = std::make_shared<FTLabel>("Resources/Fonts/Vera.ttf", L"Hello!!!", 32);
    label->setAnchorPoint(glm::vec2(0.0f, 0.5f));
    label->setFrustrumCull(true);

    auto label2 = std::make_shared<FTLabel>("Resources/Fonts/Vera.ttf", L"Hello2!!!", 32);
    label2->setAnchorPoint(glm::vec2(0.0f, 0.5f));
    label2->setFrustrumCull(true);


    layout->addChild(label);
    layout->addChild(label2);


    layout->setAnchorPoint(glm::vec2(0.5f, 0.0f));
    layout->layoutChildrenWithPaddingX(20.0f);

    auto delay = std::make_unique<FTDelayAction>(1);
    auto move_to = std::make_unique<FTMoveToAction>(glm::vec3(20, 20, 0), 1);

    auto delay2 = std::make_unique<FTDelayAction>(1);
    auto move_back = std::make_unique<FTMoveToAction>(glm::vec3(0, 0, 0), 1);

    auto print = std::make_unique<FTCallFuncAction>([](FTNode* node) {
        FTLOG("Sequence Finished");
    });


    auto sequence = std::make_unique<FTActionSequence>();
    sequence->addAction(std::move(delay));
    sequence->addAction(std::move(move_to));
    sequence->addAction(std::move(delay2));
    sequence->addAction(std::move(move_back));
    sequence->addAction(std::move(print));

    layout->runAction(std::make_unique<FTRepeatAction>(std::move(sequence), -1));
}

Demo2DView::~Demo2DView() {
}
