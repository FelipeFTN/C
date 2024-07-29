#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

void error_callback(int error, const char* description);
static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

int main() {
    if (!glfwInit()) {
        // Initialization failed
        glfwTerminate();
        return -1;
    }
    glfwSetErrorCallback(error_callback);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Game", NULL, NULL);
    if (!window) {
        // Window or OpenGL context creation failed
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    // gladLoadGL();

    while(!glfwWindowShouldClose(window)) {
        glfwSetKeyCallback(window, key_callback);
        // Rendering with OpenGL
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void error_callback(int error, const char* description) {
    fprintf(stderr, "[X] Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}
