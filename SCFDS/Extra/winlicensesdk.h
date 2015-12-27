#ifndef __WINLICENSDK__
#define __WINLICENSDK__


// ***********************************************
// WinLicense constants definition
// ***********************************************

const int wlNoTrialExt             		= 0;
const int wlAppExtended            		= 1;
const int wlInvalidTrialExt        		= 2;
const int wlNoMoreExt              		= 3;
const int wlTrialOk                		= 0;
const int wlTrialDaysExpired       		= 1;
const int wlTrialExecExpired      		= 2;
const int wlTrialDateExpired       		= 3;
const int wlTrialRuntimExpired     		= 4;
const int wlTrialGlobalExpired     		= 5;
const int wlTrialInvalidCountry    		= 6;
const int wlTrialManipulated    		= 7;
const int wlMarkStolenKey          		= 0;
const int wlMarkInvalidKey        		= 1;
const int wlLicenseDaysExpired    		= 1;
const int wlLicenseExecExpired     		= 2;
const int wlLicenseDateExpired     		= 3;
const int wlLicenseGlobalExpired   		= 4;
const int wlLicenseRuntimeExpired  		= 5;
const int wlLicenseActivationExpired  	= 6;
const int wlIsTrial                		= 0;
const int wlIsRegistered           		= 1;
const int wlInvalidLicense         		= 2;
const int wlInvalidHardwareLicense 		= 3;
const int wlNoMoreHwdChanges       		= 4;
const int wlLicenseExpired         		= 5;
const int wlInvalidCountryLicense  		= 6;
const int wlLicenseStolen          		= 7;
const int wlWrongLicenseExp        		= 8;
const int wlWrongLicenseHardware   		= 9;
const int wlIsRegisteredNotActivared 	= 10;
const int wlIsRegisteredAndActivated 	= wlIsRegistered;
const int wlNoMoreInstancesAllowed 		= 12;
const int wlNetworkNoServerRunning 		= 13;
const int wlInstallLicenseDateExpired	= 14;
const int wlLicenseDisabledInstance		= 15;

const int wlPermKey                		= -1;
const int wlNoKey                  		= -2;
const int wlNoTrialDate            		= -1;
const int wlInvalidCounter         		= -1;


// License restrictions 

const int wlRegRestrictionDays          = 1 << 0;
const int wlRegRestrictionExec          = 1 << 1;
const int wlRegRestrictionDate          = 1 << 2;
const int wlRegRestrictionRuntime       = 1 << 3;
const int wlRegRestrictionGlobalTime    = 1 << 4;
const int wlRegRestrictionCountry       = 1 << 5;
const int wlRegRestrictionHardwareId    = 1 << 6;
const int wlRegRestrictionNetwork       = 1 << 7;
const int wlRegRestrictionInstallDate   = 1 << 8;
const int wlRegRestrictionCreationDate  = 1 << 9;
const int wlRegRestrictionEmbedUserInfo = 1 << 10;



// ***********************************************
// WinLicense typedef definition
// ***********************************************

typedef struct _sLicenseFeatures 
{ 
	unsigned	cb;						// size of struct
	unsigned 	NumDays;				// expiration days
	unsigned	NumExec;				// expiration executions
	SYSTEMTIME  ExpDate;				// expiration date 
	unsigned	CountryId;				// country ID
	unsigned	Runtime;				// expiration runtime
	unsigned	GlobalMinutes;  		// global time expiration
	SYSTEMTIME	InstallDate;			// Date to install the license since it was created
	unsigned	NetInstances;			// Network instances via shared file
	unsigned	EmbedLicenseInfoInKey;	// for Dynamic SmartKeys, it embeds Name+Company+Custom inside generated SmartKey
	unsigned    EmbedCreationDate;  	// Embed the date that the key was created
} sLicenseFeatures;


