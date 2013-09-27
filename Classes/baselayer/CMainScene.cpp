#include "CMainScene.h"
#include "CStartGame.h"
#include "CWellSprite.h"
#include "CWinDialog.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
CCMainScene::CCMainScene(void)
{
	//��ʼ���ƶ�ƫ����
	MoveLength = CCDirector::sharedDirector()->getWinSize().height/480*4;
	//��ʼ����ť״̬
	b_ButtonDown = false;
	//��ʼ���ϰ���ṹ��
	data = CCWallData::create();
	SceneID = data->getSelectID();
	data->setDataTime(0);
	data->getWall(SceneID,&sceneWall.red_wall,&sceneWall.yellow_wall,&sceneWall.blue_wall,&sceneWall.green_wall);

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
		//��ӱ���
		CCSprite * bgSprite = CCSprite::create("mainGameBG.png");
		bgSprite->setPosition(ccp(winSize.width/2,winSize.height/2));
		this->addChild(bgSprite);

		//���һ�����ذ�ť
		CCMenuItemImage *pBackItem = CCMenuItemImage::create(
			"back_0.png",
			"back_1.png",
			this,
			menu_selector(CCMainScene::menuCloseCallback)
			);
		pBackItem->setPosition(ccp(winSize.width - 30,winSize.height-30));
		CCMenu * pBackMenu = CCMenu::create(pBackItem,NULL);
		pBackMenu->setPosition(CCPointZero);
		this->addChild(pBackMenu);


		//��ʼ�����ǲ���ӵ�����
		m_pLead = CCSprite::create("Lead.PNG");
		m_pLead->setPosition(data->getLeadPosition());
		this->addChild(m_pLead);


		//��Ӳ��԰�ť

		//////////////////////////////////////////////////////////////////////////
		//��ӿ��ư�ť  ��ʼ
		//////////////////////////////////////////////////////////////////////////

		//�������ϰ�ť
		CCScale9Sprite *btnNormal = CCScale9Sprite::create("up2.png");
		CCScale9Sprite *btnSelected = CCScale9Sprite::create("up1.png");
		CCControlButton *pButtonUP = CCControlButton::create(btnNormal);
		pButtonUP->setPreferredSize(CCSizeMake(70,70));
		pButtonUP->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonUP->setPosition(ccp(winSize.width/16*13,winSize.width/16*4.5));
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp),CCControlEventTouchDown);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpInside);
		pButtonUP->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideUp2),CCControlEventTouchUpOutside);
		this->addChild(pButtonUP);

		//������°�ť
		btnNormal = CCScale9Sprite::create("down2.png");
		btnSelected = CCScale9Sprite::create("down1.png");
		CCControlButton *pButtonDown = CCControlButton::create(btnNormal);
		pButtonDown->setPreferredSize(CCSizeMake(70,70));
		pButtonDown->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonDown->setPosition(ccp(winSize.width/16*13,winSize.width/16*1.5));
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown),CCControlEventTouchDown);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown2),CCControlEventTouchUpInside);
		pButtonDown->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideDown2),CCControlEventTouchUpOutside);
		this->addChild(pButtonDown);

		//�������ť
		btnNormal = CCScale9Sprite::create("left2.png");
		btnSelected = CCScale9Sprite::create("left1.png");
		CCControlButton *pButtonLeft = CCControlButton::create(btnNormal);
		pButtonLeft->setPreferredSize(CCSizeMake(70,70));
		pButtonLeft->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonLeft->setPosition(ccp(winSize.width/16*11.5,winSize.width/16*3));
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft),CCControlEventTouchDown);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft2),CCControlEventTouchUpInside);
		pButtonLeft->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideLeft2),CCControlEventTouchUpOutside);
		this->addChild(pButtonLeft);

		//������Ұ�ť
		btnNormal = CCScale9Sprite::create("right2.png");
		btnSelected = CCScale9Sprite::create("right1.png");
		CCControlButton *pButtonRight = CCControlButton::create(btnNormal);
		pButtonRight->setPreferredSize(CCSizeMake(70,70));
		pButtonRight->setBackgroundSpriteForState(btnSelected,CCControlStateSelected);
		pButtonRight->setPosition(ccp(winSize.width/16*14.5,winSize.width/16*3));
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight),CCControlEventTouchDown);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight2),CCControlEventTouchUpInside);
		pButtonRight->addTargetWithActionForControlEvents(this,cccontrol_selector(CCMainScene::touchDragInsideRight2),CCControlEventTouchUpOutside);
		this->addChild(pButtonRight);

		//////////////////////////////////////////////////////////////////////////
		//��ӿ��ư�ť  ����
		//////////////////////////////////////////////////////////////////////////

		//��Ӽ�ʱ��
		this->schedule(schedule_selector(CCMainScene::addDataTime),1.0);

		titleNum = CCLabelTTF::create("","",45);
		titleNum->setPosition(ccp(80,20));
		titleNum->setColor(ccc3(255,255,255));
		this->addChild(titleNum);

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
		
		CCPoint temp = *iter;
		CCRect wellRect = CCRectMake(temp.x-5,temp.y-5,10,10); 
		if (leadRect.intersectsRect(wellRect))
		{
			m_pTagWell = kblue;
			return false;
		}

	}

	//�ж��Ƿ��ƶ���������˵����Ϸ����
	if (leadRect.getMinX()<0 || leadRect.getMinY()<0 || leadRect.getMaxX() > 500 || leadRect.getMaxY() >480)
	{
		m_pTagWell = knull;
		return false;
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
	this->removeChild(sprite,true);
}


/************************************************************************/
/* ��ײ����                                                                     */
/************************************************************************/
void CCMainScene::handleImpact()
{
	CCWallData *data = CCWallData::create();
	if (data->m_bsound)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("snd_pusharpshot.wav");
	}

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
	case knull://�ƶ���������˵����Ϸ����
		{
			this->unschedule(schedule_selector(CCMainScene::moveLead));//ֹͣ�ƶ�
			this->unschedule(schedule_selector(CCMainScene::addDataTime));
			CCWinDialog *dlg = CCWinDialog::create();
			this->addChild(dlg);
		}
		break;
	default:
		break;
	}
}


/************************************************************************/
/* ʱ�����                                                                    */
/************************************************************************/
void CCMainScene::addDataTime(float t)
{
	CCWallData *data = CCWallData::create();
	data->setDataTime(data->getDataTime()+1);

	char  s[10];
	sprintf(s,"%d",data->getDataTime());
	titleNum->setString(s);

}