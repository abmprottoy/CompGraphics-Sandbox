#include <Windows.h>
#include <GL/freeglut.h>

void display() {
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set the background color to grey
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw the grid lines (green lines at the center)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.75f, 0.25f);
    glVertex2f(-0.25f, 0.25f);
    glVertex2f(-0.5f, 0.75f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_POLYGON);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(0.375f, 0.75f);
    glVertex2f(0.625f, 0.75f);
    glVertex2f(0.75f, 0.5f);
    glVertex2f(0.625f, 0.25f);
    glVertex2f(0.375f, 0.25f);
    glEnd();


    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glBegin(GL_QUADS);
    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.25f, -0.25f);
    glVertex2f(-0.25f, -0.75f);
    glVertex2f(-0.75f, -0.75f);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f); // Orange color
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, -0.25f);
    glVertex2f(0.55f, -0.75f);
    glVertex2f(0.35f, -0.75f);
    glEnd();



    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
    glutCreateWindow("Graphics Introduction");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}