#pragma once


#ifndef  __WINDOWS_XAML_H
#define  __WINDOWS_XAML_H


#if ( _MSC_VER)  /*    ��� Visual Studio ��ȫ��������    */
#define _CRT_SECURE_NO_WARNINGS 
#endif

#include <iostream>
#include <cstring>


namespace SDKSample        /*  �������ƿռ�  */
{
	namespace WASAPIAudio  /*  SDKSample::WASAPIAudio  */
	{
		class SDKTemplate  /*  ������ C++  */
		{
		public:
			SDKTemplate(void);  /*  �޲ι��캯��  */
			SDKTemplate(int Boolean, char* DeviceState, float ComPtr);   /*  ���ι��캯��  */
			~SDKTemplate(void);  /*  ��������  */

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

