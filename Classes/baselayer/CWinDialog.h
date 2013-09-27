#ifndef _WINDLG_H_
#define _WINDLG_H_

#include "DialogLayer.h"

class CCWinDialog :public DialogLayer
{
public:
	CCWinDialog(void);
	~CCWinDialog(void);

	/************************************************************************/
	/* ��ʼ���Ի���                                                                     */
	/************************************************************************/
	virtual bool onInitDialog();
	/************************************************************************/
	/* �����Ի���*/
	/************************************************************************/
	CREATE_FUNC(CCWinDialog);

	/************************************************************************/
	/* ���غ���һ�ذ�ť                                                                     */
	/************************************************************************/
	void backMenuItemCallback(CCObject *obj);
	void nextMenuItemCallback(CCObject *obj);
};

#endif