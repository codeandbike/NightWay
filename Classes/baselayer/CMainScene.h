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
	//屏幕尺寸
	cocos2d::CCSize winSize;
	int SceneID; //场景ID
	cocos2d::CCLabelTTF * titleNum;
	//主角
	cocos2d::CCSprite *m_pLead;   
	CCWallData * data; //场景数据类
	//移动方向枚举
	enum direction{
		kUp,
		kDown,
		kLeft,
		kRight
	};
	//墙体颜色枚举
	enum m_pEnumWell{
		kyellow,
		kred,
		kgreen,
		kblue,
		knull
	};

	//移动方向
	int dirTag; 
	//移动量
	float MoveLength; 
	//是否有按钮按下
	bool b_ButtonDown; 
	//触碰到墙体
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
	/* 创建场景                                                                     */
	/************************************************************************/
	CREATE_FUNC(CCMainScene);
	/************************************************************************/
	/* 加载场景                                                                     */
	/************************************************************************/
	static cocos2d::CCScene * scene();
	/************************************************************************/
	/* 类初始化                                                                     */
	/************************************************************************/
	virtual bool init();

	/************************************************************************/
	/* 菜单事件回调函数                                                                     */
	/************************************************************************/
	void menuCloseCallback(CCObject * pSender);



	/************************************************************************/
	/* 主角移动                                                                     */
	/************************************************************************/
	void moveLead(float t);

	/************************************************************************/
	/* 检测碰撞                                                                     */
	/************************************************************************/
	bool seeImpact(cocos2d::CCRect leadRect);

	/************************************************************************/
	/* 碰撞处理                                                                     */
	/************************************************************************/
	void handleImpact();


	/************************************************************************/
	/*       初始化墙体集合                                                               */
	/************************************************************************/
	list<cocos2d::CCPoint> initList(int arr[][2],int n);

	/************************************************************************/
	/* 墙体消失                                                                     */
	/************************************************************************/
	void callNodeBack(CCNode *sender);
	/************************************************************************/
	/* 时间计数                                                                    */
	/************************************************************************/
	void addDataTime(float t);
	/************************************************************************/
	/*    按钮事件回调函数                                                                  */
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

