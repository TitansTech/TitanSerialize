
#pragma once

#define MAX_TYPE_ITEMS 16
#define MAX_SUBTYPE_ITEMS 512

#define MAX_ITEMS (MAX_TYPE_ITEMS*MAX_SUBTYPE_ITEMS)
#define MAX_ITEM_SPECIAL_ATTRIBUTE 7

#define ITEMGET(x,y) ( (x)*MAX_SUBTYPE_ITEMS + (y))

enum ClassNumber {
  CLASS_WIZARD = 0x0,
  CLASS_KNIGHT = 0x1,
  CLASS_ELF = 0x2,
  CLASS_MAGICGLADIATOR = 0x3,
  CLASS_DARKLORD = 0x4,
  CLASS_SUMMONER = 0x5,
  CLASS_RAGEFIGHTER = 0x6,
};

typedef struct
{
	char Name[32]; // 0
	BYTE HaveItemInfo; // 20
	BYTE TwoHand;	// 21
	BYTE Level; // 22
	BYTE Width;	// 23
	BYTE Height;	// 24
	char Serial; // 25
	BYTE OptionFlag; // 26
	BYTE MondownFlag; // 27
	BYTE AttackSpeed; // 28
	BYTE WalkSpeed; // 29
	BYTE DamageMin; // 2A
	BYTE DamageMax; // 2B
	BYTE SuccessfulBlocking; // 2C
	BYTE Defense; // 2D
	BYTE MagicDefense; // 2E
	BYTE Speed;	// 2F
	BYTE Durability; // 30
	BYTE MagicDurability; // 31
	BYTE AttackDur;	// 32
	BYTE DefenceDur; // 33
	WORD RequireStrength; // 34
	WORD RequireDexterity; // 36
	WORD RequireEnergy; // 38
	WORD RequireLevel; // 3A
	WORD Value; // 3C
	BYTE RequireClass[MAX_TYPE_PLAYER]; // 3E
	BYTE Resistance[MAX_ITEM_SPECIAL_ATTRIBUTE]; // unk43 - Ice poisonous lightning non ground wind water
	WORD RequireVitality;	// 4A
	WORD RequireLeadership;	// 68
	int BuyMoney; // 4C
	int MagicPW; // 50
	float RepaireMoneyRate;	// 54
	float AllRepaireMoneyRate; // 58
	bool QuestItem;	// 5C
	BYTE SetAttr; // 5D
	BYTE ResistanceType;	// 5E
	BYTE ItemSlot; // 60
	int SkillType; // 64
	BOOL isSocketItem;
}  ITEM_ATTRIBUTE, * LPITEM_ATTRIBUTE;

class cITEM
{
public:
	BOOL OpenItemScript(char* FileName); // Save Item(kor) Values Into ItemAttribute
	bool IsItem(int Type, int Index);
	bool IsItem(int ItemID);

	ITEM_ATTRIBUTE ItemAttribute[MAX_ITEMS];
	int g_MaxItemIndexOfEachItemType[MAX_TYPE_ITEMS];
};

extern cITEM ItemFilter;
extern cITEM ItemNormal;
