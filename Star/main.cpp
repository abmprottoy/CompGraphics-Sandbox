#include <Windows.h>
#include <GL/freeglut.h>

void display() {
    glClearColor(0.07f, 0.16f, 0.24, 0.0f); // Set the background color to grey
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw the grid lines (green lines at the center)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    glPointSize(10.0);
    // Begin drawing a triangle
    glBegin(GL_POINTS);

    glColor3f(1.0, 0.0, 0.0); // Set the color to red
    glVertex2f(-0.628f, -0.456f); // Set the vertex of the point
    glEnd();


    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition(700, 100);
    glutCreateWindow("Graphics Introduction");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}