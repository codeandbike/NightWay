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
/* ��ʼ������                                                                     */
/************************************************************************/
bool CCMission::init()
{
	bool sRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		//��ʼ������
		//////////////////////////////////////////////////////////////////////////
		CC_BREAK_IF(!CCLayer::create());
		//////////////////////////////////////////////////////////////////////////
		//����ͼ��Ԫ��
		//////////////////////////////////////////////////////////////////////////
		//����豸�ߴ�
		CCSize WinSize = CCDirector::sharedDirector()->getWinSize();
		//���عؿ���ť
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
/* ���س���                                                                     */
/************************************************************************/
CCScene * CCMission::scene()
{
	CCScene * scene = NULL;
	do 
	{
		//��������
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		//������
		CCMission *layer = CCMission::create();
		CC_BREAK_IF(!layer);
		//���ͼ��
		scene->addChild(layer);
	} while (0);
	return scene;
}

/************************************************************************/
/* ��������ҳ��                                                                     */
/************************************************************************/
void CCMission::menuSceneToStart(CCObject *pSender)
{
	CCScene *s = CCStartGame::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}