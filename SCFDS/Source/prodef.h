// ------------------------------
// Decompiled by Deathway
// Date : 2007-03-09
// ------------------------------
#ifndef PRODEF_H
#define PRODEF_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define MAX_CHAT_LEN 60

#define SET_NUMBERH(x) ( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x) ( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x) ( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x) ( (WORD)((DWORD)(x) & 0xFFFF) )

#define MAKE_NUMBERW(x,y)  ( (WORD)(((BYTE)((y)&0xFF)) |   ((BYTE)((x)&0xFF)<<8 ))  )
#define MAKE_NUMBERDW(x,y) ( (DWORD)(((WORD)((y)&0xFFFF)) | ((WORD)((x)&0xFFFF)<<16))  )

/* ------------------------------------------------*
 * ::::::::::::::::::::::::::::::::::::::::::::::::*
 * :::::::::::Packet Head Definitions::::::::::::::*
 * ::::::::::::::::::::::::::::::::::::::::::::::::*
 * ------------------------------------------------*/


// PRIMITIVE HEADS
typedef struct _PHEADB	// Packet Head Byte Normal / Extended [C1:C3]
{
	unsigned char uPacketType;
	unsigned char uSize;
	unsigned char uHead;

} PHEADB, PHEADBE, *LPHEADB, *LPHEADBE; 


typedef struct _PHEADSUBB	// Packet Sub Head Byte [C1:C3]
{
	unsigned char uPacketType;
	unsigned char uSize;
	unsigned char uHead;
	unsigned char uSubHead;

} PHEADSUBB, * LPPHEADSUBB;



typedef struct _PHEADW	// Packet Head Word / Extend [C2:C4]
{
	unsigned char uPacketType;
	unsigned char uSize[2];
	unsigned char uHead;

} PHEADW, * LPPHEADW;


typedef struct _PHEADSUBW	// Packed Sub Head Word [C2:C4]
{
	unsigned char uPacketType;
	unsigned char uSize[2];
	unsigned char uHead;
	unsigned char uSubHead;

} PHEADSUBW, *LPPHEADSUBW;



// ADVANCE DEVIRVATED
struct PBMSG_HEAD	// Packet - Byte Type
{
public:
	void set ( BYTE head, BYTE size)	// line : 18
	{
		this->c			= 0xC1;
		this->size		= size;
		this->headcode	= head;
	};	// line : 22

	void setE ( BYTE head, BYTE size)	// line : 25
	{
		this->c			= 0xC3;
		this->size		= size;
		this->headcode	= head;
	};	// line : 29

	BYTE c;
	BYTE size;
	BYTE headcode;
};




struct PWMSG_HEAD	// Packet - Word Type
{
public:

	void set(BYTE head, int size)
	{
		this->c = 0xC2;
		this->sizeH = SET_NUMBERH(size);
		this->sizeL = SET_NUMBERL(size);
		this->headcode = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	// line : 49
	{
		this->c = 0xC4;
		this->sizeH = SET_NUMBERH(size);
		this->sizeL = SET_NUMBERL(size);
		this->headcode = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};



struct PBMSG_HEAD2	// Packet - Byte Type
{

public:

	void set( LPBYTE lpBuf, BYTE head, BYTE sub, BYTE size)
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
		lpBuf[3] = sub;
	};

	BYTE c;
	BYTE size;
	BYTE headcode;
	BYTE subcode;
};



struct PWMSG_HEAD2
{

public:

	void set(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
		lpBuf[4] = sub;
	}

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
	BYTE subcode;
};



struct REVISION
{
	int Signature;
	int Module;
	int WndTitle;
};


struct PMSG_DEFAULT
{
	PBMSG_HEAD h;
};


struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PMSG_TEST
{
	PWMSG_HEAD h;
	char testbuf[1996];	// 4
	int count;	// 7D0
};


struct SDHP_SERVERINFO
{
	struct PBMSG_HEAD h;
	REVISION Rev;
};



#endif