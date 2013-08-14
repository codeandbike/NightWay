#include "CMainScene.h"

using namespace cocos2d;
CCMainScene::CCMainScene(void)
{
}


CCMainScene::~CCMainScene(void)
{
}

/************************************************************************/
/* 加载场景                                                                     */
/************************************************************************/
CCScene * CCMainScene::scene()
{
	CCScene *scene = NULL;
	do 
	{
		//创建场景
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		//创建层
		CCMainScene *layer = CCMainScene::create();
		CC_BREAK_IF(!layer);
		//添加层
		scene->addChild(layer);
	} while (0);
	return scene;
}
/************************************************************************/
/* 类初始化                                                                     */
/************************************************************************/
bool CCMainScene::init()
{
	bool sRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		//初始化父类
		//////////////////////////////////////////////////////////////////////////
		CC_BREAK_IF(!CCLayer::create());
		//////////////////////////////////////////////////////////////////////////
		//场景元素代码
		//////////////////////////////////////////////////////////////////////////
		
		//获取屏幕尺寸
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();


		sRet = true;
	} while (0);
	return sRet;
}
