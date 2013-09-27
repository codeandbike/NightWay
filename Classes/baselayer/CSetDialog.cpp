#include "CSetDialog.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "CWallData.h"
USING_NS_CC;
using namespace cocos2d;


CCSetDialog::CCSetDialog(void)
{
	m_bmusic = true;
}


CCSetDialog::~CCSetDialog(void)
{
}


/************************************************************************/
/* ��ʼ���Ի���                                                                     */
/************************************************************************/
bool CCSetDialog::onInitDialog()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	//��ӱ���
	CCSprite * bg = CCSprite::create("dialogSetBG.png");
	bg->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(bg);

	//ȷ����ť
	CCMenuItemImage *okMenuItem = CCMenuItemImage::create(
		"buttonDlgOk_0.png",
		"buttonDlgOk_1.png",
		this, 
		menu_selector(CCSetDialog::okMenuItemCallback)
		);
	okMenuItem->setPosition(ccp(winSize.width / 2 - 100, winSize.height / 2 - 70));
	//ȡ����ť
	CCMenuItemImage *cancelMenuItem = CCMenuItemImage::create(
		"buttonDlgCancel_0.png", 
		"buttonDlgCancel_1.png", 
		this,
		menu_selector(CCSetDialog::cancelMenuItemCallback)
		);
	cancelMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2 - 70));
	//���������
	CCWallData *data = CCWallData::create();
	//��Ч����
	CCMenuItemToggle * soundMenuItem =CCMenuItemToggle::createWithTarget(
		this,
		menu_selector(CCSetDialog::soundMenuCallback),
		CCMenuItemFont::create("On"),
		CCMenuItemFont::create("Off"),
		NULL
		);
	soundMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2+30));
	if (!data->m_bsound)
	{
		soundMenuItem->setSelectedIndex(1);
	}
	

		//���ֿ���
	CCMenuItemToggle * musicMenuItem =CCMenuItemToggle::createWithTarget(
		this,
		menu_selector(CCSetDialog::musicMenuCallback),
		CCMenuItemFont::create("On"),
		CCMenuItemFont::create("Off"),
		NULL
		);
	musicMenuItem->setPosition(ccp(winSize.width / 2 - 30, winSize.height / 2+30));
	if (!data->m_bMusic)
	{
		musicMenuItem->setSelectedIndex(1);
	}
	
	

	pushMenu(okMenuItem);
	pushMenu(cancelMenuItem);
	pushMenu(soundMenuItem);
	pushMenu(musicMenuItem);


	setColor(ccc3(150,150,150));
	setOpacity(210);
	return true;
}


/************************************************************************/
/* ȷ�Ϻ��˳���ť                                                                     */
/************************************************************************/
void CCSetDialog::okMenuItemCallback(CCObject *obj)
{
	removeFromParentAndCleanup(true);
}
void CCSetDialog::cancelMenuItemCallback(CCObject *obj)
{
	removeFromParentAndCleanup(true);
}

/************************************************************************/
/* �������ֿ���                                                                     */
/************************************************************************/
void CCSetDialog::musicMenuCallback(CCObject *obj)
{
	CCWallData *data = CCWallData::create();
	if (data->m_bMusic)
	{
		data->m_bMusic = !data->m_bMusic;
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}else{
		data->m_bMusic = !data->m_bMusic;
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
	
	
}
/************************************************************************/
/* ��Ч����                                                                     */
/************************************************************************/
void CCSetDialog::soundMenuCallback(CCObject *obj)
{
	CCWallData *data = CCWallData::create();
	if (data->m_bsound)
	{
		data->m_bsound = !data->m_bsound;
	}else{
		data->m_bsound = !data->m_bsound;
	}
}