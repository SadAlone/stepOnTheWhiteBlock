#pragma once
#include <iostream>
#include <glad.h>
#include <glfw3.h>


//输入
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

//对窗口注册一个回调函数，在每次窗口大小被调整的时候调用。
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//创建窗口
int CreateMyWindows()
{
	glfwInit();  //初始化GLFW
				 //配置GLFW
				 //第一个参数：选项名称，可从GLFW_开头的枚举值中选择；第二个参数接收一个整形
				 //用来设置这个选项的值。
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//创建一个窗口对象
	GLFWwindow* window = glfwCreateWindow(800, 600, "MyOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//GLAD用来管理OpenGL的函数指针，在调用任何OpenGL的函数之前需要初始化GLAD。
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//视口：即要告诉OPENGL渲染窗口的尺寸大小
	//可以通过glViewport函数来设置窗口的维度
	//前两个参数是控制窗口左下角的位置，第三个和第四个参数是渲染窗口的宽度和高度（像素）
	glViewport(0, 0, 800, 600);
	//注：可以将视口的维度设置为比GLFW维度小，这样之后所有的OPENGL渲染将会在一个更小的窗口中显示，
	//这样可以将一些其它元素显示在OPENGL视口之外。

	//当窗口第一次显示的时候framebuffer_size_callback也会被调用，对于视网膜显示屏，width和height都会明显比原输入值更高一点
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//渲染循环
	//glfwWindowShouldClose函数在每次循环的开始前检查一次GLFW是否被要求退出，
	//如果是该函数返回true，然后渲染循环结束，可以关闭应用程序
	//glfwPollEvents函数检查有没有触发什么时间（比如键盘输入，鼠标移动）、更新窗口状态，并调用
	//对应的回调函数（可以通过回调方法手动设置）
	//glfwSwapBuffers函数会交换颜色缓冲（它是一个存储着GLFW窗口每一个像素颜色值的大缓冲），它在这一
	//迭代中被用来绘制，并且将会作为输出显示在屏幕上
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//状态设置函数 清空屏幕所用的颜色
		glClear(GL_COLOR_BUFFER_BIT);//状态使用的函数 清楚颜色缓冲之后，整个颜色缓冲都会被填充为glClearColor里所设置的颜色

		glfwSwapBuffers(window); 
		glfwPollEvents();
	}

	return 0;
}





int main()
{
	CreateMyWindows();
	//渲染循环结束后需要正确释放/删除之前的分配的所有资源，可以在main
	//函数的最后调用glfwTerminate函数完成.
	glfwTerminate();
	return 0;
}