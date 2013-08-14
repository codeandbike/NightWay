#include "CMission.h"
#include "CStartGame.h"
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

		//���عؿ���ť
// 		CCScale9Sprite *butNormal = CCScale9Sprite::create("missionItemBG_0.png");
// 		CCScale9Sprite *butSelected = CCScale9Sprite::create("missionItemBG_1.png");
// 		CCLabelTTF * title = CCLabelTTF::create("1","Arial",20);
// 		CCControlButton *pButton  = CCControlButton::create(butNormal);
// 		pButton->setPreferredSize(CCSizeMake(66,66));
// 		pButton->setBackgroundSpriteForState(butSelected,CCControlStateSelected);
// 		pButton->setPosition(ccp(WinSize.width/2,WinSize.height/2));
// 		this->addChild(pButton);
		//////////////////////////////////////////////////////////////////////////
		//���عؿ���ť
		//////////////////////////////////////////////////////////////////////////
		CCMenu * menu = CCMenu::create(NULL);
		CCLayer *titleLayer = CCLayer::create();
		CCLayer *lockLayer = CCLayer::create();
		//����MenuItem���ӵ�Menu��
		for (int i = 0; i<5;i++)
		{
			CCMenuItemImage *MeunItem = CCMenuItemImage::create(
				"missionItemBG_0.png",
				"missionItemBG_1.png",
				this,
				menu_selector(CCMission::menuSceneToStart)
				); 
			MeunItem->setPosition(ccp(WinSize.width/6*(i+1),WinSize.height/2));

			menu->addChild(MeunItem,1000+i);
			menu->setPosition(CCPointZero);

			char  s[5];
			sprintf(s,"%d",i+1);

			CCLabelTTF *title = CCLabelTTF::create(s,"",60);
			title->setPosition(ccp(WinSize.width/6*(i+1),WinSize.height/2));
			title->setColor(ccc3(82,255,82));
			titleLayer->addChild(title);
			//CCUserDefault::sharedUserDefault()->getBoolForKey("lock1",false);
 
			char nmbArr[10];
			sprintf(nmbArr,"%d",1000+i);
			//string Nmb = new string(nmbArr);

			if (!loadBooleanFromXML(nmbArr,false))
			{
				CCSprite *lock = CCSprite::create("missionLock.png");
				lock->setPosition(ccp(WinSize.width/6*(i+1)-20,WinSize.height/2-16));
				lockLayer->addChild(lock);
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
	CCMenuItemImage *u = (CCMenuItemImage*)pSender;
	int i = u->getZOrder();

// 	if (1001 == i)
// 	{
// 		CCScene *s = CCStartGame::scene();
// 		CCDirector::sharedDirector()->replaceScene(s);
// 	}

	char tagNmb[10];
	sprintf(tagNmb,"%d",i);
	switch(i)
	{
	case 1000:
		{
			if (loadBooleanFromXML(tagNmb,false))
			{
				CCScene *s = CCStartGame::scene();
				CCDirector::sharedDirector()->replaceScene(s);
			}
		}
		break;
	case 1001:
		{
			if (loadBooleanFromXML(tagNmb,false))
			{
				CCScene *s = CCStartGame::scene();
				CCDirector::sharedDirector()->replaceScene(s);
			}
		}
		break;
	case 1002:
		{
			if (loadBooleanFromXML(tagNmb,false))
			{
				CCScene *s = CCStartGame::scene();
				CCDirector::sharedDirector()->replaceScene(s);
			}
		}
		break;
	case 1003:
		{
			if (loadBooleanFromXML(tagNmb,false))
			{
				CCScene *s = CCStartGame::scene();
				CCDirector::sharedDirector()->replaceScene(s);
			}
		}
		break;
	case 1004:
		{
			if (loadBooleanFromXML(tagNmb,false))
			{
				CCScene *s = CCStartGame::scene();
				CCDirector::sharedDirector()->replaceScene(s);
			}
		}
		break;
	default:
		break;

	}
		

}