#include "CWellSprite.h"

using namespace cocos2d;
CCWellSprite::CCWellSprite(void)
{
}


CCWellSprite::~CCWellSprite(void)
{
}


bool CCWellSprite::init(const char * ch,list<CCPoint> points) // ͼ���ʼ��
{
	bool sRet = false;
	do 
	{
		CC_BREAK_IF(!CCLayer::init());

		list<CCPoint>::iterator iter;
		for (iter = points.begin();iter != points.end(); iter++)
		{
			CCPoint poitn = *iter;
			CCSprite * spLead = CCSprite::create(ch);
			spLead->setPosition(poitn);
			this->addChild(spLead);
		}

		sRet = true;
	} while (0);

	return sRet;
}

CCWellSprite * CCWellSprite::create(const char * ch,list<CCPoint> points)//����ͼ��
{
	CCWellSprite *pRet = new CCWellSprite();
	if (pRet && pRet->init(ch,points))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}