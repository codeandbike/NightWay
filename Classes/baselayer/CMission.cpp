#include "CMission.h"
#include "CStartGame.h"
#include "CWallData.h"
#include "CMainScene.h"
#include <stdio.h>
#define loadBooleanFromXML CCUserDefault::sharedUserDefault()->getBoolForKey

using namespace cocos2d;
using namespace std;


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
		//���ر���
		CCSprite *bg = CCSprite::create("missionBG.png");
		bg->setPosition(ccp(WinSize.width/2,WinSize.height/2));
		this->addChild(bg);

		//���һ�����ذ�ť
		CCMenuItemImage *pBackItem = CCMenuItemImage::create(
			"back_0.png",
			"back_1.png",
			this,
			menu_selector(CCMission::menuSceneToStart)
			);
		pBackItem->setPosition(ccp(WinSize.width - 30,WinSize.height-30));
		CCMenu * pBackMenu = CCMenu::create(pBackItem,NULL);
		pBackMenu->setPosition(CCPointZero);
		this->addChild(pBackMenu);



		//////////////////////////////////////////////////////////////////////////
		//���عؿ���ť
		//////////////////////////////////////////////////////////////////////////
		CCMenu * menu = CCMenu::create(NULL);
		CCLayer *titleLayer = CCLayer::create();
		CCLayer *lockLayer = CCLayer::create();
		//����MenuItem���ӵ�Menu��
		CCWallData * data = CCWallData::create();
		NextID = data->getNextID();
		for (int i = 0; i<data->getSceneConter();i++)
		{
			CCMenuItemImage *MeunItem = CCMenuItemImage::create(
				"missionItemBG_0.png",
				"missionItemBG_1.png",
				this,
				menu_selector(CCMission::menuSceneToGame)
				); 
			float x = WinSize.width/7*((i%6)+1);
			float y = WinSize.height/5*(4-i/6);

			MeunItem->setPosition(ccp(x,y));

			menu->addChild(MeunItem,1000+i);
			menu->setPosition(CCPointZero);

			char nmbArr[10];
			sprintf(nmbArr,"%d",1000+i);
			//string Nmb = new string(nmbArr);

			if (i+1 >= NextID)
			{
				CCSprite *lock = CCSprite::create("missionLock.png");
				lock->setPosition(ccp(x,y));
				lockLayer->addChild(lock);
			}else{

				char  s[5];
				sprintf(s,"%d",i+1);
				CCLabelTTF *title = CCLabelTTF::create(s,"STKaiti",45);
				title->setPosition(ccp(x,y));
				title->setColor(ccc3(255,255,255));
				titleLayer->addChild(title);
			}

		}
		this->addChild(menu);
		this->addChild(titleLayer);
		this->addChild(lockLayer);
		
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
	
	CCScene * s = CCStartGame::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}

/************************************************************************/
/* ��ת����Ϸ����                                                                   */
/************************************************************************/
void CCMission::menuSceneToGame(CCObject *pSender)
{
	CCMenuItemImage *u = (CCMenuItemImage*)pSender;
	int i = u->getZOrder();

	char tagNmb[10];
	sprintf(tagNmb,"%d",i);
	int sceneID = i-1000;
	if (sceneID < NextID)
	{
		CCWallData * data = CCWallData::create();
		data->setSelectID(sceneID+1);
		CCScene *s = CCMainScene::scene();
		CCDirector::sharedDirector()->replaceScene(s);
	}	

}