#ifndef __MAINSCENE_SCENE_H__
#define __MAINSCENE_SCENE_H__

#include "cocos-ext.h"
#include "cocos2d.h"
#include <list>
#include "CWallData.h"

USING_NS_CC_EXT;  
using namespace std;
class CCMainScene : public cocos2d::CCLayer
{

private:
	//��Ļ�ߴ�
	cocos2d::CCSize winSize;
	int SceneID; //����ID
	cocos2d::CCLabelTTF * titleNum;
	//����
	cocos2d::CCSprite *m_pLead;   
	CCWallData * data; //����������
	//�ƶ�����ö��
	enum direction{
		kUp,
		kDown,
		kLeft,
		kRight
	};
	//ǽ����ɫö��
	enum m_pEnumWell{
		kyellow,
		kred,
		kgreen,
		kblue,
		knull
	};

	//�ƶ�����
	int dirTag; 
	//�ƶ���
	float MoveLength; 
	//�Ƿ��а�ť����
	bool b_ButtonDown; 
	//������ǽ��
	int m_pTagWell; 

	struct struct_wall
	{
		list<cocos2d::CCPoint> yellow_wall;
		list<cocos2d::CCPoint> red_wall;
		list<cocos2d::CCPoint> green_wall;
		list<cocos2d::CCPoint> blue_wall;
	};

	struct_wall sceneWall;
	
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
	/* �˵��¼��ص�����                                                                     */
	/************************************************************************/
	void menuCloseCallback(CCObject * pSender);



	/************************************************************************/
	/* �����ƶ�                                                                     */
	/************************************************************************/
	void moveLead(float t);

	/************************************************************************/
	/* �����ײ                                                                     */
	/************************************************************************/
	bool seeImpact(cocos2d::CCRect leadRect);

	/************************************************************************/
	/* ��ײ����                                                                     */
	/************************************************************************/
	void handleImpact();


	/************************************************************************/
	/*       ��ʼ��ǽ�弯��                                                               */
	/************************************************************************/
	list<cocos2d::CCPoint> initList(int arr[][2],int n);

	/************************************************************************/
	/* ǽ����ʧ                                                                     */
	/************************************************************************/
	void callNodeBack(CCNode *sender);
	/************************************************************************/
	/* ʱ�����                                                                    */
	/************************************************************************/
	void addDataTime(float t);
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

