#ifndef __WELLSPRITE_SCENE_H__
#define __WELLSPRITE_SCENE_H__

#include "cocos2d.h"
#include <list>

using namespace std;
using namespace cocos2d;
class CCWellSprite : public cocos2d::CCLayer
{
public:
	CCWellSprite(void);
	~CCWellSprite(void);

private:
	
public:
	virtual bool init(const char * ch,list<CCPoint> points); // 图层初始化
	
	static CCWellSprite * create(const char * ch,list<CCPoint> points);//创建图层
};

#endif