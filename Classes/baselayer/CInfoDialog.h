#ifndef _INFODLG_H_
#define _INFODLG_H_

#include "DialogLayer.h"

class CCInfoDialog :public DialogLayer
{
public:
	CCInfoDialog(void);
	~CCInfoDialog(void);

	/************************************************************************/
	/* ��ʼ���Ի���                                                                     */
	/************************************************************************/
	virtual bool onInitDialog();
	/************************************************************************/
	/* �����Ի���*/
	/************************************************************************/
	CREATE_FUNC(CCInfoDialog);

	/************************************************************************/
	/* ���غ���һ�ذ�ť                                                                     */
	/************************************************************************/
	void backMenuItemCallback(CCObject *obj);
};

#endif