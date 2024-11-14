#include <Windows.h>
#include <GL/freeglut.h>

void display() {
	glClearColor(0.0f, 0.48f, 0.8f, 0.0f); // Set the background color
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
	glPointSize(10.0); // Set the point size to 10 pixels
	glLineWidth(1.0); // Set the line width to 5 pixels

    // Begin drawing a triangle
    glBegin(GL_POINTS);
    
	glColor3f(1.0, 0.0, 0.0); // Set the color to red
	glVertex2f(-0.0f, -0.0f); // Set the vertex of the point
    glEnd(); // End drawing the triangle

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0); // Set the color to green
	glVertex2f(-0.5f, -0.2f); // Set the vertex of the first line
	glVertex2f(0.5f, 0.2f); // Set the vertex of the second line
	glEnd(); // End drawing the lines

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); // Set the color to blue
	glVertex2f(-4.0f, 4.0f); // Set the vertex of the first line
	glVertex2f(1.74f, 4.71f); // Set the vertex of the second line
	glVertex2f(2.14f, -2.45f); // Set the vertex of the third line
	glVertex2f(-4.78f, 2.53f); // Set the vertex of the fourth line
	glEnd(); // End drawing the polygon

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