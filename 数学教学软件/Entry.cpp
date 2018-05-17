#include "Login.h"

using namespace 数学教学软件;


[STAThreadAttribute]
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Application::Run(gcnew Login);
	Application::Run(gcnew 教学大纲);

}