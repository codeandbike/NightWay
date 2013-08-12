#include "CStartGame.h"
#include "CMission.h"
using namespace cocos2d;
CCStartGame::CCStartGame(void)
{
}


CCStartGame::~CCStartGame(void)
{
}


/************************************************************************/
/* ��ʼ������                                                                     */
/************************************************************************/
bool CCStartGame::init()
{
	bool sRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		//���ø����ʼ��
		//////////////////////////////////////////////////////////////////////////
		CC_BREAK_IF(!CCLayer::init());
		//////////////////////////////////////////////////////////////////////////
		//���س���Ԫ��
		//////////////////////////////////////////////////////////////////////////
		//����豸�ߴ�
		CCSize WinSize = CCDirector::sharedDirector()->getWinSize();

		//���һ������
		CCSprite * bakegerad = CCSprite::create("StertGameBG.png");
		bakegerad->setPosition(ccp(WinSize.width/2,WinSize.height/2));
		this->addChild(bakegerad);

		//////////////////////////////////////////////////////////////////////////
		//����ĸ���ť�� ��ʼ��Ϸ��ѡ��ؿ�����Ϸ���á���Ϸ�˳�
		//////////////////////////////////////////////////////////////////////////
		//��ʼ��Ϸ
		CCMenuItemImage *pStartItem = CCMenuItemImage::create(
			"Menu_StartGame_0.png",
			"Menu_StartGame_1.png",
			this,
			NULL
			);
		pStartItem->setPosition(ccp(WinSize.width/2,WinSize.height/6*4));
		CCMenu * pStartMenu = CCMenu::create(pStartItem,NULL);
		pStartMenu->setPosition(CCPointZero);
		this->addChild(pStartMenu);

		//ѡ��ؿ�
		CCMenuItemImage *pMissionItem = CCMenuItemImage::create(
			"Menu_Mission_0.png",
			"Menu_Mission_1.png",
			this,
			menu_selector(CCStartGame::menuSceneToMission)
			);
		pMissionItem->setPosition(ccp(WinSize.width/2,WinSize.height/6*3));
		CCMenu * pMissionMenu = CCMenu::create(pMissionItem,NULL);
		pMissionMenu->setPosition(CCPointZero);
		this->addChild(pMissionMenu);

		//��Ϸ����
		CCMenuItemImage * pSetItem = CCMenuItemImage::create(
			"Menu_SetGame_0.png",
			"Menu_SetGame_1.png",
			this,
			NULL
			);
		pSetItem->setPosition(ccp(WinSize.width/2,WinSize.height/6*2));
		CCMenu *pSetMenu = CCMenu::create(pSetItem,NULL);
		pSetMenu->setPosition(CCPointZero);
		this->addChild(pSetMenu);

		//��Ϸ�˳�
		CCMenuItemImage *pQuitItem = CCMenuItemImage::create(
			"Menu_QuitGame_0.png",
			"Menu_QuitGame_1.png",
			this,
			menu_selector(CCStartGame::menuCloseCallback)
			);
		pQuitItem->setPosition(ccp(WinSize.width/2,WinSize.height/6));
		CCMenu * pQuitMenu = CCMenu::create(pQuitItem,NULL);
		pQuitMenu->setPosition(CCPointZero);
		this->addChild(pQuitMenu);

		sRet = true;
	} while (0);
	return sRet;
}

/************************************************************************/
/* ���س���                                                                     */
/************************************************************************/
CCScene * CCStartGame::scene()
{
	CCScene * scene = NULL;
	do 
	{
		//��������
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		//����ͼ��
		CCStartGame * layer = CCStartGame::create();
		CC_BREAK_IF(!layer);
		//��Ӳ�
		scene->addChild(layer);
	} while (0);
	return scene;
}

/************************************************************************/
/* ϵͳ�˳�                                                                     */
/************************************************************************/
void CCStartGame::menuCloseCallback(CCObject *pSender)
{
	CCDirector::sharedDirector()->end();

	
}

/************************************************************************/
/* ѡ��ؿ�                                                                     */
/************************************************************************/
void CCStartGame::menuSceneToMission(CCObject *pSender)
{
	CCScene *s = CCMission::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}
