#include "CMainScene.h"
#include "CStartGame.h"
#include "CWellSprite.h"

using namespace cocos2d;
CCMainScene::CCMainScene(void)
{
	//��ʼ���ƶ�ƫ����
	MoveLength = CCDirector::sharedDirector()->getWinSize().height/480*5;
	//��ʼ����ť״̬
	b_ButtonDown = false;
	//��ʼ���ϰ���ṹ��
	//����ȡֵ��Χ[0][0] -> [27][32]
	int yellowArr[118][2] = {{1,0},{2,0},{3,0},{4,0},{5,0}};
	int redArr[5][2] = {{1,4},{2,4},{3,4},{4,4},{5,4}};
	int greenArr[5][2] = {{1,8},{2,8},{3,8},{4,8},{5,8}};
	int blueArr[5][2] = {{1,12},{2,12},{3,12},{4,12},{5,12}};

	sceneWall.yellow_wall = initList(yellowArr,118);
	sceneWall.red_wall = initList(redArr,5);
	sceneWall.green_wall = initList(greenArr,5);
	sceneWall.blue_wall = initList(blueArr,5);
	
}


CCMainScene::~CCMainScene(void)
{
}

/************************************************************************/
/* ���س���                                                                     */
/************************************************************************/
CCScene * CCMainScene::scene()
{
	CCScene *scene = NULL;
	do 
	{
		//��������
		scene = CCScene::create();
		CC_BREAK_IF(!scene);
		//������
		CCMainScene *layer = CCMainScene::create();
		CC_BREAK_IF(!layer);
		//��Ӳ�
		scene->addChild(layer);
	} while (0);
	return scene;
}
/************************************************************************/
/* ���ʼ��                                                                     */
/************************************************************************/
bool CCMainScene::init()
{
	bool sRet = false;
	do 
	{
		//////////////////////////////////////////////////////////////////////////
		//��ʼ������
		//////////////////////////////////////////////////////////////////////////
		CC_BREAK_IF(!CCLayer::create());
		//////////////////////////////////////////////////////////////////////////
		//����Ԫ�ش���
		//////////////////////////////////////////////////////////////////////////	

		//��ȡ��Ļ�ߴ�
		winSize = CCDirector::sharedDirector()->getWinSize();
		//���һ���˵���ť
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(CCMainScene::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);
		pCloseItem->setPosition(ccp(winSize.width - 20, winSize.height-20));
		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);
		this->addChild(pMenu, 1);

		//��ʼ�����ǲ���ӵ�����
		m_pLead = CCSprite::create("Lead.PNG");
		m_pLead->setPosition(ccp(winSize.width/2,winSize.height/2));
		this->addChild(m_pLead);

		//////////////////////////////////////////////////////////////////////////
		//��ӿ��ư�ť  ��ʼ
		//////////////////////////////////////////////////////////////////////////

		//�������ϰ�ť
		CCScale9Sprite *btnNormal = CCScale9Sprite::create("up2.png");
		CCScale9Sprite *btnSelected = CCScale9Sprite::create("up1.png");
		CCControlButton *pButtonUP = CCControlButton::create(btnNormal);
		pButtonUP->setPreferredSize(CCSizeMake(48,48));
		pButtonUP->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonUP->setPosition(ccp(winSize.width/2,((150/4)*3)+12.5));
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp),CCControlEventTouchDown);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpInside);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonUP);

		//������°�ť
		btnNormal = CCScale9Sprite::create("down2.png");
		btnSelected = CCScale9Sprite::create("down1.png");
		CCControlButton *pButtonDown = CCControlButton::create(btnNormal);
		pButtonDown->setPreferredSize(CCSizeMake(48,48));
		pButtonDown->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonDown->setPosition(ccp(winSize.width/2,(150/4)-12.5));
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown),CCControlEventTouchDown);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown2),CCControlEventTouchUpInside);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonDown);

		//�������ť
		btnNormal = CCScale9Sprite::create("left2.png");
		btnSelected = CCScale9Sprite::create("left1.png");
		CCControlButton *pButtonLeft = CCControlButton::create(btnNormal);
		pButtonLeft->setPreferredSize(CCSizeMake(48,48));
		pButtonLeft->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonLeft->setPosition(ccp((winSize.width/2)-48,150/2));
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft),CCControlEventTouchDown);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft2),CCControlEventTouchUpInside);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonLeft);

		//������Ұ�ť
		btnNormal = CCScale9Sprite::create("right2.png");
		btnSelected = CCScale9Sprite::create("right1.png");
		CCControlButton *pButtonRight = CCControlButton::create(btnNormal);
		pButtonRight->setPreferredSize(CCSizeMake(48,48));
		pButtonRight->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonRight->setPosition(ccp((winSize.width/2)+48,150/2));
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight),CCControlEventTouchDown);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight2),CCControlEventTouchUpInside);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonRight);

		//////////////////////////////////////////////////////////////////////////
		//��ӿ��ư�ť  ����
		//////////////////////////////////////////////////////////////////////////


		sRet = true;
	} while (0);
	return sRet;
}




