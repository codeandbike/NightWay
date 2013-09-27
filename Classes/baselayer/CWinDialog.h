#ifndef _WINDLG_H_
#define _WINDLG_H_

#include "DialogLayer.h"

class CCWinDialog :public DialogLayer
{
public:
	CCWinDialog(void);
	~CCWinDialog(void);

	/************************************************************************/
	/* 初始化对话框                                                                     */
	/************************************************************************/
	virtual bool onInitDialog();
	/************************************************************************/
	/* 创建对话框*/
	/************************************************************************/
	CREATE_FUNC(CCWinDialog);

	/************************************************************************/
	/* 返回和下一关按钮                                                                     */
	/************************************************************************/
	void backMenuItemCallback(CCObject *obj);
	void nextMenuItemCallback(CCObject *obj);
};

#endif