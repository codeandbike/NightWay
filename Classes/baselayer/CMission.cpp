#include "CMission.h"
#include "CStartGame.h"
using namespace cocos2d;
CCMission::CCMission(void)
{
}


CCMission::~CCMission(void)
{
}


/************************************************************************/
/* 初始化场景                                                                     */
/************************************************************************/
bool CCMission::init()
{
	bool sRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		//初始化父类
		//////////////////////////////////////////////////////////////////////////
		CC_BREAK_IF(!CCLayer::create());
		//////////////////////////////////////////////////////////////////////////
		//加载图层元素
		//////////////////////////////////////////////////////////////////////////
		//获得设备尺寸
		CCSize WinSize = CCDirector::sharedDirector()->getWinSize();
		//加载关卡按钮
		CCMenuItemImage * pSetItem = CCMenuItemImage::create(
			"Menu_SetGame_0.png",
			"Menu_SetGame_1.png",
			this,
			menu_selector(CCMission::menuSceneToStart)
			);
		pSetItem->setPosition(ccp(WinSize.width/2,WinSize.height/6*2));
		CCMenu *pSetMenu = CCMenu::create(pSetItem,NULL);
		pSetMenu->setPosition(CCPointZero);
		this->addChild(pSetMenu);

		sRet = true;
	} while (0);
	return sRet;
}

/************************************************************************/
/* 加载场景                                                                     */
/************************************************************************/
CCScene * CCMission::scene()
{
	CCScene * scene = NULL;
	do 
	{
		//创建场景
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		//创建层
		CCMission *layer = CCMission::create();
		CC_BREAK_IF(!layer);
		//添加图层
		scene->addChild(layer);
	} while (0);
	return scene;
}

/************************************************************************/
/* 返回启动页面                                                                     */
/************************************************************************/
void CCMission::menuSceneToStart(CCObject *pSender)
{
	CCScene *s = CCStartGame::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}