#include "stdafx.h"
#include "GameApp.h"
#include <map>

#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
#include <cctype>
#include "AndroidUtils.h"
#define MAX_INT_TO_STR_LEN (20)
extern "C" const char *AppVer()
{ 
	const char * input = "{\"function\":\"GetGameVersionName\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern "C" void PopUpGameExitUI()
{
 
}
extern "C" void ExitGame()
{
 	const char * input = "{\"function\":\"ExitGame\"}";
	AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern "C" const char *PlatformTimeZoneArea()
{
	const char * input = "{\"function\":\"GetTimeZone\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern "C" const char *GetUDID()
{
 	const char * input = "{\"function\":\"GetOpenUDID\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern "C" const char *PlatformAndroidID()
{
 	const char * input = "{\"function\":\"GetAndroidID\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern "C" const char *PlatformAndroidDeviceID()
{
	const char * input = "{\"function\":\"GetDeviceName\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
 	//return "PlatformAndroidDeviceID"; 
}
extern "C" const char *PlatformDeviceMacAddress()
{
	const char * input = "{\"function\":\"GetMacAddr\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
// return "AndroidMacAddr"; 
}
extern "C" const char *DeviceLanguageSetting()
{
	const char * input = "{\"function\":\"GetLanguage\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
// return "en"; 
}
extern "C" const char *AppleID(){ return "AndroidAppleID"; }
extern "C" const char *GPUDevVersion()
{
	const char * input = "{\"function\":\"GetCPUName\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
// return "AndroidGPUVersion"; 
}
extern "C" const char *DeviceNameCode()
{
	const char * input = "{\"function\":\"GetDeviceName\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
// return "FakeWin32DeviceVersion"; 
}
extern "C" const char *DeviceOSVersionCode()
{	
	const char * input = "{\"function\":\"GetOSVersion\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
 //return "Win32"; 
}
extern "C" void SetPastBoard(const char* param)
{
	const char * input = "{\"function\":\"CopyToPastBoard\",\"param1\":\"%s\"}";
	char * buf = getJniRetBuff(strlen(param)+strlen(input));
	sprintf(buf,input,param);
	AndroidUtils_CallStaticAndroidJavaFunction(buf); 
}
extern "C" const char* GetPastBoard()
{
	const char * input = "{\"function\":\"GetFromPastBoard\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern "C" int IsWifiOK()
{
	const char * input = "{\"function\":\"isWifiReached\"}";
	const char * ret = AndroidUtils_CallStaticAndroidJavaFunction(input); 
	if(ret != NULL)
		return atoi(ret);
 	return 0; 
}
extern "C" bool DoCreateAndShowWebView(const char *url, int x, int y, int w, int h)
{
 	const char * input = "{\"function\":\"OpenWebView\",\"param1\":\"%s\",\"param2\":%d,\"param3\":%d,\"param4\":%d,\"param5\":%d}";
 	char * buf = getJniRetBuff(strlen(input)+strlen(url) + MAX_INT_TO_STR_LEN*4);
 	sprintf(buf,input,url,x,y,w,h);
 	AndroidUtils_CallStaticAndroidJavaFunction(buf); 
 	printf("Open url %s", url); 
 	return true; 
}
extern "C" void DoHideWebView(bool notvisible)
{
	const char * input = "{\"function\":\"SetVisibleWebView\",\"param1\":%d}";
	char * buf = getJniRetBuff(strlen(input)+ MAX_INT_TO_STR_LEN);
 	sprintf(buf,input,notvisible == true?0:1);
	AndroidUtils_CallStaticAndroidJavaFunction(buf); 
 	printf("hide web view"); 
}
extern "C" int IsNetOK()
{
	const char * input = "{\"function\":\"isNetConnected\"}";
	const char * ret = AndroidUtils_CallStaticAndroidJavaFunction(input); 
	if(ret != NULL)
		return atoi(ret);
 	return 0; 
 return 1; 
}

extern "C" const char* GetNetworkType()
{
	const char * input = "{\"function\":\"GetNetWorkType\"}";
	const char * ret = AndroidUtils_CallStaticAndroidJavaFunction(input); 
	
 	return ret; 
}
extern "C" void showAlertView(const char* message, int tag){ printf("FakeWin32ShowAlertView %s, %d \n", message, tag); }
extern "C" const char* GetPlatform(){ return "WIN32"; }
extern "C" void addLocalNotification(const char * nt){ printf("to do add win32 local notification;"); }
extern "C" const char *GetIDFA(){ return "WINIDFA"; }

extern "C" void OpenURL(const char* url)
{

	const char * input = "{\"function\":\"OpenUrl\",\"param1\":\"%s\"}";
	char * buf = getJniRetBuff(strlen(url)+strlen(input));
	sprintf(buf,input,url);

	AndroidUtils_CallStaticAndroidJavaFunction(buf); 
}

extern "C" const char *GetOpenUdid()
{
	const char * input = "{\"function\":\"GetOpenUDID\"}";
	return AndroidUtils_CallStaticAndroidJavaFunction(input); 
}
extern int TrackingAssert_impl(const char*key,const char*param)
{
	return 0;
}

extern "C" const char* CallNativeFuntionByJson(const char * jsonstring)
{
	return AndroidUtils_CallStaticAndroidJavaFunction(jsonstring); 
}




