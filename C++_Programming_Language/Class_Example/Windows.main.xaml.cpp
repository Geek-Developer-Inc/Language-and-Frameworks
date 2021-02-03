#include "Windows.xaml.h"


using namespace SDKSample;
using namespace SDKSample::WASAPIAudio;

/*    应用 SDKTemplate 类   */
int main(int argc, char** argv)
{
        SDKTemplate SDK1;      /*    类型  变量名   如：int a;   此处自动调用默认无参构造函数    */
        SDK1.ShowParameters(); /*    类调用成员函数   */
        SDK1.SetParameters(386, (char*)"new value", 653.563f);
        int retBoolean = 0;
        float retComPtr = 0.00f;
        SDK1.GetParameters(&retBoolean, NULL, &retComPtr);
        std::cout << "retBoolean = " << retBoolean << std::endl;
        std::cout << "retComPtr = " << retComPtr << std::endl;

        SDKTemplate SDK2(525,(char*)"525",5.25f);   /*   自动调用带参构造    */
        SDK2.ShowParameters();

        return 0;    /*   自动析构造函数   */
}
