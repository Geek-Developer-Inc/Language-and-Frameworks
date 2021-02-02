#include "Windows.xaml.h"


using namespace std;
using namespace SDKSample;
using namespace SDKSample::WASAPIAudio;


/*
 *                            ��Ĺ��캯�� (C++)    
 *
 * ��C++�У���һ������ĳ�Ա�������������ֺ�������ͬ��û�з���ֵ������Ҫ�û���ʽ���ã��û�Ҳ���ܵ��ã���
 * �����ڴ�������ʱ�Զ�ִ�С���������ĳ�Ա�������ǹ��캯����Constructor���� 
 * 
 * ���캯�������� public ���Եģ����򴴽�����ʱ�޷����á���Ȼ������Ϊ private��protected ����Ҳ���ᱨ������û�����塣
 * 
 * ���캯��û�з���ֵ����Ϊû�б��������շ���ֵ����ʹ��Ҳ�����ô�������ζ�ţ�
 *     --�������������Ƕ��壬������ǰ�涼���ܳ��ַ���ֵ���ͣ���ʹ�� void Ҳ������
 *     --�������в����� return ��䡣
 * 
 */

SDKTemplate::SDKTemplate(void)    /*    �޲ι��캯��    */
{
	cout << "Call no-argument constructor" << endl;
	cout << "this: " << this << endl;
	Boolean = 8888;
	strcpy(DeviceState, "hello word");
	ComPtr = 88.88f;
}


/*                              ���캯�������� (C++)
 *
 * ����ͨ��Ա����һ�������캯�����������صġ�һ��������ж�����صĹ��캯������������ʱ���ݴ��ݵ�ʵ�����жϵ�����һ�����캯����
 * 
 * ���캯���ĵ�����ǿ���Եģ�һ�������ж����˹��캯������ô��������ʱ��һ��Ҫ���ã��������Ǵ���ġ�����ж�����صĹ��캯����
 * ��ô��������ʱ�ṩ��ʵ�α�������е�һ�����캯��ƥ�䣻������˵����������ʱֻ��һ�����캯���ᱻ���á�
 * 
 * 
 *                              Ĭ�Ϲ��캯��
 * 
 * һ��������й��캯����Ҫô�û��Լ����壬Ҫô�������Զ����ɡ�һ���û��Լ������˹��캯���������м�����Ҳ�����β���Σ�������
 * �������Զ����ɡ�
 * 
 */

SDKTemplate::SDKTemplate(int Boolean, char* DeviceState, float ComPtr)    /*    ���ι��캯��    */
{
	cout << "Call the parameterized constructor" << endl;
	cout << "this: " << this << endl;
	this->Boolean = Boolean;
	strcpy(this->DeviceState, DeviceState);
	this->ComPtr = ComPtr;
}


/*                 
 *                                   �������� (C++)
 * 
 * ����������Destructor��Ҳ��һ������ĳ�Ա������û�з���ֵ������Ҫ����Ա��ʽ���ã�����ԱҲû����ʽ���ã������������ٶ���ʱ�Զ�ִ�С�
 * ���캯�������ֺ�������ͬ��������������������������ǰ���һ��~���š�
 * 
 * ע�⣺��������û�в��������ܱ����أ����һ����ֻ����һ����������������û�û�ж��壬���������Զ�����һ��Ĭ�ϵ�����������
 *
 * ���������ڶ�������ʱ���ã������������ʱ���������ڵ��ڴ������й�
 * �����к���֮�ⴴ���Ķ�����ȫ�ֶ�������ȫ�ֱ������ƣ�λ���ڴ�����е�ȫ���������������ڽ���ִ��ʱ�������Щ���������������
 * �ں����ڲ������Ķ����Ǿֲ��������;ֲ��������ƣ�λ��ջ��������ִ�н���ʱ�������Щ���������������
 * new �����Ķ���λ�ڶ�����ͨ�� delete ɾ��ʱ�Ż�����������������û�� delete�����������Ͳ��ᱻִ�С�    
 *     
 */

SDKTemplate::~SDKTemplate(void)    /*    ��������    */
{
	cout << "Call destructor" << endl;
	cout << "this: " << this << endl;
	Boolean = 0x00;
	strcpy(DeviceState, "\0");
	ComPtr = 0.000f;
}


/*
 *
 *                    C++ thisָ��
 * this �� C++ �е�һ���ؼ��֣�Ҳ��һ�� const ָ�룬��ָ��ǰ����ͨ�������Է��ʵ�ǰ��������г�Ա��
 * this ֻ����������ڲ���ͨ�� this ���Է���������г�Ա������ private��protected��public ���Եġ�
 * ע�⣬this ��һ��ָ�룬Ҫ��->�����ʳ�Ա�������Ա������
 * this ��Ȼ��������ڲ�������ֻ���ڶ��󱻴����Ժ�Ż�� this ��ֵ�����������ֵ�Ĺ����Ǳ������Զ���ɵģ�
 * ����Ҫ�û���Ԥ���û�Ҳ������ʽ�ظ� this ��ֵ��
 * 
 * ����ע��:
 * this �� const ָ�룬����ֵ�ǲ��ܱ��޸ĵģ�һ����ͼ�޸ĸ�ָ��Ĳ������縳ֵ���������ݼ��ȶ��ǲ�����ġ�
 * this ֻ���ڳ�Ա�����ڲ�ʹ�ã����������ط�û�����壬Ҳ�ǷǷ��ġ�
 * ֻ�е����󱻴����� this �������壬��˲����� static ��Ա������ʹ�ã������ὲ�� static ��Ա����
 * 
 * this ʵ�����ǳ�Ա������һ���βΣ��ڵ��ó�Ա����ʱ������ĵ�ַ��Ϊʵ�δ��ݸ� this������ this ����β�����ʽ�ģ�
 * �����������ڴ����У������ڱ���׶��ɱ�����ĬĬ�ؽ�����ӵ������б��С�
 * 
 */

void SDKTemplate::SetParameters(int Boolean, char* DeviceState, float ComPtr)
{
	cout << "Call set parameter function" << endl;

	this->Boolean = Boolean;
	strcpy(this->DeviceState, DeviceState);
	this->ComPtr = ComPtr;
}


void SDKTemplate::GetParameters(int* Boolean, char* DeviceState, float* ComPtr)
{
	cout << "Call get parameter function" << endl;

	*Boolean = this->Boolean;
	*ComPtr = this->ComPtr;
}


void SDKTemplate::ShowParameters(void)
{
	cout << "Show the value of the parameter:" << endl;
	cout << "Boolean = " << Boolean << endl;
	cout << "DeviceState = " << DeviceState << endl;
	cout << "ComPtr = " << ComPtr << endl;
}

