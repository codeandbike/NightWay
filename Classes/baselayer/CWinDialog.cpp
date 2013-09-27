#include "CWinDialog.h"
#include "cocos2d.h"
#include "CWallData.h"
#include "CMainScene.h"
#include "CInfoDialog.h"

USING_NS_CC;

CCWinDialog::CCWinDialog(void)
{
}


CCWinDialog::~CCWinDialog(void)
{
}


/************************************************************************/
/* 初始化对话框                                                                     */
/************************************************************************/
bool CCWinDialog::onInitDialog()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//添加背景
	CCSprite * bg = CCSprite::create("dialogWin_BG.png");
	bg->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(bg);

	//返回按钮
	CCMenuItemImage *cancelMenuItem = CCMenuItemImage::create(
		"buttonDlgBack_0.png", 
		"buttonDlgBack_1.png", 
		this,
		menu_selector(CCWinDialog::backMenuItemCallback)
		);
	cancelMenuItem->setPosition(ccp(winSize.width / 2 - 100, winSize.height / 2 - 70));

	//下一关按钮
	CCMenuItemImage *nextMenuItem = CCMenuItemImage::create(
		"buttonDlgNext_0.png", 
		"buttonDlgNext_1.png", 
		this,
		menu_selector(CCWinDialog::nextMenuItemCallback)
		);
	nextMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2 - 70));

	//显示时间
	CCWallData * data = CCWallData::create();
	char  s[20];
	sprintf(s,"%d",data->getDataTime());
	CCLabelTTF *title = CCLabelTTF::create(s,"STKaiti",45);
	title->setPosition(ccp(winSize.width / 2-20,winSize.height / 2+5));
	title->setColor(ccc3(255,255,255));
	this->addChild(title);

	pushMenu(cancelMenuItem);
	pushMenu(nextMenuItem);

	setColor(ccc3(150,150,150));
	setOpacity(210);
	return true;


}


/************************************************************************/
/* 返回和下一关按钮                                                                     */
/************************************************************************/
void CCWinDialog::backMenuItemCallback(CCObject *obj)
{
	CCScene *s = CCMainScene::scene();
	CCDirector::sharedDirector()->replaceScene(s);
	//removeFromParentAndCleanup(true);
}
void CCWinDialog::nextMenuItemCallback(CCObject *obj)
{
	CCWallData *data = CCWallData::create();
	int NextID = data->getSelectID()+1;
	data->setSelectID(NextID);
	if (NextID <= data->getSceneConter())
	{
		//下一关
		if (NextID > data->getNextID())
		{
			CCUserDefault::sharedUserDefault()->setIntegerForKey("NextID",NextID);
		}
		CCScene *s = CCMainScene::scene();
		CCDirector::sharedDirector()->replaceScene(s);
	}else{
		//游戏结束
		//CCMessageBox("over!!","tetle");
		//CCUserDefault::sharedUserDefault()->setIntegerForKey("NextID",-1);
		//跳转到关于页面
		CCInfoDialog * dlg = CCInfoDialog::create();
		this->addChild(dlg);
	}

	
	

}