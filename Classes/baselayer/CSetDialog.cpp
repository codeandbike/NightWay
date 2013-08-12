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

	CCLabelTTF *label = CCLabelTTF::create("Set the Game", "", 64);
	label->setPosition(ccp(winSize.width / 2, winSize.height / 2 + 50));
	this->addChild(label);

	CCMenuItemFont *okMenuItem = CCMenuItemFont::create("OK", this, menu_selector(CCSetDialog::okMenuItemCallback));
	okMenuItem->setPosition(ccp(winSize.width / 2 - 100, winSize.height / 2 - 50));

	CCMenuItemFont *cancelMenuItem = CCMenuItemFont::create("Cancel", this, menu_selector(CCSetDialog::cancelMenuItemCallback));
	cancelMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2 - 50));

	pushMenu(okMenuItem);
	pushMenu(cancelMenuItem);


	setColor(ccc3(150,150,150));
	setOpacity(128);
	return true;
}


/************************************************************************/
/* 确认和退出按钮                                                                     */
/************************************************************************/
void CCSetDialog::okMenuItemCallback(CCObject *obj)
{

}
void CCSetDialog::cancelMenuItemCallback(CCObject *obj)
{
	removeFromParentAndCleanup(true);
}