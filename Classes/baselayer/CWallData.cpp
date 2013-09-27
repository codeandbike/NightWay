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
/* ��ȡjson����                                                                     */
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
/* ��ʼ���������������ļ���                                                                     */
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
/* ���ݳ���id��ȡǽ������                                                                     */
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
			case 5: //����λ��
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
/* ����json���ݻ��ǽ��                                                                     */
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
/* ��ȡ������                                                                     */
/************************************************************************/
int CCWallData::getSceneConter()
{
	return sceneConter;
}
/************************************************************************/
/* ��ȡ���ǳ�ʼ��λ��                                                                     */
/************************************************************************/
CCPoint CCWallData::getLeadPosition()
{
	return IniLeadPosition;
}


/************************************************************************/
/* ����������                                                                     */
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
/* ������һ��ID                                                                     */
/************************************************************************/
void CCWallData::setNextID(int i)
{
	sceneNext = i;
}

/************************************************************************/
/* ��ȡ��һ��ID                                                                     */
/************************************************************************/
int CCWallData::getNextID()
{
	return sceneNext;
}

/************************************************************************/
/* ����ѡ�񳡾�ID                                                                     */
/************************************************************************/
void CCWallData::setSelectID(int i)
{
	SelectID = i;
}

/************************************************************************/
/* ��ȡѡ�񳡾�ID                                                                     */
/************************************************************************/
int CCWallData::getSelectID()
{
	return SelectID;
}

/************************************************************************/
/* ��ȡʱ��*/
/************************************************************************/
int CCWallData::getDataTime()
{
	return dataTime;
}
/************************************************************************/
/* ʱ���ۻ�                                                                     */
/************************************************************************/
void CCWallData::setDataTime(int i)
{
	dataTime = i;
}