/************************************************************************/
/*   ��ť�¼��ص����� ��ʼ                                                                   */
/************************************************************************/
void CCMainScene::touchDragInsideUp(CCObject* pSender, CCControlEvent event)
{


	if (!b_ButtonDown)
	{	
		dirTag = kUp;
		this->schedule(schedule_selector(CCMainScene::moveLead),0.005f);
		b_ButtonDown = true;
	}

}
void CCMainScene::touchDragInsideDown(CCObject* pSender, CCControlEvent event)
{

	if (!b_ButtonDown)
	{
		dirTag = kDown;
		this->schedule(schedule_selector(CCMainScene::moveLead),0.005f);
		b_ButtonDown = true;
	}


}
void CCMainScene::touchDragInsideLeft(CCObject* pSender, CCControlEvent event)
{

	if (!b_ButtonDown)
	{
		b_ButtonDown = true;
		dirTag = kLeft;
		this->schedule(schedule_selector(CCMainScene::moveLead),0.005f);
	}



}
void CCMainScene::touchDragInsideRight(CCObject* pSender, CCControlEvent event)
{

	if (!b_ButtonDown)
	{
		dirTag = kRight;
		this->schedule(schedule_selector(CCMainScene::moveLead),0.005f);
		b_ButtonDown=true;
	}


}


void CCMainScene::touchDragInsideUp2(CCObject* pSender, CCControlEvent event)
{

	if (dirTag == kUp)
	{
		this->unschedule(schedule_selector(CCMainScene::moveLead));
		b_ButtonDown = false;
	}


}
void CCMainScene::touchDragInsideDown2(CCObject* pSender, CCControlEvent event)
{

	if (dirTag == kDown)
	{
		this->unschedule(schedule_selector(CCMainScene::moveLead));
		b_ButtonDown = false;
	}

}
void CCMainScene::touchDragInsideLeft2(CCObject* pSender, CCControlEvent event)
{

	if (dirTag == kLeft)
	{
		this->unschedule(schedule_selector(CCMainScene::moveLead));
		b_ButtonDown = false;
	}

}
void CCMainScene::touchDragInsideRight2(CCObject* pSender, CCControlEvent event)
{

	if (dirTag == kRight)
	{
		this->unschedule(schedule_selector(CCMainScene::moveLead));
		b_ButtonDown = false;
	}

}

/************************************************************************/
/*      ��ť�¼��ص����� ����                                                                */
/************************************************************************/


/************************************************************************/
/* �˵��¼��ص�����                                                                     */
/************************************************************************/
void CCMainScene::menuCloseCallback(CCObject * pSender)
{
	CCScene * s = CCStartGame::scene();
	CCDirector::sharedDirector()->replaceScene(s);
}

