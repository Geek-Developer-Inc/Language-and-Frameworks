#pragma once


#ifndef  __WINDOWS_XAML_H
#define  __WINDOWS_XAML_H


#if ( _MSC_VER)  /*    规避 Visual Studio 安全函数报错    */
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include <iostream>
#include <cstring>


namespace SDKSample        /*  定义名称空间  */
{
	namespace WASAPIAudio  /*  SDKSample::WASAPIAudio  */
	{
		class SDKTemplate  /*  定义类 C++  */
		{
		public:
			SDKTemplate(void);  /*  无参构造函数  */
			SDKTemplate(int Boolean, char* DeviceState, float ComPtr);   /*  带参构造函数  */
			~SDKTemplate(void);  /*  析构函数  */

			void SetParameters(int Boolean, char* DeviceState, float ComPtr);
			void GetParameters(int *Boolean, char*DeviceState, float *ComPtr);
			void ShowParameters(void);
		private:
			int Boolean;
			char DeviceState[128];
			float ComPtr;
		};
	}
}


#endif    /*  END  __WINDOWS_XAML_H  */

