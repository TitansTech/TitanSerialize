#include "stdafx.h"
#include "config.h"
#include "winutil.h"
#include "shared.h"
#include "DB/Query.h"
#include "../stdafx.h"
#include "Log.h"

int usercount = 0;
int charcount = 0;
int TotalWares = 0;


CQuery db;
#define INVENTORY_COUNT			3776
#define VAULT_COUNT				3840

#define VAULT_ITEMS				240
#define INV_ITEMS				236


typedef struct _tagItem
{ 
	BYTE	itemtype;
	BYTE	itemoption;
	BYTE	itemdurability;
	//DWORD	itemserial;
	BYTE	itemserial1;
	BYTE	itemserial2;
	BYTE	itemserial3;
	BYTE	itemserial4;

	BYTE	itemexemod;
	BYTE	itemexereserved;
	BYTE	type2;
	BYTE	harmony;
	BYTE	sock1;
	BYTE	sock2;
	BYTE	sock3;
	BYTE	sock4;
	BYTE	sock5;
} ITEM; 

BYTE GetType(ITEM *item)
{
	return (item->type2 >> 4);
}

typedef struct _tagCharacter
{ 
	ITEM	inventory[INV_ITEMS];
	char	name[11];
	char	account[11];
} CHARACTER, *PCHARACTER;

typedef struct _tagAccount
{ 
	ITEM	warehouse[VAULT_ITEMS];
	char	account[11];
	int		ExtWare;
} ACCOUNT, *PACCOUNT;

typedef struct _tagItemArrayElement
{ 
	ITEM	item;
	DWORD	account_index;
	DWORD	character_index;
	DWORD	item_index;
	BOOL	isvault;
	int		ExtWare;
} ITEMARRAYELEMENT, *PITEMARRAYELEMENT;

void InitDB()
{
	//int aa = sizeof(ITEM);
	if ( db.Connect(g_Config.m_sDbServerAddr, g_Config.m_sDbLogin, g_Config.m_sDbPassword) == TRUE )
	{
		LogAddC(4, "[DB] Connection Successfull!");
	}
	else
	{
		LogAddC(2, "[DB] Error On Connection!");
	}
}

DWORD GetSerial(ITEM *item)
{
	WORD ser1 = MAKE_NUMBERW(item->itemserial1,item->itemserial2);
	WORD ser2 = MAKE_NUMBERW(item->itemserial3,item->itemserial4);

	return MAKE_NUMBERDW(ser1,ser2);
}

void SetSerial(ITEM *item, DWORD Serial)
{
	WORD ser1 = SET_NUMBERHW(Serial);
	WORD ser2 = SET_NUMBERLW(Serial);

	BYTE bSer1 = HIBYTE(ser1);
	BYTE bSer2 = LOBYTE(ser1);
	BYTE bSer3 = HIBYTE(ser2);
	BYTE bSer4 = LOBYTE(ser2);

	item->itemserial1 = bSer1;
	item->itemserial2 = bSer2;
	item->itemserial3 = bSer3;
	item->itemserial4 = bSer4;

}

bool IsEmptyItem(ITEM *item,bool Filter)
{
	short m_Type = item->itemtype +  GetType(item) * 512 ;

	if(Filter == true)
	{
		if(ItemFilter.IsItem(m_Type) == false)
			return true;
	}else
	{
		if(ItemNormal.IsItem(m_Type) == false)
			return true;
	}
	
	return false;
}

PACCOUNT paccount;
PCHARACTER pcharacter;
PITEMARRAYELEMENT pitemarray;

DWORD GetNewSerial()
{	
	// ----
	db.ExecQuery("EXEC WZ_GetItemSerial");
	db.Fetch();
	// ----
	DWORD Number				= db.GetResult(0);
	// ----
	db.Close();
	return Number;
}

