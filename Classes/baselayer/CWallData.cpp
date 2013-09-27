#include "CWallData.h"

CCWallData * CCWallData::m_pWallData = NULL;

CCWallData::CCWallData(void)
{
	sceneConfigPath = "config_path.json";
	IniScenePath();
	sceneNext = CCUserDefault::sharedUserDefault()->getIntegerForKey("NextID",1);
	SelectID = sceneNext;
	dataTime = 0;
	m_bMusic = true;
	m_bsound = true;
}


/************************************************************************/
/* 读取json数据                                                                     */
/************************************************************************/
Json::Value CCWallData::getJsonFromFile(const char* fileName,const char * path)
{
	Json::Reader reader;  
	const char* pszFullPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativeFile(fileName,path);  

	unsigned long size;
	char *pFileContent = (char*)CCFileUtils::sharedFileUtils()->getFileData(pszFullPath, "rb", &size);  
	std::string jsonfile ;  
	jsonfile.assign(pFileContent, size);
	CCAssert( size > 0, "file is open fail!");  
	Json::Value root;  
	if  (!reader.parse(jsonfile, root, false )) {  
		CCAssert(false, "Json::Reader Parse error!");  
	}
	return root;
}


/************************************************************************/
/* 初始化场景数及场景文件名                                                                     */
/************************************************************************/
void CCWallData::IniScenePath()
{
	Json::Value value = getJsonFromFile(sceneConfigPath,sceneConfigPath);
	if (!value["path"].isNull())
	{
		
		Json::Value arrValue = value["path"];
		sceneConter = arrValue.size();
		for (int i=0; i<sceneConter; i++)
		{
			const char * path = arrValue[i].asCString();
			string s(path);
			strPaths[i] = s;
		}
		
	}

}
/************************************************************************/
/* 根据场景id获取墙体数据                                                                     */
/************************************************************************/
void CCWallData::getWall(int i, list<CCPoint> *Rad,list<CCPoint> *yellow,list<CCPoint> *blue,list<CCPoint> *green)
{

	int arrayInt[48][50];
	const char* c = strPaths[i-1].c_str();
	ExplainWallFromJson(getJsonFromFile(c,c),arrayInt);

	for (int i = 0 ;i<48;i++)
	{
		for (int k=0; k<50 ; k++)
		{
			switch (arrayInt[i][k])
			{
			case 1 :
				Rad->push_back(ccp((k*10)+5,((47-i)*10)+5));
				break;
			case 2:
				yellow->push_back(ccp((k*10)+5,((47-i)*10)+5));
				break;
			case 3:
				blue->push_back(ccp((k*10)+5,((47-i)*10)+5));
				break;
			case 4:
				green->push_back(ccp((k*10)+5,((47-i)*10)+5));
				break;
			case 5: //主角位置
				IniLeadPosition = ccp((k*10)+5,((47-i)*10)+5);
				break;
			default:
				break;
			}

		}
		
	}
	
}
/************************************************************************/

/************************************************************************/
/* 解析json数据获得墙体                                                                     */
/************************************************************************/
void CCWallData::ExplainWallFromJson(Json::Value value,int array[48][50])
{
	
	if (!value["layers"].isNull())
	{
		const Json::Value layersValue = value["layers"];

		for (int i = 0;i<layersValue.size();i++)
		{
			
			const Json::Value arrayData = layersValue[i]["data"];
			for (int k = 0; k<arrayData.size();k++)
			{
				array[k/50][k%50] = arrayData[k].asInt();
			}

		}

	}
}


/************************************************************************/
/* 获取场景数                                                                     */
/************************************************************************/
int CCWallData::getSceneConter()
{
	return sceneConter;
}
/************************************************************************/
/* 获取主角初始化位置                                                                     */
/************************************************************************/
CCPoint CCWallData::getLeadPosition()
{
	return IniLeadPosition;
}


/************************************************************************/
/* 创建数据类                                                                     */
/************************************************************************/
CCWallData* CCWallData::create()
{
	if (m_pWallData == NULL)
	{
		m_pWallData = new CCWallData;
	}
	
	return m_pWallData;
}


/************************************************************************/
/* 设置下一关ID                                                                     */
/************************************************************************/
void CCWallData::setNextID(int i)
{
	sceneNext = i;
}

/************************************************************************/
/* 获取下一关ID                                                                     */
/************************************************************************/
int CCWallData::getNextID()
{
	return sceneNext;
}

/************************************************************************/
/* 设置选择场景ID                                                                     */
/************************************************************************/
void CCWallData::setSelectID(int i)
{
	SelectID = i;
}

/************************************************************************/
/* 获取选择场景ID                                                                     */
/************************************************************************/
int CCWallData::getSelectID()
{
	return SelectID;
}

/************************************************************************/
/* 获取时间*/
/************************************************************************/
int CCWallData::getDataTime()
{
	return dataTime;
}
/************************************************************************/
/* 时间累积                                                                     */
/************************************************************************/
void CCWallData::setDataTime(int i)
{
	dataTime = i;
}