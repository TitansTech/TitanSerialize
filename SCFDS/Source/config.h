#ifndef TITANDUPEFINDER_CONFIG_H
#define TITANDUPEFINDER_CONFIG_H

#include <vector>
#include <string>

using namespace std;

typedef struct CONFIGSTRUCT {
	char	m_sDbLogin[20];
	char	m_sDbPassword[20];
	char	m_sDbName[20];
	char	m_sDbServerAddr[30];

	BYTE	UseExtendedWarehouse;
	BYTE	SkipNonUpdatedPSHOP;
	BYTE	ShowLogs;

	BYTE	ChangeSerials;
	DWORD	SerialToChange;
	char	ItemFilterPath[500];

	BYTE	SearchSerial;
	char	ItemNormalPath[500];

} *PCONFIGSTRUCT;

extern CONFIGSTRUCT g_Config;

void ConfigReadIniFile();
void ReadSerialize();
void ReadSearch();

#endif //TITANDUPEFINDER_CONFIG_H