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
	/* ��ʼ���Ի���                                                                     */
	/************************************************************************/
	virtual bool onInitDialog();
	/************************************************************************/
	/* �����Ի���*/
	/************************************************************************/
	CREATE_FUNC(CCSetDialog);

	/************************************************************************/
	/* ȷ�Ϻ��˳���ť                                                                     */
	/************************************************************************/
	void okMenuItemCallback(CCObject *obj);
	void cancelMenuItemCallback(CCObject *obj);
};
#endif
