#include "CMainScene.h"

using namespace cocos2d;
CCMainScene::CCMainScene(void)
{
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
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();


		sRet = true;
	} while (0);
	return sRet;
}
