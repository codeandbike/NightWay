#include "CStartGame.h"
#include "CMission.h"
#include "ExitDialog.h"
#include "CSetDialog.h"
#include "CMainScene.h"
#include "CInfoDialog.h"
#include "SimpleAudioEngine.h"
#include "CWallData.h"

using namespace cocos2d;
CCStartGame::CCStartGame(void)
{
	//初始化障碍物结构体
	//data = new CCWallData;
}


CCStartGame::~CCStartGame(void)
{
}


/************************************************************************/
/* 初始化场景                                                                     */
/************************************************************************/
bool CCStartGame::init()
{
	bool sRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		//调用父类初始化
		//////////////////////////////////////////////////////////////////////////
		CC_BREAK_IF(!CCLayer::init());
		//////////////////////////////////////////////////////////////////////////
		//加载场景元素
		//////////////////////////////////////////////////////////////////////////
		//初始化数据保存文件
		CCUserDefault::sharedUserDefault()->setBoolForKey("MyDB",true);

		//获得设备尺寸
		CCSize WinSize = CCDirector::sharedDirector()->getWinSize();

		//添加一个背景
		CCSprite * bakegerad = CCSprite::create("StertGameBG.png");
		bakegerad->setPosition(ccp(WinSize.width/2,WinSize.height/2));
		this->addChild(bakegerad);

		//////////////////////////////////////////////////////////////////////////
		//添加四个按钮， 开始游戏、选择关卡、游戏设置、游戏退出
		//////////////////////////////////////////////////////////////////////////
		//开始游戏
		CCMenuItemImage *pStartItem = CCMenuItemImage::create(
			"Menu_StartGame_0.png",
			"Menu_StartGame_1.png",
			this,
			menu_selector(CCStartGame::menuBeginGame)
			);
		pStartItem->setPosition(ccp(WinSize.width/2-200,WinSize.height/6*2));
		CCMenu * pStartMenu = CCMenu::create(pStartItem,NULL);
		pStartMenu->setPosition(CCPointZero);
		this->addChild(pStartMenu);

		//选择关卡
		CCMenuItemImage *pMissionItem = CCMenuItemImage::create(
			"Menu_Mission_0.png",
			"Menu_Mission_1.png",
			this,
			menu_selector(CCStartGame::menuSceneToMission)
			);
		pMissionItem->setPosition(ccp(WinSize.width/2+200,WinSize.height/6*2));
		CCMenu * pMissionMenu = CCMenu::create(pMissionItem,NULL);
		pMissionMenu->setPosition(CCPointZero);
		this->addChild(pMissionMenu);

		//游戏设置
		CCMenuItemImage * pSetItem = CCMenuItemImage::create(
			"Menu_SetGame_0.png",
			"Menu_SetGame_1.png",
			this,
			menu_selector(CCStartGame::menuSetGame)
			);
		pSetItem->setPosition(ccp(WinSize.width/2-200,WinSize.height/6));
		CCMenu *pSetMenu = CCMenu::create(pSetItem,NULL);
		pSetMenu->setPosition(CCPointZero);
		this->addChild(pSetMenu);

		//游戏退出
		CCMenuItemImage *pQuitItem = CCMenuItemImage::create(
			"Menu_QuitGame_0.png",
			"Menu_QuitGame_1.png",
			this,
			menu_selector(CCStartGame::menuCloseCallback)
			);
		pQuitItem->setPosition(ccp(WinSize.width/2+200,WinSize.height/6));
		CCMenu * pQuitMenu = CCMenu::create(pQuitItem,NULL);
		pQuitMenu->setPosition(CCPointZero);
		this->addChild(pQuitMenu);

		//添加一个开发者信息按钮
		CCMenuItemImage *pInfoItem = CCMenuItemImage::create(
			"info_0.png",
			"info_1.png",
			this,
			menu_selector(CCStartGame::menuInfoCallback)
			);
		pInfoItem->setPosition(ccp(WinSize.width - 30,WinSize.height-30));
		CCMenu * pInfoMenu = CCMenu::create(pInfoItem,NULL);
		pInfoMenu->setPosition(CCPointZero);
		this->addChild(pInfoMenu);
		//添加背景音乐
		CCWallData *data = CCWallData::create();
		if (data->m_bMusic)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainmenu.wav",true);
		}
		sRet = true;
	} while (0);
	return sRet;
}

/************************************************************************/
/* 加载场景                                                                     */
/************************************************************************/
CCScene * CCStartGame::scene()
{
	CCScene * scene = NULL;
	do 
	{
		//创建场景
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		//创建图层
		CCStartGame * layer = CCStartGame::create();
		CC_BREAK_IF(!layer);
		//添加层
		scene->addChild(layer);
	} while (0);
	return scene;
}

/************************************************************************/
/* 开始游戏                                                                     */
/************************************************************************/
void CCStartGame::menuBeginGame(CCObject *pSender)
{
	CCScene *s = CCMainScene::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}


/************************************************************************/
/* 系统退出                                                                     */
/************************************************************************/
void CCStartGame::menuCloseCallback(CCObject *pSender)
{
	//CCDirector::sharedDirector()->end();
	ExitDlg * dlg = ExitDlg::create();
	this->addChild(dlg);
}

/************************************************************************/
/* 选择关卡                                                                     */
/************************************************************************/
void CCStartGame::menuSceneToMission(CCObject *pSender)
{
	CCScene *s = CCMission::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}

/************************************************************************/
/* 游戏设置                                                                     */
/************************************************************************/
void CCStartGame::menuSetGame(CCObject *pSender)
{
	CCSetDialog * dlg = CCSetDialog::create();
	this->addChild(dlg);
}

/************************************************************************/
/* 开发者信息回调函数                                                                     */
/************************************************************************/
void CCStartGame::menuInfoCallback(CCObject * pSender)
{
	CCInfoDialog * dlg = CCInfoDialog::create();
	this->addChild(dlg);
}
