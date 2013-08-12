#ifndef __STARTGAME_SCENE_H__
#define __STARTGAME_SCENE_H__

#include "cocos2d.h"


class CCStartGame : public cocos2d::CCLayer
{
public:
	CCStartGame(void);
	~CCStartGame(void);

	/************************************************************************/
	/* 创建场景                                                                     */
	/************************************************************************/
	CREATE_FUNC(CCStartGame);

	/************************************************************************/
	/* 初始化场景                                                                     */
	/************************************************************************/
	virtual bool init();

	/************************************************************************/
	/* 加载场景                                                                     */
	/************************************************************************/
	static cocos2d::CCScene * scene();

	/************************************************************************/
	/* 开始游戏                                                                     */
	/************************************************************************/
	void menuBeginGame(CCObject *pSender);

	/************************************************************************/
	/* 系统退出                                                                     */
	/************************************************************************/
	void menuCloseCallback(CCObject *pSender);
	/************************************************************************/
	/* 选择关卡                                                                     */
	/************************************************************************/
	void menuSceneToMission(CCObject *pSender);
	/************************************************************************/
	/* 游戏设置                                                                     */
	/************************************************************************/
	void menuSetGame(CCObject *pSender);

};

#endif