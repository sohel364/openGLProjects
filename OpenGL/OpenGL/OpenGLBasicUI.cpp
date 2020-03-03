// OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Simple program to test the supported openGL version by this platform

#include <GLFW/glfw3.h>
#include <gl/glut.h>
#include <iostream>

// DrawRectangle
void DrawRectangle()
{

	glBegin(GL_LINES);
    
    glVertex2f(.5, .5);
    glVertex2f(.5, 0);

    glVertex2f(0, .5);
    glVertex2f(.5, .5);

	glVertex2f(0, 0);
	glVertex2f(.5, 0);

	glVertex2f(0, 0);
	glVertex2f(0, .5);

	//glVertex2f(0, 0); 
	//glVertex2f(0, .5);

	glEnd();
}

// Draw Lines
void DrawLines()
{
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 1);

    glVertex2f(0, 0);
    glVertex2f(0, -1);

	glVertex2f(0, 0);
	glVertex2f(-1, 0);

	glVertex2f(0, 0);
	glVertex2f(1, 0);

	glVertex2f(0, 1);
	glVertex2f(0, 0);

	glEnd();
}

// Draw a triangle
void DrawTringle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

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

    std::cout << "This platform supports : " << glGetString(GL_VERSION) << std::endl;
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /*Test functions*/
        DrawRectangle();
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
    // Create an OpenGL window with GLFW Library
    CreateWindowWithGLFW();
}