/************************************************************************/
/* �����ƶ�                                                                     */
/************************************************************************/
void CCMainScene::moveLead(float t)
{
	//����ѡ�����ƶ�����


	//�����ƶ���λ��
	CCRect leadRect;
	switch(dirTag)
	{
	case kUp:
		//��ȡ�ƶ���λ��
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f,m_pLead->getPositionY()-2.5f+MoveLength,5,5);
		if (seeImpact(leadRect))
		{
			this->m_pLead->setPositionY(this->m_pLead->getPositionY()+MoveLength);
		}else
		{
			handleImpact();
		}
		break;
	case kDown:
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f,m_pLead->getPositionY()-2.5f-MoveLength,5,5);
		if (seeImpact(leadRect))
		{
			this->m_pLead->setPositionY(this->m_pLead->getPositionY()-MoveLength);
		}
		else
		{

			handleImpact();
		}
		break;
	case kLeft:
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f-MoveLength,m_pLead->getPositionY()-2.5f,5,5);
		if (seeImpact(leadRect))
		{
			this->m_pLead->setPositionX(this->m_pLead->getPositionX()-MoveLength);
		}
		else
		{
			handleImpact();
		}
		break;
	case kRight:
		leadRect = CCRectMake(m_pLead->getPositionX()-2.5f+MoveLength,m_pLead->getPositionY()-2.5f,5,5);
		if (seeImpact(leadRect))
		{
			this->m_pLead->setPositionX(this->m_pLead->getPositionX()+MoveLength);
		}
		else
		{

			handleImpact();
		}
		break;
	default:

		break;
	}

}


/************************************************************************/
/* �����ײ                                                                     */
/************************************************************************/
bool CCMainScene::seeImpact(CCRect leadRect)
{

	list<CCPoint>::iterator iter;
	//�ж��Ƿ�ײ�ϻ�ɫǽ��
	for (iter = sceneWall.yellow_wall.begin();iter!=sceneWall.yellow_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kyellow;
			return false;
		}

	}
	//�ж��Ƿ�ײ�Ϻ�ɫǽ��
	for (iter = sceneWall.red_wall.begin();iter!=sceneWall.red_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kred;
			return false;
		}

	}

	//�ж��Ƿ�ײ����ɫǽ��
	for (iter = sceneWall.green_wall.begin();iter!=sceneWall.green_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kgreen;
			return false;
		}

	}

	//�ж��Ƿ�ײ����ɫǽ��
	for (iter = sceneWall.blue_wall.begin();iter!=sceneWall.blue_wall.end();iter++)
	{
		//list<CCPoint>::iterator iter = yellow_wall.begin()+i;
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kblue;
			return false;
		}

	}

	return true;
}

/************************************************************************/
/*       ��ʼ��ǽ�弯��                                                               */
/************************************************************************/
list<CCPoint> CCMainScene::initList(int arr[][2],int n)
{
	list<CCPoint> temp;
	for (int i=0; i<n;i++)
	{
		int k = arr[i][0];
		int j = arr[i][1];
		temp.push_back(ccp((k*10)+5,(j*10)+5));
	}
	return temp;

}


/************************************************************************/
/* ǽ����ʧ                                                                     */
/************************************************************************/
void CCMainScene::callNodeBack(CCNode *sender)
{
	CCWellSprite * sprite = (CCWellSprite *)sender;
	this->removeChild(sprite);
}


/************************************************************************/
/* ��ײ����                                                                     */
/************************************************************************/
void CCMainScene::handleImpact()
{
	switch(m_pTagWell)
	{
	case kyellow:
		{
			CCWellSprite * yellow_Sprite = CCWellSprite::create("yellow.png",sceneWall.yellow_wall);
			this->addChild(yellow_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCMainScene::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			yellow_Sprite->runAction(seq);
		}
		break;

	case kred:
		{
			CCWellSprite * red_Sprite = CCWellSprite::create("red.png",sceneWall.red_wall);
			this->addChild(red_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCMainScene::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			red_Sprite->runAction(seq);
		}
		break;
	case kgreen:
		{
			CCWellSprite * green_Sprite = CCWellSprite::create("green.png",sceneWall.green_wall);
			this->addChild(green_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCMainScene::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			green_Sprite->runAction(seq);
		}
		break;
	case kblue:
		{
			CCWellSprite * blue_Sprite = CCWellSprite::create("blue.png",sceneWall.blue_wall);
			this->addChild(blue_Sprite);

			CCFadeOut* fadeOut = CCFadeOut::create(0.2f);
			CCCallFuncN *callN = CCCallFuncN::create(this,callfuncN_selector(CCMainScene::callNodeBack));
			CCFiniteTimeAction * seq = CCSequence::create(fadeOut,callN,NULL);
			blue_Sprite->runAction(seq);
		}
		break;

	default:
		break;
	}
}