#include "Windows.xaml.h"
#include "color.h"

using namespace SDKSample;
using namespace SDKSample::WASAPIAudio;

#define green redbud::io::state::manual << redbud::io::hfg::green
#define red   redbud::io::state::manual << redbud::io::hfg::red
#define white redbud::io::state::manual << redbud::io::hfg::white

/*    Ӧ�� SDKTemplate ��   */
int main(int argc, char** argv)
{

	SDKTemplate SDK1;      /*    ����  ������   �磺int a;   �˴��Զ�����Ĭ���޲ι��캯��    */
	SDK1.ShowParameters(); /*    ����ó�Ա����   */
	SDK1.SetParameters(386, (char*)"new value", 653.563f);
	int retBoolean = 0;
	float retComPtr = 0.00f;
	SDK1.GetParameters(&retBoolean, NULL, &retComPtr);
	std::cout << red << "retBoolean = " << retBoolean << std::endl;
	std::cout << "retComPtr = " << retComPtr << std::endl;

	SDKTemplate SDK2(525,(char*)"525",5.25f);   /*   �Զ����ô��ι���    */
	SDK2.ShowParameters();
	std::cout << white << std::endl;
	return 0;    /*   �Զ������캯��   */
}

//namespace SDKSample


