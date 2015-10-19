#include "FTEngine.h"
#include <DemoScene.h>
#include <Rendering/FTDirector.h>

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif


int main() {
    int ret = -1;
    if (FTEngine::setup()) {
        auto scene = std::static_pointer_cast<FTScene>(std::make_shared<DemoScene>());
        FTEngine::getDirector()->setCurrentScene(scene);
        scene.reset();

        ret = FTEngine::run();
        FTEngine::cleanup();
    }
#ifdef _WIN32
    FTAssert(_CrtDumpMemoryLeaks() == 0, "Leaks Detected");
#endif
    return ret;
}
