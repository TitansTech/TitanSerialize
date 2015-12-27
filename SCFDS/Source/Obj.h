#ifndef OBJ_H__
#define OBJ_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define OBJMAX 300

struct OBJECTSTRUCT
{
	int m_Index;
	unsigned int m_socket;
	char Ip_addr[16];
	bool Connected;
	//
	REVISION Rev;
};

typedef OBJECTSTRUCT * LPOBJ;
extern OBJECTSTRUCT Obj[OBJMAX];

short ObjAdd(SOCKET aSocket, char* ip, int aIndex);
short ObjDel(int index);
short ObjAddSearch(SOCKET aSocket, char* ip);
void OBJInit();

#endif