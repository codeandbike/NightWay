#include "CInfoDialog.h"
#include "cocos2d.h"
#include "CWallData.h"
#include "CStartGame.h"
#include "CMainScene.h"

USING_NS_CC;

CCInfoDialog::CCInfoDialog(void)
{
}


CCInfoDialog::~CCInfoDialog(void)
{
}


/************************************************************************/
/* 初始化对话框                                                                     */
/************************************************************************/
bool CCInfoDialog::onInitDialog()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//添加背景
	CCSprite * bg = CCSprite::create("dialogInfoBG.png");
	bg->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(bg);

	//返回按钮
	CCMenuItemImage *cancelMenuItem = CCMenuItemImage::create(
		"Menu_Info_0.png", 
		"Menu_Info_1.png", 
		this,
		menu_selector(CCInfoDialog::backMenuItemCallback)
		);
	cancelMenuItem->setPosition(ccp(winSize.width / 2,70));

	pushMenu(cancelMenuItem);

	setColor(ccc3(150,150,150));
	setOpacity(210);
	return true;


}


/************************************************************************/
/* 返回主页                                                                  */
/************************************************************************/
void CCInfoDialog::backMenuItemCallback(CCObject *obj)
{
	CCScene * s = CCStartGame::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}