bool SearchAndChangeSerial(ITEM *item,bool IsVault, int Pos, int Index)
{
	bool isDupe = false;
	char tmp[100]={0};
	short m_Type2 = item->itemtype +  GetType(item) * 512 ;
	BYTE btItemType2=0;
	btItemType2 |= (m_Type2 & 0x1E00 ) >> 5;

	if(!IsEmptyItem(item,true))
	{
		DWORD itemserial1 = GetSerial(item);

		if(((btItemType2+2) == item->itemexereserved))
		{
			//CSHOP
		}else
		{
			if(itemserial1 == g_Config.SerialToChange)
			{			
				DWORD NewSerial = GetNewSerial();				
				
				SetSerial(item,NewSerial);

				if(g_Config.ShowLogs == 1)
				{
					if(IsVault == false)
						LogAddC(2,"[Inventory][%s][%s] Serial [%d] Item [%d][%s][Pos:%d]",pcharacter[Index].account,pcharacter[Index].name, NewSerial,m_Type2,ItemFilter.ItemAttribute[m_Type2].Name,Pos);
					else
						LogAddC(2,"[Vault][%d][%s] Serial [%d] Item [%d][%s][Pos:%d]",paccount[Index].ExtWare,paccount[Index].account, NewSerial,m_Type2,ItemFilter.ItemAttribute[m_Type2].Name,Pos);
				}
				return true;
			}
		}
	}
	return false;
}

void Serialize()
{
	ReadSerialize();
	unsigned int ConvertedItemsCnt=0;

	for(int user=0;user<usercount;user++)
	{
		bool Changed = false;
		for(int item=0;item<VAULT_ITEMS;item++) 
		{
			if(!IsEmptyItem(&paccount[user].warehouse[item],true))
			{
				bool bFlag = false;
				bFlag = SearchAndChangeSerial(&paccount[user].warehouse[item],true,item,user);
				if(bFlag == true)
				{
					ConvertedItemsCnt++;
					if(Changed == false)
						Changed = bFlag;
				}
			}
		}
		if(Changed == true)
		{
			if(g_Config.ChangeSerials == 1)
			{
				char szTemp[10000]={0};
				BYTE dbWarehouse[VAULT_COUNT]	= {0};
				
				memcpy(dbWarehouse, paccount[user].warehouse, sizeof(paccount[user].warehouse));
				
				wsprintf(szTemp, "UPDATE warehouse SET Items=? WHERE AccountID = '%s'", paccount[user].account);
				db.SetAsBinary(szTemp, dbWarehouse, sizeof(dbWarehouse));
				db.Fetch();
				db.Close();
			}
		}
	}

	if(g_Config.UseExtendedWarehouse == 1)
	{
		for(int user=usercount;user<TotalWares;user++)
		{
			bool Changed = false;
			for(int item=0;item<VAULT_ITEMS;item++) 
			{
				if(!IsEmptyItem(&paccount[user].warehouse[item],true))
				{
					bool bFlag = false;
					bFlag = SearchAndChangeSerial(&paccount[user].warehouse[item],true,item,user);
					if(bFlag == true)
					{
						ConvertedItemsCnt++;
						if(Changed == false)
							Changed = bFlag;
					}
				}
			}
			if(Changed == true)
			{
				if(g_Config.ChangeSerials == 1)
				{
					char szTemp[10000]={0};
					BYTE dbWarehouse[VAULT_COUNT]	= {0};
					
					memcpy(dbWarehouse, paccount[user].warehouse, sizeof(paccount[user].warehouse));
					
					wsprintf(szTemp, "UPDATE ExtendedWarehouse SET Items=? WHERE AccountID = '%s' AND SCFExtWare=%d", paccount[user].account,paccount[user].ExtWare);
					db.SetAsBinary(szTemp, dbWarehouse, sizeof(dbWarehouse));
					db.Fetch();
					db.Close();
				}
			}
		}
	}

	for(int character=0;character<charcount;character++)
	{
		bool Changed = false;
		for(int item=0;item<INV_ITEMS;item++) 
		{
			if(!IsEmptyItem(&pcharacter[character].inventory[item],true))
			{
				bool bFlag = false;
				bFlag = SearchAndChangeSerial(&pcharacter[character].inventory[item],false,item,character);
				if(bFlag == true)
				{
					ConvertedItemsCnt++;
					if(Changed == false)
						Changed = bFlag;
				}
			}
		}
		if(Changed == true)
		{
			if(g_Config.ChangeSerials == 1)
			{
				char szTemp[10000]={0};
				BYTE dbInventory[INVENTORY_COUNT]	= {0};
				memcpy(dbInventory, pcharacter[character].inventory, sizeof(pcharacter[character].inventory));

				wsprintf(szTemp, "UPDATE character SET Inventory=? WHERE Name = '%s' AND AccountID = '%s'", pcharacter[character].name, pcharacter[character].account);
				db.SetAsBinary(szTemp, dbInventory, sizeof(dbInventory));
				db.Fetch();
				db.Close();
			}
		}
	}
	LogAddC(3,"Converted serials: %d",ConvertedItemsCnt);

	LogAddTD("Serialize finished...");
}

