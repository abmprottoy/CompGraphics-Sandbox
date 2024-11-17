#include <Windows.h>
#include <GL/freeglut.h>

void display() {
    glClearColor(0.07f, 0.16f, 0.24f, 0.0f); // Set the background color
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw the grid lines (green lines at the center)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(0.0f, 1.0f);
    glEnd();

    /// Switzerland Flag

	// Draw the rectangle
	glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.81f, 0.24f); // Bottom-left
    glVertex2f(-0.21f, 0.24f); // Bottom-right
    glVertex2f(-0.21f, 0.84f); // Top-right
    glVertex2f(-0.81f, 0.84f); // Top-left
    glEnd();

	// Draw the rectangle
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
    glVertex2f(-0.32f, 0.48f);
	glVertex2f(-0.32f, 0.59f);
	glVertex2f(-0.70f, 0.59f);
	glVertex2f(-0.70f, 0.48f);
	glEnd();

    // Draw the rectangle
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.46f, 0.35f);
    glVertex2f(-0.46f, 0.72f);
    glVertex2f(-0.56f, 0.72f);
    glVertex2f(-0.56f, 0.35f);
    glEnd();

    /// Scotland Flag

    // Draw the rectangle
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.79f, 0.69f);
    glVertex2f(0.19f, 0.69f);
    glVertex2f(0.19f, 0.33f);
    glVertex2f(0.79f, 0.33f);
    glEnd();
    
    // Draw the triangle
    glColor3f(0.0f, 0.37f, 0.72f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.71f, 0.69f);
    glVertex2f(0.49f, 0.55f);
    glVertex2f(0.26f, 0.69f);
    glEnd();

    // Draw the triangle
    glColor3f(0.0f, 0.37f, 0.72f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.79f, 0.64f);
    glVertex2f(0.79f, 0.37f);
    glVertex2f(0.56f, 0.51f);
    glEnd();

    // Draw the triangle
    glColor3f(0.0f, 0.37f, 0.72f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.72f, 0.33f);
    glVertex2f(0.49f, 0.47f);
    glVertex2f(0.26f, 0.33f);
    glEnd();
    
    // Draw the triangle
    glColor3f(0.0f, 0.37f, 0.72f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.19f, 0.37f);
    glVertex2f(0.42f, 0.51f);
    glVertex2f(0.19f, 0.64f);
    glEnd();

    ///Finland Flag

    // Draw the rectangle
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, -0.26f);
    glVertex2f(-0.19f, -0.62f);
    glVertex2f(-0.79f, -0.62f);
    glVertex2f(-0.79f, -0.26f);
    glEnd();
    
    // Draw the rectangle
    glColor3f(0.0f, 0.18f, 0.42f);
    glBegin(GL_QUADS);
    glVertex2f(-0.53f, -0.26f);
    glVertex2f(-0.63f, -0.26f);
    glVertex2f(-0.63f, -0.62f);
    glVertex2f(-0.53f, -0.62f);
    glEnd();

    // Draw the rectangle
    glColor3f(0.0f, 0.18f, 0.42f);
    glBegin(GL_QUADS);
    glVertex2f(-0.19f, -0.39f);
    glVertex2f(-0.79f, -0.39f);
    glVertex2f(-0.79f, -0.49f);
    glVertex2f(-0.19f, -0.49f);
    glEnd();

    /// Vietnam Flag

    // Draw the rectangle
    glColor3f(0.85f, 0.15f, 0.11f);
    glBegin(GL_QUADS);
    glVertex2f(0.80f, -0.23f);
    glVertex2f(0.19f, -0.23f);
    glVertex2f(0.19f, -0.63f);
    glVertex2f(0.80f, -0.63f);
    glEnd();

    // Draw the Polygon
	glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
	glVertex2f(0.60f, -0.40f);
    glVertex2f(0.52f, -0.39f);
    glVertex2f(0.50f, -0.32f);
    glVertex2f(0.47f, -0.39f);
    glVertex2f(0.39f, -0.39f);
    glVertex2f(0.45f, -0.44f);
    glVertex2f(0.43f, -0.52f);
    glVertex2f(0.50f, -0.48f);
    glVertex2f(0.56f, -0.52f);
    glVertex2f(0.54f, -0.44f);
	glEnd();





    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
	glutInitWindowPosition(700, 100);
    glutCreateWindow("Graphics Introduction - Country Flags");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}