// stdafx.h: archivo de inclusión de los archivos de inclusión estándar del sistema
// o archivos de inclusión específicos de un proyecto utilizados frecuentemente,
// pero rara vez modificados
//

#pragma once

//--------------------------
// WinLicense Protection
//--------------------------
// 0 : Dissabled
// 1 : Enabled
#define WL_PROTECT	0

//--------------------------
// MAC Protection
//--------------------------
// 0 : Dissabled
// 1 : Enabled
#define MAC_PROTECT	0


#pragma warning(disable: 4996 4172 4244 4101)

#define MAX_TYPE_PLAYER 5

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
// Archivos de encabezado de Windows:
#include <windows.h>

// Archivos de encabezado en tiempo de ejecución de C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include <stdio.h>
#include <SQL.h>
#include <sqlext.h>
#include <vector>
#include <map>
#include <time.h>
#include <process.h>
#include "Source/prodef.h"
#include "Source\WinUtil.h"
#include "Source\ReadItems.h"
#include "Resource.h"


#define FILEPATH			"./Config.ini"


#if (WL_PROTECT==1)
#include "Extra\\WinLicenseSDK.h"
#pragma comment (lib,"Extra\\WinlicenseSDK.lib")
#endif

// TODO: mencionar aquí los encabezados adicionales que el programa necesita
