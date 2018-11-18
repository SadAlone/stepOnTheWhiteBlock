#pragma once
#include <iostream>
#include <glad.h>
#include <glfw3.h>


//����
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

//�Դ���ע��һ���ص���������ÿ�δ��ڴ�С��������ʱ����á�
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

//��������
int CreateMyWindows()
{
	glfwInit();  //��ʼ��GLFW
				 //����GLFW
				 //��һ��������ѡ�����ƣ��ɴ�GLFW_��ͷ��ö��ֵ��ѡ�񣻵ڶ�����������һ������
				 //�����������ѡ���ֵ��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//����һ�����ڶ���
	GLFWwindow* window = glfwCreateWindow(800, 600, "MyOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//GLAD��������OpenGL�ĺ���ָ�룬�ڵ����κ�OpenGL�ĺ���֮ǰ��Ҫ��ʼ��GLAD��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//�ӿڣ���Ҫ����OPENGL��Ⱦ���ڵĳߴ��С
	//����ͨ��glViewport���������ô��ڵ�ά��
	//ǰ���������ǿ��ƴ������½ǵ�λ�ã��������͵��ĸ���������Ⱦ���ڵĿ�Ⱥ͸߶ȣ����أ�
	glViewport(0, 0, 800, 600);
	//ע�����Խ��ӿڵ�ά������Ϊ��GLFWά��С������֮�����е�OPENGL��Ⱦ������һ����С�Ĵ�������ʾ��
	//�������Խ�һЩ����Ԫ����ʾ��OPENGL�ӿ�֮�⡣

	//�����ڵ�һ����ʾ��ʱ��framebuffer_size_callbackҲ�ᱻ���ã���������Ĥ��ʾ����width��height�������Ա�ԭ����ֵ����һ��
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//��Ⱦѭ��
	//glfwWindowShouldClose������ÿ��ѭ���Ŀ�ʼǰ���һ��GLFW�Ƿ�Ҫ���˳���
	//����Ǹú�������true��Ȼ����Ⱦѭ�����������Թر�Ӧ�ó���
	//glfwPollEvents���������û�д���ʲôʱ�䣨����������룬����ƶ��������´���״̬��������
	//��Ӧ�Ļص�����������ͨ���ص������ֶ����ã�
	//glfwSwapBuffers�����ύ����ɫ���壨����һ���洢��GLFW����ÿһ��������ɫֵ�Ĵ󻺳壩��������һ
	//�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ��
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//״̬���ú��� �����Ļ���õ���ɫ
		glClear(GL_COLOR_BUFFER_BIT);//״̬ʹ�õĺ��� �����ɫ����֮��������ɫ���嶼�ᱻ���ΪglClearColor�������õ���ɫ

		glfwSwapBuffers(window); 
		glfwPollEvents();
	}

	return 0;
}





int main()
{
	CreateMyWindows();
	//��Ⱦѭ����������Ҫ��ȷ�ͷ�/ɾ��֮ǰ�ķ����������Դ��������main
	//������������glfwTerminate�������.
	glfwTerminate();
	return 0;
}