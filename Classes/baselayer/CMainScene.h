#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos-ext.h"
#include "cocos2d.h"
USING_NS_CC_EXT;  

class CCMainScene : public cocos2d::CCLayer
{
public:
	CCMainScene(void);
	~CCMainScene(void);
	/************************************************************************/
	/* ��������                                                                     */
	/************************************************************************/
	CREATE_FUNC(CCMainScene);
	/************************************************************************/
	/* ���س���                                                                     */
	/************************************************************************/
	static cocos2d::CCScene * scene();
	/************************************************************************/
	/* ���ʼ��                                                                     */
	/************************************************************************/
	virtual bool init();

	/************************************************************************/
	/*    ��ť�¼��ص�����                                                                  */
	/************************************************************************/
	void touchDragInsideUp(CCObject* pSender, CCControlEvent event);
	void touchDragInsideDown(CCObject* pSender, CCControlEvent event);
	void touchDragInsideLeft(CCObject* pSender, CCControlEvent event);	
	void touchDragInsideRight(CCObject* pSender, CCControlEvent event);

	void touchDragInsideUp2(CCObject* pSender, CCControlEvent event);
	void touchDragInsideDown2(CCObject* pSender, CCControlEvent event);
	void touchDragInsideLeft2(CCObject* pSender, CCControlEvent event);	
	void touchDragInsideRight2(CCObject* pSender, CCControlEvent event);

};

#endif

