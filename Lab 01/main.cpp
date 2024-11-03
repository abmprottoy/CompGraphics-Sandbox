#include <Windows.h>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Begin drawing a triangle
    glBegin(GL_TRIANGLES);
    // Set the color to red for the first vertex
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);

    // Set the color to green for the second vertex
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);

    // Set the color to blue for the third vertex
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd(); // End drawing the triangle

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