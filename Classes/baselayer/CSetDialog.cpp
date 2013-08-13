#include "CSetDialog.h"
#include "cocos2d.h"

USING_NS_CC;

CCSetDialog::CCSetDialog(void)
{
}


CCSetDialog::~CCSetDialog(void)
{
}


/************************************************************************/
/* 初始化对话框                                                                     */
/************************************************************************/
bool CCSetDialog::onInitDialog()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//添加背景
	CCSprite * bg = CCSprite::create("dialogSetBG.png");
	bg->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(bg);

	//确定按钮
	CCMenuItemImage *okMenuItem = CCMenuItemImage::create(
		"dialogButtonOk_0.png",
		"dialogButtonOk_1.png",
		this, 
		menu_selector(CCSetDialog::okMenuItemCallback)
		);
	okMenuItem->setPosition(ccp(winSize.width / 2 - 100, winSize.height / 2 - 70));
	//取消按钮
	CCMenuItemImage *cancelMenuItem = CCMenuItemImage::create(
		"dialogButtonCancel_0.png", 
		"dialogButtonCancel_1.png", 
		this,
		menu_selector(CCSetDialog::cancelMenuItemCallback)
		);
	cancelMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2 - 70));

	//音效开关
	CCMenuItemToggle * soundMenuItem =CCMenuItemToggle::createWithTarget(
		this,
		NULL,
		CCMenuItemFont::create("On"),
		CCMenuItemFont::create("Off"),
		NULL
		);
	soundMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2+30));
	soundMenuItem->setColor(ccc3(85,63,39));
		//音乐开关
	CCMenuItemToggle * musicMenuItem =CCMenuItemToggle::createWithTarget(
		this,
		NULL,
		CCMenuItemFont::create("On"),
		CCMenuItemFont::create("Off"),
		NULL
		);
	musicMenuItem->setPosition(ccp(winSize.width / 2 - 30, winSize.height / 2+30));
	musicMenuItem->setColor(ccc3(85,63,39));

	pushMenu(okMenuItem);
	pushMenu(cancelMenuItem);
	pushMenu(soundMenuItem);
	pushMenu(musicMenuItem);


	setColor(ccc3(150,150,150));
	setOpacity(128);
	return true;
}


/************************************************************************/
/* 确认和退出按钮                                                                     */
/************************************************************************/
void CCSetDialog::okMenuItemCallback(CCObject *obj)
{
	removeFromParentAndCleanup(true);
}
void CCSetDialog::cancelMenuItemCallback(CCObject *obj)
{
	removeFromParentAndCleanup(true);
}