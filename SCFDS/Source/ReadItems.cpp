#include "stdafx.h"
#include "config.h"
#include "winutil.h"
#include "shared.h"
#include "ReadScript.h"
#include "../stdafx.h"
#include "Log.h"

cITEM ItemFilter;
cITEM ItemNormal;

BOOL cITEM::OpenItemScript(char* FileName) // Save Item(kor) Values Into ItemAttribute
{
	int loop_count;
	int n;
	int Token;

	SMDFile = fopen(FileName, "r");

	if ( SMDFile == 0 )
	{
		return FALSE;
	}

	memset ( ItemAttribute, 0, sizeof(ItemAttribute) );
	
	for ( n=0;n<MAX_ITEMS;n++)
	{
		ItemAttribute[n].Level = -1;
		ItemAttribute[n].RepaireMoneyRate  = 0;
		ItemAttribute[n].AllRepaireMoneyRate  = 0;
	}

	
	while ( true )
	{
		Token = GetToken();

		if ( Token == 2 )
		{
			break;
		}
		if ( Token == 1 )
		{
			int ItemType;

			ItemType = TokenNumber;
			loop_count = 0;
			while ( true )
			{
				int ItemSubType;
				LPITEM_ATTRIBUTE p;
				
				Token = GetToken();
				ItemSubType = TokenNumber;

				if ( ItemType >= 0 && ItemType < MAX_TYPE_ITEMS )
				{
					if ( g_MaxItemIndexOfEachItemType[ItemType] <= ItemSubType )
					{
						g_MaxItemIndexOfEachItemType[ItemType] = ItemSubType;
					}
				}

				
				if ( Token == 0 )
				{
					if ( strcmp("end", TokenString ) == 0 )
					{
						break;
					}
				}
					
				p = &ItemAttribute[ItemType*MAX_SUBTYPE_ITEMS + ItemSubType];

				Token = GetToken();
				p->ItemSlot = TokenNumber;

				Token = GetToken();
				p->SkillType = TokenNumber;

				Token = GetToken();
				p->Width  = TokenNumber;

				Token = GetToken();
				p->Height  = TokenNumber;

				Token = GetToken();
				p->Serial = TokenNumber;

				Token = GetToken();
				p->OptionFlag = TokenNumber;

				Token = GetToken();
				p->MondownFlag = TokenNumber;

				Token = GetToken();
				strcpy(&p->Name[0], TokenString );

				if(!strcmp(TokenString,""))
				{
					MsgBox("ERROR: FILE %s (TYPE:%d INDEX:%d)", FileName,ItemType,loop_count);
					exit(1);
				}

				if ( ItemType >= 0 && ItemType <= 5 )
				{
					Token = GetToken();
					p->Level = TokenNumber;

					Token = GetToken();
					p->DamageMin = TokenNumber;

					Token = GetToken();
					p->DamageMax = TokenNumber;

					Token = GetToken();
					p->AttackSpeed = TokenNumber;

					Token = GetToken();
					p->Durability = TokenNumber;

					Token = GetToken();
					p->MagicDurability = TokenNumber;

					Token = GetToken();
					p->MagicPW = TokenNumber;

					Token = GetToken();
					p->RequireLevel = TokenNumber;

					Token = GetToken();
					p->RequireStrength = TokenNumber;

					Token = GetToken();
					p->RequireDexterity = TokenNumber;

					Token = GetToken();
					p->RequireEnergy = TokenNumber;

					Token = GetToken();
					p->RequireVitality = TokenNumber;

					Token = GetToken();
					p->RequireLeadership = TokenNumber;

					if ( p->Width  >= 2)
					{
						p->TwoHand = true; // Review this later
					}

					(BYTE)p->Durability += (BYTE)p->MagicDurability;
				}

				if ( ItemType >= 6 && ItemType <= 11 )
				{
					Token = GetToken();
					p->Level = TokenNumber;
					
					if ( ItemType == 6 )
					{

						Token = GetToken();
						p->Defense = TokenNumber;

						Token = GetToken();
						p->SuccessfulBlocking  = TokenNumber;

					}
					else if ( ItemType >= 7 && ItemType <= 9 )
					{

						Token = GetToken();
						p->Defense  = TokenNumber;

						Token = GetToken();
						p->MagicDefense = TokenNumber;
					}
					else if ( ItemType == 10 )
					{
						Token = GetToken();
						p->Defense = TokenNumber;

						Token = GetToken();
						p->AttackSpeed = TokenNumber;
					}
					else if ( ItemType == 11 )
					{
						Token = GetToken();
						p->Defense  = TokenNumber;

						Token = GetToken();
						p->WalkSpeed = TokenNumber;
					}
					
					Token = GetToken();
					p->Durability = TokenNumber;

					Token = GetToken();
					p->RequireLevel = TokenNumber;

					Token = GetToken();
					p->RequireStrength = TokenNumber;

					Token = GetToken();
					p->RequireDexterity = TokenNumber;

					Token = GetToken();
					p->RequireEnergy = TokenNumber;

					Token = GetToken();
					p->RequireVitality = TokenNumber;

					Token = GetToken();
					p->RequireLeadership = TokenNumber;
				}

				if ( ItemType == 13 )
				{
					Token = GetToken();
					p->Level = TokenNumber;

					Token = GetToken();
					p->Durability = TokenNumber;

					Token = GetToken();
					p->Resistance[0] = TokenNumber;

					Token = GetToken();
					p->Resistance[1] = TokenNumber;

					Token = GetToken();
					p->Resistance[2] = TokenNumber;

					Token = GetToken();
					p->Resistance[3] = TokenNumber;

					Token = GetToken();
					p->Resistance[4] = TokenNumber;

					Token = GetToken();
					p->Resistance[5] = TokenNumber;

					Token = GetToken();
					p->Resistance[6] = TokenNumber;

					p->ResistanceType = -1;
					
					int n;

					for (n=0;n<MAX_ITEM_SPECIAL_ATTRIBUTE-1;n++)
					{
						if ( (p->Resistance[n]) != 0 )
						{
							p->ResistanceType=n;
						}
					}

					p->RequireLevel = p->Level ;
					
				}

				if ( ItemType == 14 )
				{
					Token = GetToken();
					p->Value = TokenNumber;

					Token = GetToken();
					p->Level = TokenNumber;

					p->Durability = 1;
				}

				if ( ItemType == 12 )
				{
					Token = GetToken();
					p->Level = TokenNumber;

					Token = GetToken();
					p->Defense = TokenNumber;

					Token = GetToken();
					p->Durability = TokenNumber;

					Token = GetToken();
					p->RequireLevel = TokenNumber;

					Token = GetToken();
					p->RequireEnergy = TokenNumber;

					Token = GetToken();
					p->RequireStrength = TokenNumber;

					Token = GetToken();
					p->RequireDexterity = TokenNumber;

					Token = GetToken();
					p->RequireLeadership = TokenNumber;

					Token = GetToken();
					p->BuyMoney = TokenNumber;

				}
				
				if ( ItemType == 15 )
				{

					Token = GetToken();
					p->Level = TokenNumber;

					Token = GetToken();
					p->RequireLevel  = TokenNumber;

					Token = GetToken();
					p->RequireEnergy  = TokenNumber;

					Token = GetToken();
					p->BuyMoney  = TokenNumber;

					p->DamageMin = p->Level;
					p->DamageMax = p->Level + p->Level/2; 
				}

				if ( ItemType <= 11 || ItemType == 13)
				{
					Token = GetToken();
				}

				p->SetAttr = TokenNumber;

				if ( ItemType <= 13 || ItemType == 15 )
				{

					Token = GetToken();
					p->RequireClass[CLASS_WIZARD]  = TokenNumber;

					Token = GetToken();
					p->RequireClass[CLASS_KNIGHT]  = TokenNumber;

					Token = GetToken();
					p->RequireClass[CLASS_ELF]  = TokenNumber;

					Token = GetToken();
					p->RequireClass[CLASS_MAGICGLADIATOR]  = TokenNumber;

					Token = GetToken();
					p->RequireClass[CLASS_DARKLORD]  = TokenNumber;

					Token = GetToken();
					p->RequireClass[CLASS_SUMMONER]  = TokenNumber;

					//if(ReadConfig.S6E1 == 1)
					//{
						Token = GetToken();
						p->RequireClass[CLASS_RAGEFIGHTER]  = TokenNumber;
					//}
				}

				p->HaveItemInfo = true;

				loop_count++;

				if ( loop_count > MAX_SUBTYPE_ITEMS )
				{
					MsgBox("Error : Item Data fail. (LoopCount:%d) Item Type:%d Index %d", loop_count, ItemType, ItemSubType);
					break;
				}
			}

			if ( loop_count > MAX_SUBTYPE_ITEMS )
			{
				break;
			}
			
		}
	}
	
	fclose(SMDFile);
	return true;
}

bool cITEM::IsItem(int Type, int Index)
{
	int ItemID = ITEMGET(Type,Index);
	
	if(ItemID > MAX_ITEMS)
		return false;

	if(ItemAttribute[ItemID].HaveItemInfo == false)
		return false;

	return true;
}

bool cITEM::IsItem(int ItemID)
{	
	if(ItemID > MAX_ITEMS)
		return false;

	if(ItemAttribute[ItemID].HaveItemInfo == false)
		return false;

	return true;
}