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

		//////////////////////////////////////////////////////////////////////////
		//添加控制按钮  开始
		//////////////////////////////////////////////////////////////////////////

		//加载向上按钮
		CCScale9Sprite *btnNormal = CCScale9Sprite::create("up2.png");
		CCScale9Sprite *btnSelected = CCScale9Sprite::create("up1.png");
		CCControlButton *pButtonUP = CCControlButton::create(btnNormal);
		pButtonUP->setPreferredSize(CCSizeMake(48,48));
		pButtonUP->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonUP->setPosition(ccp(winSize.width/2,((150/4)*3)+12.5));
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp),CCControlEventTouchDown);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpInside);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonUP);

		//添加向下按钮
		btnNormal = CCScale9Sprite::create("down2.png");
		btnSelected = CCScale9Sprite::create("down1.png");
		CCControlButton *pButtonDown = CCControlButton::create(btnNormal);
		pButtonDown->setPreferredSize(CCSizeMake(48,48));
		pButtonDown->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonDown->setPosition(ccp(winSize.width/2,(150/4)-12.5));
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown),CCControlEventTouchDown);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown2),CCControlEventTouchUpInside);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonDown);

		//添加向左按钮
		btnNormal = CCScale9Sprite::create("left2.png");
		btnSelected = CCScale9Sprite::create("left1.png");
		CCControlButton *pButtonLeft = CCControlButton::create(btnNormal);
		pButtonLeft->setPreferredSize(CCSizeMake(48,48));
		pButtonLeft->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonLeft->setPosition(ccp((winSize.width/2)-48,150/2));
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft),CCControlEventTouchDown);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft2),CCControlEventTouchUpInside);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonLeft);

		//添加向右按钮
		btnNormal = CCScale9Sprite::create("right2.png");
		btnSelected = CCScale9Sprite::create("right1.png");
		CCControlButton *pButtonRight = CCControlButton::create(btnNormal);
		pButtonRight->setPreferredSize(CCSizeMake(48,48));
		pButtonRight->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonRight->setPosition(ccp((winSize.width/2)+48,150/2));
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight),CCControlEventTouchDown);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight2),CCControlEventTouchUpInside);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonRight);

		//////////////////////////////////////////////////////////////////////////
		//添加控制按钮  结束
		//////////////////////////////////////////////////////////////////////////


		sRet = true;
	} while (0);
	return sRet;
}




/************************************************************************/
/*   按钮事件回调函数 开始                                                                   */
/************************************************************************/
void CCMainScene::touchDragInsideUp(CCObject* pSender, CCControlEvent event)
{

// 	if (!b_ButtonDown)
// 	{	
// 		dirTag = kUp;
// 		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
// 		b_ButtonDown = true;
// 	}




}
void CCMainScene::touchDragInsideDown(CCObject* pSender, CCControlEvent event)
{

// 	if (!b_ButtonDown)
// 	{
// 		dirTag = kDown;
// 		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
// 		b_ButtonDown = true;
// 	}


}
void CCMainScene::touchDragInsideLeft(CCObject* pSender, CCControlEvent event)
{

// 	if (!b_ButtonDown)
// 	{
// 		b_ButtonDown = true;
// 		dirTag = kLeft;
// 		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
// 	}



}
void CCMainScene::touchDragInsideRight(CCObject* pSender, CCControlEvent event)
{

// 	if (!b_ButtonDown)
// 	{
// 		dirTag = kRight;
// 		this->schedule(schedule_selector(CCButtonLayer::MoveHeroBegin),0.005f);
// 		b_ButtonDown=true;
// 	}


}


void CCMainScene::touchDragInsideUp2(CCObject* pSender, CCControlEvent event)
{

// 	if (dirTag == kUp)
// 	{
// 		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
// 		b_ButtonDown = false;
// 	}


}
void CCMainScene::touchDragInsideDown2(CCObject* pSender, CCControlEvent event)
{

// 	if (dirTag == kDown)
// 	{
// 		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
// 		b_ButtonDown = false;
// 	}

}
void CCMainScene::touchDragInsideLeft2(CCObject* pSender, CCControlEvent event)
{

// 	if (dirTag == kLeft)
// 	{
// 		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
// 		b_ButtonDown = false;
// 	}

}
void CCMainScene::touchDragInsideRight2(CCObject* pSender, CCControlEvent event)
{

// 	if (dirTag == kRight)
// 	{
// 		this->unschedule(schedule_selector(CCButtonLayer::MoveHeroBegin));
// 		b_ButtonDown = false;
// 	}

}

/************************************************************************/
/*      按钮事件回调函数 结束                                                                */
/************************************************************************/