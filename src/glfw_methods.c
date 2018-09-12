#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <vulkan.h>
#define GLFW_DEFINE_VULKAN
#include <glfw3.h>

#include "constants.h"
#include "error_methods.h"
#include "glfw_methods.h"

GLFWwindow* createGlfwWindow()
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	return glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Vulkan", NULL, NULL);
}

VkSurfaceKHR createSurface(GLFWwindow* window, VkInstance instance)
{
	VkSurfaceKHR surface= {0};
	if (glfwCreateWindowSurface(instance, window, NULL, &surface) != VK_SUCCESS) {
		fprintf(stderr,"failed to create surface, quitting\n");
		hardExit();
	}
	return surface;
}
