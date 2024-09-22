//
// Created by Administrator on 9/21/2024.
//

#include "core/Application.h"

/**
 * 设置GLFW
 */
void setupGlfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int main()
{
    setupGlfw();
}