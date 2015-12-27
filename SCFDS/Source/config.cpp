#include "stdafx.h"
#include "config.h"
#include "WinUtil.h"

CONFIGSTRUCT g_Config;

void ConfigReadIniFile()
{
	GetPrivateProfileString("Connection","ServerODBC","MuOnline",g_Config.m_sDbServerAddr,sizeof(g_Config.m_sDbServerAddr),FILEPATH);
	GetPrivateProfileString("Connection","Name","MuOnline",g_Config.m_sDbName,sizeof(g_Config.m_sDbName),FILEPATH);
	GetPrivateProfileString("Connection","Login","sa",g_Config.m_sDbLogin,sizeof(g_Config.m_sDbLogin),FILEPATH);
	GetPrivateProfileString("Connection","Password","654321",g_Config.m_sDbPassword,sizeof(g_Config.m_sDbPassword),FILEPATH);

	g_Config.SkipNonUpdatedPSHOP = GetPrivateProfileInt("Config","SkipNonUpdatedPSHOP",1,FILEPATH);
	g_Config.UseExtendedWarehouse = GetPrivateProfileInt("Config","UseExtendedWarehouse",0,FILEPATH);
	g_Config.ShowLogs = GetPrivateProfileInt("Config","ShowLogs",0,FILEPATH);
	ReadSerialize();
	ReadSearch();
}


void ReadSerialize()
{
	g_Config.ChangeSerials = GetPrivateProfileInt("Serialize","ChangeSerials",0,FILEPATH);
	GetPrivateProfileString("Serialize","ItemFilterPath",".\\ToChange.txt",g_Config.ItemFilterPath,sizeof(g_Config.ItemFilterPath),FILEPATH);
	g_Config.SerialToChange = GetPrivateProfileInt("Serialize","SerialToChange",0,FILEPATH);
}

void ReadSearch()
{
	GetPrivateProfileString("Search","ItemFilterPath",".\\ForSearch.txt",g_Config.ItemNormalPath,sizeof(g_Config.ItemNormalPath),FILEPATH);
	g_Config.SearchSerial = GetPrivateProfileInt("Search","Serial",0,FILEPATH);
}