bool SearchSerial(ITEM *item,bool IsVault, int Pos, int Index)
{
	bool isDupe = false;
	char tmp[100]={0};
	short m_Type2 = item->itemtype +  GetType(item) * 512 ;
	BYTE btItemType2=0;
	btItemType2 |= (m_Type2 & 0x1E00 ) >> 5;

	if(!IsEmptyItem(item,false))
	{
		DWORD itemserial1 = GetSerial(item);

		if(((btItemType2+2) == item->itemexereserved))
		{
			//CSHOP
		}else
		{
			if(itemserial1 == g_Config.SerialToChange)
			{		
				if(IsVault == false)
					LogAddC(3,"[Inventory][%s][%s] Serial [%d] Item [%d][%s][Pos:%d]",pcharacter[Index].account,pcharacter[Index].name, itemserial1,m_Type2,ItemFilter.ItemAttribute[m_Type2].Name,Pos);
				else
					LogAddC(3,"[Vault][%d][%s] Serial [%d] Item [%d][%s][Pos:%d]",paccount[Index].ExtWare,paccount[Index].account, itemserial1,m_Type2,ItemFilter.ItemAttribute[m_Type2].Name,Pos);
				return true;
			}
		}
	}
	return false;
}


void Search()
{
	ReadSearch();
	unsigned int FindedItemsCnt=0;
	bool Finded = false;

	for(int user=0;user<usercount;user++)
	{
		for(int item=0;item<VAULT_ITEMS;item++) 
		{
			Finded = false;
			if(!IsEmptyItem(&paccount[user].warehouse[item],false))
			{
				Finded = SearchSerial(&paccount[user].warehouse[item],true,item,user);
				if(Finded ==  true)
					FindedItemsCnt++;
			}
		}
	}

	if(g_Config.UseExtendedWarehouse == 1)
	{
		for(int user=usercount;user<TotalWares;user++)
		{
			for(int item=0;item<VAULT_ITEMS;item++) 
			{
				Finded = false;
				if(!IsEmptyItem(&paccount[user].warehouse[item],false))
				{
					Finded = SearchSerial(&paccount[user].warehouse[item],true,item,user);
					if(Finded ==  true)
						FindedItemsCnt++;
				}
			}
		}
	}

	for(int character=0;character<charcount;character++)
	{
		for(int item=0;item<INV_ITEMS;item++) 
		{
			Finded = false;
			if(!IsEmptyItem(&pcharacter[character].inventory[item],false))
			{
				Finded = SearchSerial(&pcharacter[character].inventory[item],false,item,character);
				if(Finded ==  true)
					FindedItemsCnt++;
			}
		}
	}

	LogAddC(3,"Item with serial:%d Count: %d",g_Config.SearchSerial,FindedItemsCnt);

	LogAddTD("Search finished...");
}

