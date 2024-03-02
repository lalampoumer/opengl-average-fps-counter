#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <time.h>

int main() {
	const int take_average = 10;
	int timer = 0;
	int bil = 0;
	int list[take_average];
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "opengl application", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(2);

	gladLoadGL();
	glViewport(0, 0, 800, 800);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		clock_t start = clock();

		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		//calculate average fps
		if (timer < take_average) { timer++; }
		if (timer > take_average - 1)
		{
			for (int i = 0; i < take_average; i++)
			{
				bil = bil + list[i];
			}
			std::cout << "avrg fps: " << 1000 / (bil / take_average) << std::endl;
			timer = 0;
			bil = 0;
		}

		clock_t end = clock();
		double cal_time = end - start;
		list[timer] = cal_time;


	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}