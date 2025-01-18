#include <Windows.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> circlePoints;

void storeSymmetricPoints(int xc, int yc, int x, int y) {
    circlePoints.push_back({ xc + x, yc + y });
    circlePoints.push_back({ xc - x, yc + y });
    circlePoints.push_back({ xc + x, yc - y });
    circlePoints.push_back({ xc - x, yc - y });
    circlePoints.push_back({ xc + y, yc + x });
    circlePoints.push_back({ xc - y, yc + x });
    circlePoints.push_back({ xc + y, yc - x });
    circlePoints.push_back({ xc - y, yc - x });
}


void calculateCirclePoints(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    storeSymmetricPoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        }
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        storeSymmetricPoints(xc, yc, x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);            

    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 0.0f);

    for (const auto& point : circlePoints) {
        glVertex2f(point.first, point.second);
    }

    glEnd();
    glFlush(); 
}

int main(int argc, char** argv) {
    int xc, yc, r;

    cout << "Enter the center of the circle (x, y) : ";
    cin >> xc >> yc;

    cout << "Enter the radius of the circle : ";
    cin >> r;

    calculateCirclePoints(xc, yc, r);


    cout << "Calculated Circle Points:\n";
    for (const auto& point : circlePoints) {
        cout << "(" << point.first << ", " << point.second << ")\n";
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    glutDisplayFunc(display); 
    glutMainLoop();           

    return 0;
}
