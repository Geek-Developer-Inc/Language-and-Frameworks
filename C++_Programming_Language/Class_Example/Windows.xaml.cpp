#include "Windows.xaml.h"


using namespace std;
using namespace SDKSample;
using namespace SDKSample::WASAPIAudio;


/*
 *                            类的构造函数 (C++)    
 *
 * 在C++中，有一种特殊的成员函数，它的名字和类名相同，没有返回值，不需要用户显式调用（用户也不能调用），
 * 而是在创建对象时自动执行。这种特殊的成员函数就是构造函数（Constructor）。 
 * 
 * 构造函数必须是 public 属性的，否则创建对象时无法调用。当然，设置为 private、protected 属性也不会报错，但是没有意义。
 * 
 * 构造函数没有返回值，因为没有变量来接收返回值，即使有也毫无用处，这意味着：
 *     --不管是声明还是定义，函数名前面都不能出现返回值类型，即使是 void 也不允许；
 *     --函数体中不能有 return 语句。
 * 
 */

SDKTemplate::SDKTemplate(void)    /*    无参构造函数    */
{
	cout << "Call no-argument constructor" << endl;
	cout << "this: " << this << endl;
	Boolean = 8888;
	strcpy(DeviceState, "hello word");
	ComPtr = 88.88f;
}


/*                              构造函数的重载 (C++)
 *
 * 和普通成员函数一样，构造函数是允许重载的。一个类可以有多个重载的构造函数，创建对象时根据传递的实参来判断调用哪一个构造函数。
 * 
 * 构造函数的调用是强制性的，一旦在类中定义了构造函数，那么创建对象时就一定要调用，不调用是错误的。如果有多个重载的构造函数，
 * 那么创建对象时提供的实参必须和其中的一个构造函数匹配；反过来说，创建对象时只有一个构造函数会被调用。
 * 
 * 
 *                              默认构造函数
 * 
 * 一个类必须有构造函数，要么用户自己定义，要么编译器自动生成。一旦用户自己定义了构造函数，不管有几个，也不管形参如何，编译器
 * 都不再自动生成。
 * 
 */

SDKTemplate::SDKTemplate(int Boolean, char* DeviceState, float ComPtr)    /*    带参构造函数    */
{
	cout << "Call the parameterized constructor" << endl;
	cout << "this: " << this << endl;
	this->Boolean = Boolean;
	strcpy(this->DeviceState, DeviceState);
	this->ComPtr = ComPtr;
}


/*                 
 *                                   析构函数 (C++)
 * 
 * 析构函数（Destructor）也是一种特殊的成员函数，没有返回值，不需要程序员显式调用（程序员也没法显式调用），而是在销毁对象时自动执行。
 * 构造函数的名字和类名相同，而析构函数的名字是在类名前面加一个~符号。
 * 
 * 注意：析构函数没有参数，不能被重载，因此一个类只能有一个析构函数。如果用户没有定义，编译器会自动生成一个默认的析构函数。
 *
 * 析构函数在对象被销毁时调用，而对象的销毁时机与它所在的内存区域有关
 * 在所有函数之外创建的对象是全局对象，它和全局变量类似，位于内存分区中的全局数据区，程序在结束执行时会调用这些对象的析构函数。
 * 在函数内部创建的对象是局部对象，它和局部变量类似，位于栈区，函数执行结束时会调用这些对象的析构函数。
 * new 创建的对象位于堆区，通过 delete 删除时才会调用析构函数；如果没有 delete，析构函数就不会被执行。    
 *     
 */

SDKTemplate::~SDKTemplate(void)    /*    析构函数    */
{
	cout << "Call destructor" << endl;
	cout << "this: " << this << endl;
	Boolean = 0x00;
	strcpy(DeviceState, "\0");
	ComPtr = 0.000f;
}


/*
 *
 *                    C++ this指针
 * this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。
 * this 只能用在类的内部，通过 this 可以访问类的所有成员，包括 private、protected、public 属性的。
 * 注意，this 是一个指针，要用->来访问成员变量或成员函数。
 * this 虽然用在类的内部，但是只有在对象被创建以后才会给 this 赋值，并且这个赋值的过程是编译器自动完成的，
 * 不需要用户干预，用户也不能显式地给 this 赋值。
 * 
 * 几点注意:
 * this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
 * this 只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
 * 只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。
 * 
 * this 实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给 this。不过 this 这个形参是隐式的，
 * 它并不出现在代码中，而是在编译阶段由编译器默默地将它添加到参数列表中。
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

