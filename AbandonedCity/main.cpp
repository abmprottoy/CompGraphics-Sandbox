#include <Windows.h>
#include <math.h>
#include <GL/freeglut.h>

// Function to draw a filled circle
void drawCircle(float cx, float cy, float radius) {
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

// Function to draw a cloud at a given position and scale
void drawCloud(float x, float y, float scale) {
    // Scale factors for circle radii and positions
    float r1 = 0.2f * scale; // Radius for left circle
    float r2 = 0.3f * scale; // Radius for center circle
    float r3 = 0.2f * scale; // Radius for right circle
    float r4 = 0.15f * scale; // Radius for top bump

    // Draw overlapping circles to form the cloud
    drawCircle(x - 0.3f * scale, y + 0.3f * scale, r1); // Left part
    drawCircle(x, y + 0.3f * scale, r2);               // Center part
    drawCircle(x + 0.3f * scale, y + 0.3f * scale, r3); // Right part
    drawCircle(x + 0.15f * scale, y + 0.5f * scale, r4); // Top bump
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






// Function to display the output
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

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

    // Smoke
    glColor3f(0.71f, 0.65f, 0.53f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    drawCloud(0.77f, -0.9f, 1.0f);

    glColor3f(0.56f, 0.51f, 0.42f);
    drawCloud(0.77f, -0.9f, 0.75f);
    

	// Ground
    glColor3f(0.19f, 0.15f, 0.16f);
    glBegin(GL_QUADS);

    glVertex2f(1.00f, -1.00f);
    glVertex2f(1.00f, -0.80f);
    glVertex2f(-1.00f, -0.80f);
    glVertex2f(-1.00f, -1.00f);
    
    glEnd();
    
	// Ground 2
    glColor3f(0.5f, 0.46f, 0.38f);
    glBegin(GL_QUADS);

    glVertex2f(1.00f, -0.80f);
    glVertex2f(1.00f, -0.76f);
    glVertex2f(-1.00f, -0.76f);
    glVertex2f(-1.00f, -0.80f);

    glEnd();	
    
    // Road
    glColor3f(0.91f, 0.84f, 0.71f);
    glBegin(GL_QUADS);

    glVertex2f(1.00f, -0.76f);
    glVertex2f(1.00f, -0.70f);
    glVertex2f(-1.00f, -0.70f);
    glVertex2f(-1.00f, -0.76f);

    glEnd();

    // Truck

    // Bumper
    glColor3f(0.36f, 0.31f, 0.27f);
    glBegin(GL_QUADS);

    glVertex2f(0.24f, -0.70f);
    glVertex2f(0.24f, -0.68f);
    glVertex2f(0.19f, -0.68f);
    glVertex2f(0.19f, -0.70f);

    glEnd();

    //Front
    glColor3f(0.91f, 0.85f, 0.69f);
	glBegin(GL_POLYGON);

    glVertex2f(0.21f, -0.69f);
    glVertex2f(0.33f, -0.69f);
    glVertex2f(0.33f, -0.57f);
    glVertex2f(0.22f, -0.57f);
    glVertex2f(0.21f, -0.62f);
    glVertex2f(0.21f, -0.69f);

	glEnd();

	//Window
    glColor3f(0.13f, 0.09f, 0.13f);
	glBegin(GL_POLYGON);
    glVertex2f(0.23f, -0.58f);
    glVertex2f(0.27f, -0.58f);
    glVertex2f(0.27f, -0.62f);
    glVertex2f(0.22f, -0.62f);
	glEnd();

	glBegin(GL_POLYGON);
    glVertex2f(0.33f, -0.58f);
    glVertex2f(0.33f, -0.62f);
    glVertex2f(0.30f, -0.61f);
    glVertex2f(0.30f, -0.58f);
	glEnd();

    /// Tires
	/// Front Tire
    
    glColor3f(0.13f, 0.1f, 0.12f);
	drawCircle(0.28f, -0.69f, 0.04f);
    glColor3f(0.8f, 0.76f, 0.65f);
    drawCircle(0.28f, -0.69f, 0.030f);
    glColor3f(0.13f, 0.1f, 0.12f);
    drawCircle(0.28f, -0.69f, 0.020f);

	/// Back Tire
    glColor3f(0.13f, 0.1f, 0.12f);
    drawCircle(0.49f, -0.69f, 0.04f);
    glColor3f(0.8f, 0.76f, 0.65f);
    drawCircle(0.49f, -0.69f, 0.030f);
    glColor3f(0.13f, 0.1f, 0.12f);
    drawCircle(0.49f, -0.69f, 0.020f);

    glColor3f(0.13f, 0.1f, 0.12f);
    drawCircle(0.61f, -0.69f, 0.04f);
    glColor3f(0.8f, 0.76f, 0.65f);
    drawCircle(0.61f, -0.69f, 0.030f);
    glColor3f(0.13f, 0.1f, 0.12f);
    drawCircle(0.61f, -0.69f, 0.020f);




    glColor3f(0.74f, 0.67f, 0.54f); // Light gray color for the cloud
    // Draw clouds at different positions and scales
    drawCloud(-0.5f, 0.5f, 1.0f);  // Large cloud
    drawCloud(0.3f, 0.7f, 0.5f);   // Smaller cloud
    drawCloud(0.0f, 0.2f, 0.75f);  // Medium-sized cloud





    glColor3f(0.96f, 0.9f, 0.75f);
	drawCircle(0.66f, 0.86f, 0.25f); // Draw a black circle

    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
	glutInitWindowPosition(500, 100);
    glutCreateWindow("Graphics Introduction");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}