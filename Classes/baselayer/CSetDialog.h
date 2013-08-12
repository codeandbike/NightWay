#ifndef _SETDIALOG_H_
#define _SETDIALOG_H_

#include "DialogLayer.h"

class CCSetDialog : public DialogLayer
{
public:
	CCSetDialog(void);
	~CCSetDialog(void);

public:
	/************************************************************************/
	/* 初始化对话框                                                                     */
	/************************************************************************/
	virtual bool onInitDialog();
	/************************************************************************/
	/* 创建对话框*/
	/************************************************************************/
	CREATE_FUNC(CCSetDialog);

	/************************************************************************/
	/* 确认和退出按钮                                                                     */
	/************************************************************************/
	void okMenuItemCallback(CCObject *obj);
	void cancelMenuItemCallback(CCObject *obj);
};
#endif
