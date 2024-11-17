#include <Windows.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>

using namespace std;

 
vector<pair<float, float>> linePoints;


void calculateDDALine(int x1, int y1, int x2, int y2) {

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    }
    else {
        steps = abs(dy);
    }


    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    // Initial point
    float x = x1;
    float y = y1;

    // Store the first point
    linePoints.push_back({ x, y });

    // Calculate points and store them
    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        linePoints.push_back({ x, y });
        cout << "Point " << i + 1 << ": (" << x << ", " << y << ")" << endl;
    }
}

void display() {
    glClearColor(0.0f, 0.48f, 0.8f, 0.0f); // Set the background color
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glPointSize(10.0); // Set the point size to 10 pixels
    glLineWidth(1.0); // Set the line width to 5 pixels

    glBegin(GL_POINTS);

    glColor3f(0.0f, 1.0f, 0.0f);
    for (size_t i = 0; i < linePoints.size(); ++i) {
        glVertex2f((float)(linePoints[i].first), (float)(linePoints[i].second));
    }
	glVertex2f(11.0f, 15.07f);

    glEnd(); 
    glFlush(); 
}

int main(int argc, char** argv) {
    int x1, y1, x2, y2;
    cout << "Enter the coordinates of the two points : " << endl;
    cout << "Value of x in first pair : ";
    cin >> x1;
    cout << "Value of y in first pair : ";
    cin >> y1;
    cout << "Value of x in second pair : ";
    cin >> x2;
    cout << "Value of y in second pair : ";
    cin >> y2;

    
    calculateDDALine(x1, y1, x2, y2);

    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA Line Drawing");
    glutDisplayFunc(display); 

    glutMainLoop(); 

    return 0;
}