void Start()
{
	int extwarecount = 0;
	usercount = 0;
	charcount = 0;
	TotalWares = 0;

	BOOL bRet = FALSE;
	LogAddC(3,"Starting search...");
	LogAddTD("Getting Character Count...");

	if(g_Config.SkipNonUpdatedPSHOP == 0)
		bRet = db.ExecQuery("select count(*) as charcount from character");
	else
		bRet = db.ExecQuery("select count(*) as charcount from character WHERE SCFUpdatedPShop = 1");

	if (bRet == TRUE )
	{
		if(db.Fetch() != SQL_NO_DATA)
		{
			charcount = db.GetAsInteger("charcount");
		}
	}
	db.Close();

	LogAddTD("Character Count: %d !!",charcount);

	pcharacter = new CHARACTER [charcount];
	memset(pcharacter, 0x00, sizeof(CHARACTER)*charcount);

	LogAddTD("Getting Inventories...");
	if(g_Config.SkipNonUpdatedPSHOP == 0)
		bRet = db.ExecQuery("select AccountID, Name from character");
	else
		bRet = db.ExecQuery("select AccountID, Name from character WHERE SCFUpdatedPShop = 1");

	if (bRet == TRUE )
	{
		int i=0;
		if( db.Fetch() != SQL_NO_DATA)
		{
			do
			{
				db.GetAsString("AccountID", pcharacter[i].account);
				db.GetAsString("Name", pcharacter[i].name);
				i++;
				if(i>=charcount)
					break;
			}while(db.Fetch() != SQL_NO_DATA);
		}
	}
	db.Close();

	for(int i=0;i<charcount;i++)
	{
		char szTemp[1024]={0};
		BYTE InvTmp[INVENTORY_COUNT]={0};
		wsprintf(szTemp, "select Inventory from character WHERE Name='%s'", pcharacter[i].name);
		db.GetAsBinary(szTemp, InvTmp);
		memcpy(pcharacter[i].inventory,InvTmp,sizeof(pcharacter[i].inventory));
		db.Close();
	}
	LogAddTD("Inventories Loaded!!");
	
	LogAddTD("Getting Warehouse Count...");
	bRet = db.ExecQuery("select count(*) as usercount from warehouse");
	if (bRet == TRUE )
	{
		if(db.Fetch() != SQL_NO_DATA)
		{
			usercount = db.GetAsInteger("usercount");
		}
	}
	db.Close();
	LogAddTD("Warehouse Count: %d !!",usercount);
	
	TotalWares = usercount;

	if(g_Config.UseExtendedWarehouse == 1)
	{
		LogAddTD("Getting ExtendedWarehouse Count...");
		bRet = db.ExecQuery("select count(*) as extcount from ExtendedWarehouse");
		if (bRet == TRUE )
		{
			if(db.Fetch() != SQL_NO_DATA)
			{
				extwarecount = db.GetAsInteger("extcount");
			}
		}
		db.Close();
		LogAddTD("ExtendedWarehouse Count: %d !!",extwarecount);
		

		TotalWares += extwarecount;
	}

	paccount = new ACCOUNT [usercount+extwarecount];
	memset(paccount, 0x00, sizeof(ACCOUNT)*usercount);
	
	bRet = db.ExecQuery("select AccountID from warehouse");
	if (bRet == TRUE )
	{
		int i=0;
		if( db.Fetch() != SQL_NO_DATA)
		{
			do
			{
				db.GetAsString("AccountID", paccount[i].account);
				i++;
				if(i>=usercount)
					break;
			}while(db.Fetch() != SQL_NO_DATA);
		}
	}
	db.Close();
	
	if(g_Config.UseExtendedWarehouse == 1)
	{
		bRet = db.ExecQuery("select AccountID,SCFExtWare from ExtendedWarehouse");
		if (bRet == TRUE )
		{
			int i=usercount;
			if( db.Fetch() != SQL_NO_DATA)
			{
				do
				{
					db.GetAsString("AccountID", paccount[i].account);
					paccount[i].ExtWare = db.GetAsInteger("SCFExtWare");
					i++;
					if(i>=TotalWares)
						break;
				}while(db.Fetch() != SQL_NO_DATA);
			}
		}
		db.Close();
	}

	for(int i=0;i<usercount;i++)
	{
		char szTemp[1024]={0};
		BYTE InvTmp[VAULT_COUNT]={0};
		wsprintf(szTemp, "select Items from warehouse WHERE AccountID='%s'", paccount[i].account);
		db.GetAsBinary(szTemp, InvTmp);
		memcpy(paccount[i].warehouse,InvTmp,sizeof(paccount[i].warehouse));
		db.Close();
	}
	LogAddTD("Warehouses Loaded!!");

	if(g_Config.UseExtendedWarehouse == 1)
	{
		for(int i=usercount;i<TotalWares;i++)
		{
			char szTemp[1024]={0};
			BYTE InvTmp[VAULT_COUNT]={0};
			wsprintf(szTemp, "select Items from ExtendedWarehouse WHERE AccountID='%s' AND SCFExtWare=%d", paccount[i].account,paccount[i].ExtWare);
			db.GetAsBinary(szTemp, InvTmp);
			memcpy(paccount[i].warehouse,InvTmp,sizeof(paccount[i].warehouse));
			db.Close();
		}
		LogAddTD("ExtendedWarehouse Loaded!!");
	}
	LogAddC(3,"Ready...");
}