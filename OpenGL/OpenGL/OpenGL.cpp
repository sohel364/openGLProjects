// OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Simple program to test the supported openGL version by this platform

#include <gl/glut.h>
#include <iostream>

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("GLUT");
    
    std::cout << "This platform supports : " << glGetString(GL_VERSION) << std::endl;
}
