#include "ExitDialog.h"
#include "cocos2d.h"
#include "CWallData.h"

USING_NS_CC;


// class ExitDlg : public DialogLayer
// {
// public:
//     virtual bool onInitDialog();
// 
//     CREATE_FUNC(ExitDlg);
// 
// public:
//     /** 确认和退出按钮 */
//     void okMenuItemCallback(CCObject *obj);
//     void cancelMenuItemCallback(CCObject *obj);
// };

bool ExitDlg::onInitDialog()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//添加背景
	CCSprite * bg = CCSprite::create("dialogBG.png");
	bg->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(bg);

    CCMenuItemImage *okMenuItem = CCMenuItemImage::create(
		"buttonDlgOk_0.png",
		"buttonDlgOk_1.png",
		this, 
		menu_selector(ExitDlg::okMenuItemCallback)
		);
    okMenuItem->setPosition(ccp(winSize.width / 2 - 100, winSize.height / 2 - 70));

    CCMenuItemImage *cancelMenuItem = CCMenuItemImage::create(
		"buttonDlgCancel_0.png", 
		"buttonDlgCancel_1.png", 
		this,
		menu_selector(ExitDlg::cancelMenuItemCallback)
		);
    cancelMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2 - 70));

    pushMenu(okMenuItem);
    pushMenu(cancelMenuItem);

    setColor(ccc3(150,150,150));
    setOpacity(210);
    return true;
}

void ExitDlg::okMenuItemCallback(CCObject *obj)
{
    CCDirector::sharedDirector()->end();
}

void ExitDlg::cancelMenuItemCallback(CCObject *obj)
{
    removeFromParentAndCleanup(true);
}