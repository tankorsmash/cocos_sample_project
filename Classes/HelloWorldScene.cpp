#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

#include "reader/CreatorReader.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    creator::CreatorReader* reader = creator::CreatorReader::createWithFilename("creator/Scene/sample_scene.ccreator");
    // will create the needed spritesheets + design resolution
    reader->setup();

    // get the scene graph
    Scene* scene = reader->getSceneGraph();
    this->addChild(scene);
    //scene->removeFromParent();
    //scene->setParent(this);

    Vector<Node*> children = scene->getChildren();
    for (auto child : children){
        CCLOG("child name %s", child->getName().c_str());
        if (child->getName() == "sample_button")
        {
            cocos2d::ui::Button* button_cast = dynamic_cast<cocos2d::ui::Button*>(child);
            CCLOG("BUTTON_cast is: %s\n\n\n", button_cast ? "cast properly" : "not converted");
        }
        if (child->getName() == "sample_layout")
        {
            cocos2d::ui::Layout* layout_cast = dynamic_cast<cocos2d::ui::Layout*>(child);
            CCLOG("LAYOUT_cast is: %s\n\n\n", layout_cast ? "cast properly" : "not converted");
            //if (!layout_cast) { exit(0); };
        }
    }

    CCLOG("init done for reals");
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
