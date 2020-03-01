// OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Simple program to test the supported openGL version by this platform

#include <GLFW/glfw3.h>
#include <gl/glut.h>
#include <iostream>

// Create window with GLFW Window
int CreateWindowWithGLFW()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window); 

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_LINES);
        glVertex2f(10, 10);
        glVertex2f(20, 20);
        glEnd();
        
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("GLUT");

    std::cout << "This platform supports : " << glGetString(GL_VERSION) << std::endl;

    // Create an OpenGL window with GLFW Library
    CreateWindowWithGLFW();
}
