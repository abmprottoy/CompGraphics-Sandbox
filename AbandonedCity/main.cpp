#include <Windows.h>
#include <math.h>
#include <GL/freeglut.h>

// Function to draw a filled circle
void drawCircle(float cx, float cy, float radius, float r, float g, float b) {
    glColor3f(r, g, b); // Set color
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * 3.14159f * i / 100;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void setupOrtho(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Adjust orthographic projection to maintain aspect ratio
    float aspectRatio = (float)width / (float)height;
    if (aspectRatio >= 1.0f) {
        // Wide canvas: adjust x-axis
        glOrtho(-aspectRatio, aspectRatio, -1.0, 1.0, -1.0, 1.0);
    }
    else {
        // Tall canvas: adjust y-axis
        glOrtho(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h); // Set the viewport to cover the new window
    setupOrtho(w, h);       // Adjust the orthographic projection
}


void glDrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

	// Ground
    glColor3f(0.51f, 0.47f, 0.39f);
    glBegin(GL_POLYGON);

    glVertex2f(1.00f, -1.00f);
    glVertex2f(1.00f, -0.91f);
    glVertex2f(-1.00f, -0.91f);
    glVertex2f(-1.00f, -1.00f);
    
    glEnd();
    
	// Road
    glColor3f(0.96f, 0.9f, 0.75f);
    glBegin(GL_POLYGON);

    glVertex2f(1.00f, -0.91f);
    glVertex2f(1.00f, -0.83f);
    glVertex2f(-1.00f, -0.83f);
    glVertex2f(-1.00f, -0.91f);

    glEnd();

    //Backgroud
	glBegin(GL_POLYGON);

    glColor3f(0.28f, 0.26f, 0.24f);
    glVertex2f(1.00f, -0.82f);

    glColor3f(0.45f, 0.41f, 0.36f);
    glVertex2f(1.00f, 1.00f);

    glColor3f(0.85f, 0.76f, 0.6f);
    glVertex2f(-1.00f, 1.00f);

    glColor3f(0.49f, 0.45f, 0.36f);
    glVertex2f(-1.00f, -0.82f);
    
    glEnd();

	drawCircle(0.66f, 0.86f, 0.25f, 0.62f, 0.56f, 0.45f); // Draw a black circle

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 576);
	glutInitWindowPosition(300, 300);
    glutCreateWindow("Graphics Introduction");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}