// ***********************************************
// WinLicense functions prototype
// ***********************************************

 #ifdef __BORLANDC__

 extern "C" _stdcall __declspec(dllimport) int WLGenTrialExtensionFileKey(char* TrialHash, int Level,\
                                                int NumDays, int NumExec, SYSTEMTIME* NewDate, int NumMinutes,\
                                                int TimeRuntime, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenTrialExtensionRegistryKey(char* TrialHash, int Level,\
                                                int NumDays, int NumExec, SYSTEMTIME* NewDate, int NumMinutes,\
                                                int TimeRuntime, char* pKeyName, char* pKeyValueName, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenPassword(char* TrialHash, char* Name, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseFileKey(char* LicenseHash, char* UserName, char* Organization,\
                                                char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseFileKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseFileKeyEx(const char* LicenseHash, const char* UserName, const char* Organization,\
                                                const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseFileKeyExW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseRegistryKey(char* LicenseHash, char* UserName, char* Organization,\
                                                char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, char* KeyName, char* KeyValueName, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseRegistryKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, const wchar_t* KeyName, const wchar_t* KeyValueName, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseRegistryKeyEx(char* LicenseHash, char* UserName, char* Organization,\
                                                char* CustomData, char* MachineID, sLicenseFeatures* LicenseFeatures, char* KeyName, char* KeyValueName, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseRegistryKeyExW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, 
                                                const wchar_t* KeyName, const wchar_t* KeyValueName, wchar_t* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseTextKey(char* LicenseHash, char* UserName, char* Organization,\
                                                char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseTextKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, wchar_t* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseTextKeyEx(const char* LicenseHash, const char* UserName, const char* Organization,\
                                                const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseTextKeyExW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, wchar_t* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseSmartKey(char* LicenseHash, char* UserName, char* Organization,\
                                                char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseSmartKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                wchar_t* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseDynSmartKey(const char* LicenseHash, const char* UserName, const char* Organization,\
                                                const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLGenLicenseDynSmartKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, wchar_t* BufferOut);

 extern "C" _stdcall __declspec(dllimport) int WLTrialGetStatus(int* pExtendedInfo);

 extern "C" _stdcall __declspec(dllimport) int WLTrialExtGetStatus(void);
 
 extern "C" _stdcall __declspec(dllimport) int WLRegGetStatus(int* pExtendedInfo);

 extern "C" _stdcall __declspec(dllimport) bool WLRegGetLicenseInfo(char* pName, char* pCompanyName, char* pCustomData);

 extern "C" _stdcall __declspec(dllimport) bool WLRegGetLicenseInfoW(wchar_t* pName, wchar_t* pCompanyName, wchar_t* pCustomData);

 extern "C" _stdcall __declspec(dllimport) int WLTrialTotalDays(void);
 
 extern "C" _stdcall __declspec(dllimport) int WLTrialTotalExecutions(void);

 extern "C" _stdcall __declspec(dllimport) int WLTrialDaysLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLTrialExecutionsLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLTrialExpirationDate(SYSTEMTIME* pExpDate);

 extern "C" _stdcall __declspec(dllimport) int WLTrialGlobalTimeLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLTrialRuntimeLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLTrialLockedCountry(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegDaysLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegExecutionsLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegExpirationDate(SYSTEMTIME* pExpDate);

 extern "C" _stdcall __declspec(dllimport) bool WLRegLicenseCreationDate(SYSTEMTIME* pCreationDate);

 extern "C" _stdcall __declspec(dllimport) int WLRegTotalExecutions(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegTotalDays(void);

 extern "C" _stdcall __declspec(dllimport) bool WLHardwareGetID(char* pHardwareId);

 extern "C" _stdcall __declspec(dllimport) bool WLHardwareCheckID(char* pHardwareId);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyCheck(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyCheckW(const wchar_t* UserName, const wchar_t* Organization, const wchar_t* Custom, const wchar_t* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegNormalKeyCheck(const char* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegNormalKeyCheckW(const wchar_t* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegNormalKeyInstallToFile(const char* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegNormalKeyInstallToFileW(const wchar_t* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegNormalKeyInstallToRegistry(const char* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegNormalKeyInstallToRegistryW(const wchar_t* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyInstallToFile(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyInstallToFileW(const wchar_t* UserName, const wchar_t* Organization, const wchar_t* Custom, const wchar_t* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyInstallToRegistry(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyInstallToRegistryW(const wchar_t* UserName, const wchar_t* Organization, const wchar_t* Custom, const wchar_t* AsciiKey);
 
 extern "C" _stdcall __declspec(dllimport) int WLTrialCustomCounterInc(int Value, int CounterId);

 extern "C" _stdcall __declspec(dllimport) int WLTrialCustomCounterDec(int Value, int CounterId);

 extern "C" _stdcall __declspec(dllimport) int WLTrialCustomCounter(int CounterId);

 extern "C" _stdcall __declspec(dllimport) int WLTrialCustomCounterSet(int Value, int CounterId);

 extern "C" _stdcall __declspec(dllimport) bool WLRestartApplication(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegLockedCountry(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegRuntimeLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegGlobalTimeLeft(void);

 extern "C" _stdcall __declspec(dllimport) bool WLRegDisableCurrentKey(int DisableFlags);

 extern "C" _stdcall __declspec(dllimport) bool WLRegRemoveCurrentKey(void);
 
 extern "C" _stdcall __declspec(dllimport) bool WLHardwareGetFormattedID(int BlockCharSize, int Uppercase, char* Buffer);
 
 extern "C" _stdcall __declspec(dllimport) bool WLPasswordCheck(char* UserName, char* Password);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialExpireTrial(void);

 extern "C" _stdcall __declspec(dllimport) LPSTR WLStringDecrypt(char* pString);

 extern "C" _stdcall __declspec(dllimport) LPWSTR WLStringDecryptW(wchar_t* pString);

 extern "C" _stdcall __declspec(dllimport) void WLRegLicenseName(char* FileKeyName, char* RegKeyName, char* RegKeyValueName);

 extern "C" _stdcall __declspec(dllimport) bool WLRestartApplicationArgs(char* pArgs);

 extern "C" _stdcall __declspec(dllimport) bool WLActGetInfo(int* Custom1, int* Custom2, int* Custom3);

 extern "C" _stdcall __declspec(dllimport) bool WLActCheck(char* ActivationCode);

 extern "C" _stdcall __declspec(dllimport) bool WLActInstall(char* ActivationCode);

 extern "C" _stdcall __declspec(dllimport) bool WLActExpirationDate(SYSTEMTIME* pExpDate);

 extern "C" _stdcall __declspec(dllimport) int WLActDaysToActivate(void);

 extern "C" _stdcall __declspec(dllimport) bool WLActUninstall(void);

// (CURRENTLY DISABLED) extern "C" _stdcall __declspec(dllimport) bool WLRegGetLicenseHardwareID(char* pHardwareId);

 extern "C" _stdcall __declspec(dllimport) int WLGetCurrentCountry(void);

 extern "C" _stdcall __declspec(dllimport) int WLTrialExtGetLevel(void);

 extern "C" _stdcall __declspec(dllimport) bool WLProtectCheckDebugger(void);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialExtendExpiration(int NumDays, int NumExec, SYSTEMTIME* NewDate,
                                                int Runtime, int GlobalMinutes);
  
 extern "C" _stdcall __declspec(dllimport) bool WLTrialFirstRun(void);

 extern "C" _stdcall __declspec(dllimport) bool WLRegFirstRun(void);
 
 extern "C" _stdcall __declspec(dllimport) bool WLRegCheckMachineLocked(void);

 extern "C" _stdcall __declspec(dllimport) void WLSplashHide(void);

 extern "C" _stdcall __declspec(dllimport) void WLBufferCrypt(void* Buffer, int BufferLength, char* Password);

 extern "C" _stdcall __declspec(dllimport) void WLBufferDecrypt(void* Buffer, int BufferLength, char* Password);

 extern "C" _stdcall __declspec(dllimport) bool WLRegSmartKeyInstallToFileInFolder(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey, const char* FilePath);

 extern "C" _stdcall __declspec(dllimport) int WLTrialDateDaysLeft(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegDateDaysLeft(void);

 extern "C" _stdcall __declspec(dllimport) void WLResetLicenseFeatures(sLicenseFeatures *LicenseFeatures, int SizeStructure);

 extern "C" _stdcall __declspec(dllimport) bool WLRegGetDynSmartKey(char* SmartKey);

 extern "C" _stdcall __declspec(dllimport) bool WLRegDisableKeyCurrentInstance(void);

 extern "C" _stdcall __declspec(dllimport) bool WLHardwareRuntimeCheckU3(void);

 extern "C" _stdcall __declspec(dllimport) void WLGetVersion(char* Buffer);

 extern "C" _stdcall __declspec(dllimport) int WLRegNetInstancesGet(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegNetInstancesMax(void);

 extern "C" _stdcall __declspec(dllimport) void WLGetProtectionDate(SYSTEMTIME* pProtectionDate);

 extern "C" _stdcall __declspec(dllimport) bool WLProtectCheckMem(void);

 extern "C" _stdcall __declspec(dllimport) int WLHardwareGetIdType(void);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialStringRead(const char *StringName, char *StringValue);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialStringReadW(const wchar_t *StringName, wchar_t *StringValue);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialStringWrite(const char *StringName, const char *StringValue);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialStringWriteW(const wchar_t *StringName, const wchar_t *StringValue);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialDebugCheck(void);

 extern "C" _stdcall __declspec(dllimport) bool WLRegExpirationTimestamp(LPFILETIME lpFileTime);

 extern "C" _stdcall __declspec(dllimport) bool WLTrialExpirationTimestamp(LPFILETIME lpFileTime);

 extern "C" _stdcall __declspec(dllimport) int WLRegGetLicenseRestrictions(void);

 extern "C" _stdcall __declspec(dllimport) int WLRegGetLicenseType(void);

 extern "C" _stdcall __declspec(dllimport) bool WLCheckVirtualPC(void);

 extern "C" _stdcall __declspec(dllimport) bool WLHardwareGetIDW(wchar_t * pHardwareId);

  
 #else

 extern "C" int _stdcall GenerateTrialExtensionKey(char* TrialHash, int Level, int NumDays, int NumExec,\
                                                SYSTEMTIME* NewDate, int NumMinutes, int TimeRuntime,\
                                                char* BufferOut);

 extern "C" int _stdcall WLGenTrialExtensionFileKey(char* TrialHash, int Level,\
                                            int NumDays, int NumExec, SYSTEMTIME* NewDate, int NumMinutes,\
                                            int TimeRuntime, char* BufferOut);

 extern "C" int _stdcall WLGenTrialExtensionRegistryKey(char* TrialHash, int Level,\
                          int NumDays, int NumExec, SYSTEMTIME* NewDate, int NumMinutes,\
                          int TimeRuntime, char* pKeyName, char* pKeyValueName, char* BufferOut);

 extern "C" int _stdcall WLGenPassword(char* TrialHash, char* Name, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseFileKey(char* LicenseHash, char* UserName, char* Organization,\
                          char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          int CountryId, int Runtime, int GlobalMinutes, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseFileKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                          const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          int CountryId, int Runtime, int GlobalMinutes, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseFileKeyEx(const char* LicenseHash, const char* UserName, const char* Organization,\
                                               const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseFileKeyExW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseRegistryKey(char* LicenseHash, char* UserName, char* Organization,\
                          char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          int CountryId, int Runtime, int GlobalMinutes, char* KeyName, char* KeyValueName, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseRegistryKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                                                int CountryId, int Runtime, int GlobalMinutes, const wchar_t* KeyName, const wchar_t* KeyValueName, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseRegistryKeyEx(const char* LicenseHash, const char* UserName, const char* Organization,\
                          const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* KeyName, char* KeyValueName, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseRegistryKeyExW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                          const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, const wchar_t* KeyName, const wchar_t* KeyValueName, wchar_t* BufferOut);

 extern "C" int _stdcall WLGenLicenseTextKey(char* LicenseHash, char* UserName, char* Organization,\
                          char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          int CountryId, int Runtime, int GlobalMinutes, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseTextKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                          const wchar_t* CustomData, const wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          int CountryId, int Runtime, int GlobalMinutes, wchar_t* BufferOut);

 extern "C" int _stdcall WLGenLicenseTextKeyEx(const char* LicenseHash, const char* UserName, const char* Organization,\
                          const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseTextKeyExW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                          const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, wchar_t* BufferOut);

 extern "C" int _stdcall WLGenLicenseSmartKey(char* LicenseHash, char* UserName, char* Organization,\
                          char* CustomData, char* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          char* BufferOut);

 extern "C" int _stdcall WLGenLicenseSmartKeyW(wchar_t* LicenseHash, wchar_t* UserName, wchar_t* Organization,\
                          wchar_t* CustomData, wchar_t* MachineID, int NumDays, int NumExec, SYSTEMTIME* NewDate, \
                          wchar_t* BufferOut);

 extern "C" int _stdcall WLGenLicenseDynSmartKey(const char* LicenseHash, const char* UserName, const char* Organization,\
                                                const char* CustomData, const char* MachineID, sLicenseFeatures* LicenseFeatures, char* BufferOut);

 extern "C" int _stdcall WLGenLicenseDynSmartKeyW(const wchar_t* LicenseHash, const wchar_t* UserName, const wchar_t* Organization,\
                                                const wchar_t* CustomData, const wchar_t* MachineID, sLicenseFeatures* LicenseFeatures, wchar_t* BufferOut);

 extern "C" int _stdcall WLRegGetStatus(int* pExtendedInfo);

 extern "C" int _stdcall WLTrialGetStatus(int* pExtendedInfo);

 extern "C" int _stdcall WLTrialExtGetStatus(void);
 
 extern "C" bool _stdcall WLRegGetLicenseInfo(char* pName, char* pCompanyName, char* pCustomData);

 extern "C" bool _stdcall WLRegGetLicenseInfoW(wchar_t* pName, wchar_t* pCompanyName, wchar_t* pCustomData);

 extern "C" int _stdcall WLTrialTotalDays(void);
 
 extern "C" int _stdcall WLTrialTotalExecutions(void);

 extern "C" int _stdcall WLTrialDaysLeft(void);

 extern "C" int _stdcall WLTrialExecutionsLeft(void);

 extern "C" int _stdcall WLTrialExpirationDate(SYSTEMTIME* pExpDate);

 extern "C" int _stdcall WLTrialGlobalTimeLeft(void);

 extern "C" int _stdcall WLTrialRuntimeLeft(void);

 extern "C" int _stdcall WLTrialLockedCountry(void);

 extern "C" int _stdcall WLRegDaysLeft(void);

 extern "C" int _stdcall WLRegExecutionsLeft(void);

 extern "C" int _stdcall WLRegExpirationDate(SYSTEMTIME* pExpDate);

 extern "C" bool _stdcall WLRegLicenseCreationDate(SYSTEMTIME* pCreationDate);
 
 extern "C" int _stdcall WLRegTotalExecutions(void);

 extern "C" int _stdcall WLRegTotalDays(void);

 extern "C" bool _stdcall WLHardwareGetID(char* pHardwareId);

 extern "C" bool _stdcall WLHardwareCheckID(char* pHardwareId);

 extern "C" bool _stdcall WLRegSmartKeyCheck(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey);

 extern "C" bool _stdcall WLRegSmartKeyCheckW(const wchar_t* UserName, const wchar_t* Organization, const wchar_t* Custom, const wchar_t* AsciiKey);

 extern "C" bool _stdcall WLRegNormalKeyCheck(const char* AsciiKey);

 extern "C" bool _stdcall WLRegNormalKeyCheckW(const wchar_t* AsciiKey);

 extern "C" bool _stdcall WLRegNormalKeyInstallToFile(const char* AsciiKey);

 extern "C" bool _stdcall WLRegNormalKeyInstallToFileW(const wchar_t* AsciiKey);

 extern "C" bool _stdcall WLRegNormalKeyInstallToRegistry(const char* AsciiKey);

 extern "C" bool _stdcall WLRegNormalKeyInstallToRegistryW(const wchar_t* AsciiKey);

 extern "C" bool _stdcall WLRegSmartKeyInstallToFile(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey);

 extern "C" bool _stdcall WLRegSmartKeyInstallToRegistry(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey);

 extern "C" bool _stdcall WLRegSmartKeyInstallToFileW(const wchar_t* UserName, const wchar_t* Organization, const wchar_t* Custom, const wchar_t* AsciiKey);
 
 extern "C" bool _stdcall WLRegSmartKeyInstallToRegistryW(const wchar_t* UserName, const wchar_t* Organization, const wchar_t* Custom, const wchar_t* AsciiKey);

 extern "C" int _stdcall WLTrialCustomCounterInc(int Value, int CounterId);

 extern "C" int _stdcall WLTrialCustomCounterDec(int Value, int CounterId);

 extern "C" int _stdcall WLTrialCustomCounter(int CounterId);

 extern "C" int _stdcall WLTrialCustomCounterSet(int Value, int CounterId);

 extern "C" bool _stdcall WLRestartApplication(void);

 extern "C" int _stdcall WLRegLockedCountry(void);

 extern "C" int _stdcall WLRegRuntimeLeft(void);

 extern "C" int _stdcall WLRegGlobalTimeLeft(void);

 extern "C" bool _stdcall WLRegDisableCurrentKey(int DisableFlags);

 extern "C" bool _stdcall WLRegRemoveCurrentKey(void);
 
 extern "C" bool _stdcall WLHardwareGetFormattedID(int BlockCharSize, int Uppercase, char* Buffer);
 
 extern "C" bool _stdcall WLPasswordCheck(char* UserName, char* Password);

 extern "C" bool _stdcall WLTrialExpireTrial(void);

 extern "C" char* _stdcall WLStringDecrypt(char* pString);

 extern "C" wchar_t* _stdcall WLStringDecryptW(wchar_t* pString);

 extern "C" void _stdcall WLRegLicenseName(char* FileKeyName, char* RegKeyName, char* RegKeyValueName);

 extern "C" bool _stdcall WLRestartApplicationArgs(char* pArgs);

 extern "C" bool _stdcall WLActGetInfo(int* Custom1, int* Custom2, int* Custom3);

 extern "C" bool _stdcall WLActCheck(char* ActivationCode);

 extern "C"  bool _stdcall WLActInstall(char* ActivationCode);

 extern "C"  bool _stdcall WLActExpirationDate(SYSTEMTIME* pExpDate);

 extern "C" int _stdcall WLActDaysToActivate(void);

 extern "C" bool _stdcall WLActUninstall(void);

// (CURRENTLY DISABLED) extern "C" bool _stdcall WLRegGetLicenseHardwareID(char* pHardwareId);

 extern "C" int _stdcall WLGetCurrentCountry(void);

 extern "C" int _stdcall WLTrialExtGetLevel(void);

 extern "C" bool _stdcall WLProtectCheckDebugger(void);

 extern "C" bool _stdcall  WLTrialExtendExpiration(int NumDays, int NumExec, SYSTEMTIME* NewDate, int Runtime, int GlobalMinutes);

 extern "C" bool _stdcall WLTrialFirstRun(void);

 extern "C" bool _stdcall WLRegFirstRun(void);

 extern "C" bool _stdcall WLRegCheckMachineLocked(void);

 extern "C" void _stdcall WLSplashHide(void);

 extern "C" void _stdcall WLBufferCrypt(void* Buffer, int BufferLength, char* Password);

 extern "C" void _stdcall WLBufferDecrypt(void* Buffer, int BufferLength, char* Password);

 extern "C" bool _stdcall WLRegSmartKeyInstallToFileInFolder(const char* UserName, const char* Organization, const char* Custom, const char* AsciiKey, const char* FilePath);

 extern "C" int _stdcall WLTrialDateDaysLeft(void);
 
 extern "C" int _stdcall WLRegDateDaysLeft(void);

 extern "C" void _stdcall WLResetLicenseFeatures(sLicenseFeatures *LicenseFeatures, int SizeStructure);

 extern "C" bool _stdcall WLRegGetDynSmartKey(char* SmartKey);

 extern "C" bool _stdcall WLRegDisableKeyCurrentInstance(void);

 extern "C" bool _stdcall WLHardwareRuntimeCheckU3(void);

 extern "C" void _stdcall WLGetVersion(char* Buffer);

 extern "C" int _stdcall WLRegNetInstancesGet(void);

 extern "C" int _stdcall WLRegNetInstancesMax(void);

 extern "C" void _stdcall WLGetProtectionDate(SYSTEMTIME* pProtectionDate);
 
 extern "C" bool _stdcall WLProtectCheckCodeIntegrity(void);

 extern "C" int _stdcall WLHardwareGetIdType(void);

 extern "C" bool _stdcall WLTrialStringRead(const char *StringName, char *StringValue);

 extern "C" bool _stdcall WLTrialStringReadW(const wchar_t *StringName, wchar_t *StringValue);

 extern "C" bool _stdcall WLTrialStringWrite(const char *StringName, const char *StringValue);

 extern "C" bool _stdcall WLTrialStringWriteW(const wchar_t *StringName, const wchar_t *StringValue);

 extern "C" bool _stdcall WLTrialDebugCheck(void);

 extern "C" bool _stdcall WLRegExpirationTimestamp(LPFILETIME lpFileTime);

 extern "C" bool _stdcall WLTrialExpirationTimestamp(LPFILETIME lpFileTime);

 extern "C" int _stdcall WLRegGetLicenseRestrictions(void);

 extern "C" int _stdcall WLRegGetLicenseType(void);

 extern "C" bool _stdcall WLCheckVirtualPC(void);

 extern "C" bool _stdcall WLHardwareGetIDW(wchar_t * pHardwareId);

    
 #endif

// WinLicense macros definition
 
 #ifdef __BORLANDC__
 
 #define REMOVE_BLOCK_START     __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, \
                                           0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define REMOVE_BLOCK_END       __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x01, 0x00, 0x00, 0x00, \
                                           0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define CODEREPLACE_START      __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define CODEREPLACE_END        __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x01, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 
 #define REGISTERED_START       __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x02, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define REGISTERED_END         __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x03, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 
 #define ENCODE_START           __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x04, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define ENCODE_END             __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x05, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define CLEAR_START            __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x06, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define CLEAR_END              __emit__ (0xEB, 0x15, 0x57, 0x4C, 0x20, 0x20, 0x07, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, \
                                          0x00, 0x00, 0x00);

 #define UNREGISTERED_START     __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x08, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define UNREGISTERED_END       __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x09, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define VM_START               __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0C, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define VM_END                 __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0D, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define VM_REGISTEREDVM_START  __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0E, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define VM_REGISTEREDVM_END    __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0F, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define VM_START_WITHLEVEL(x)  __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0C, 0x00, 0x00, 0x00, \
                                          0x00, x, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define UNPROTECTED_START      __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);
 #define UNPROTECTED_END        __emit__ (0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x21, 0x00, 0x00, 0x00, \
                                          0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20);

 #define CHECK_PROTECTION(var, val) \
 asm {  \
   dw    0x10EB; \
   dd    0x091ab3167; \
   dd    0x08a8b717a; \
   dd    0x0bc117abd; \
   dd    0x0; \
   push  val; \
   pop   var; \
   dw    0x0CEB; \
   dd    0x0bc117abd; \
   dd    0x08a8b717a; \
   dd    0x091ab3167; \
}

 #define CHECK_CODE_INTEGRITY(var, val) \
 asm {  \
   dw    0x10EB; \
   dd    0x091ab3167; \
   dd    0x08a8b717a; \
   dd    0x0bc117abd; \
   dd    0x1; \
   push  val; \
   pop   var; \
   dw    0x0CEB; \
   dd    0x0bc117abd; \
   dd    0x08a8b717a; \
   dd    0x091ab3167; \
}

 #define CHECK_REGISTRATION(var, val) \
 asm {  \
   dw    0x10EB; \
   dd    0x091ab3167; \
   dd    0x08a8b717a; \
   dd    0x0bc117abd; \
   dd    0x2; \
   push  val; \
   pop   var; \
   dw    0x0CEB; \
   dd    0x0bc117abd; \
   dd    0x08a8b717a; \
   dd    0x091ab3167; \
}

 #define CHECK_VIRTUAL_PC(var, val) \
 asm {  \
   dw    0x10EB; \
   dd    0x091ab3167; \
   dd    0x08a8b717a; \
   dd    0x0bc117abd; \
   dd    0x3; \
   push  val; \
   pop   var; \
   dw    0x0CEB; \
   dd    0x0bc117abd; \
   dd    0x08a8b717a; \
   dd    0x091ab3167; \
}
 
 #define __WL_MACROS__
 #endif
 
#endif
 
 /* intel cpp compiler */
 
#ifndef __WL_MACROS__
 
 #ifdef __ICL
 
 #define REMOVE_BLOCK_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 #define REMOVE_BLOCK_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x01 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

  #define CODEREPLACE_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 #define CODEREPLACE_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x01 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

 #define REGISTERED_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x02 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 #define REGISTERED_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x03 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 
 #define ENCODE_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x04 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 
 #define ENCODE_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x05 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 
 #define CLEAR_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x06 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

 
 #define CLEAR_END \
  __asm __emit 0xEB \
  __asm __emit 0x15 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x07 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 
 
  #define UNREGISTERED_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x08 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
 
 #define UNREGISTERED_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x09 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

  #define VM_START_WITHLEVEL(x) \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x0C \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit x \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

  #define VM_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x0C \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  
 #define VM_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x0D \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

  #define REGISTEREDVM_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x0E \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  
 #define REGISTEREDVM_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x0F \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \

  #define UNPROTECTED_START \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  
 #define UNPROTECTED_END \
  __asm __emit 0xEB \
  __asm __emit 0x10 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \
  __asm __emit 0x21 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x00 \
  __asm __emit 0x57 \
  __asm __emit 0x4C \
  __asm __emit 0x20 \
  __asm __emit 0x20 \


 #define __WL_MACROS__
 
 #endif
#endif
 
 
 /* LCC by Jacob Navia */
 
#ifndef __WL_MACROS__
 
 #ifdef __LCC__
 
 #define REMOVE_BLOCK_START     __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 #define REMOVE_BLOCK_END       __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x01, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define CODEREPLACE_START      __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 #define CODEREPLACE_END        __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x01, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 
 #define REGISTERED_START       __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x02, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 #define REGISTERED_END         __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x03, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 
 #define ENCODE_START           __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x04, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 #define ENCODE_END             __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x05, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 
 #define CLEAR_START            __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x06, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 
 #define CLEAR_END              __asm__ (" .byte\t0xEB, 0x15, 0x57, 0x4C, 0x20, 0x20, 0x07, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20, 0x00, 0x00, \
                                         0x00, 0x00, 0x00");

 #define UNREGISTERED_START     __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x08, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");
 #define UNREGISTERED_END       __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x09, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define VM_START_WITHLEVEL(x)  __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0C, 0x00, 0x00, 0x00, \
                                         0x00, "x", 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define VM_START               __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0C, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define VM_END                 __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0D, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define REGISTEREDVM_START     __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0E, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define REGISTEREDVM_END       __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x0F, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define UNPROTECTED_START      __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define UNPROTECTED_END        __asm__ (" .byte\t0xEB, 0x10, 0x57, 0x4C, 0x20, 0x20, 0x21, 0x00, 0x00, 0x00, \
                                         0x00, 0x00, 0x00, 0x00, 0x57, 0x4C, 0x20, 0x20");

 #define __WL_MACROS__
 #endif
 
#endif
 
 
#ifndef __WL_MACROS__
 
 #define REMOVE_BLOCK_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define REMOVE_BLOCK_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x01 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define CODEREPLACE_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define CODEREPLACE_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x01 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define REGISTERED_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x02 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
#define REGISTERED_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x03 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define ENCODE_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x04 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define ENCODE_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x05 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define CLEAR_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x06 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define CLEAR_END \
  __asm _emit 0xEB \
  __asm _emit 0x15 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x07 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 

 #define UNREGISTERED_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x08 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
#define UNREGISTERED_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x09 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define VM_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x0C \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define VM_START_WITHLEVEL(x) \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x0C \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit x \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
 
 #define VM_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x0D \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define REGISTEREDVM_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x0E \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define REGISTEREDVM_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x0F \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \


 #define UNPROTECTED_START \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

 #define UNPROTECTED_END \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \
  __asm _emit 0x21 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x57 \
  __asm _emit 0x4C \
  __asm _emit 0x20 \
  __asm _emit 0x20 \

  #define CHECK_PROTECTION(var, val) \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm push  val \
  __asm pop   var \
  __asm _emit 0xEB \
  __asm _emit 0x0C \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \

  #define CHECK_CODE_INTEGRITY(var, val) \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x01 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm push  val \
  __asm pop   var \
  __asm _emit 0xEB \
  __asm _emit 0x0C \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \

  #define CHECK_REGISTRATION(var, val) \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x02 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm push  val \
  __asm pop   var \
  __asm _emit 0xEB \
  __asm _emit 0x0C \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \

  #define CHECK_VIRTUAL_PC(var, val) \
  __asm _emit 0xEB \
  __asm _emit 0x10 \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x03 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm _emit 0x00 \
  __asm push  val \
  __asm pop   var \
  __asm _emit 0xEB \
  __asm _emit 0x0C \
  __asm _emit 0xBD \
  __asm _emit 0x7A \
  __asm _emit 0x11 \
  __asm _emit 0xBC \
  __asm _emit 0x7A \
  __asm _emit 0x71 \
  __asm _emit 0x8B \
  __asm _emit 0x8A \
  __asm _emit 0x67 \
  __asm _emit 0x31 \
  __asm _emit 0xAB \
  __asm _emit 0x91 \

#endif
