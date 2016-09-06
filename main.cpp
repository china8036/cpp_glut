#include <iostream>
#include <GL/glut.h>
#include <stdio.h>
#include "draw.h"
#include "key.h"

using namespace std;
using namespace key;
float angle=0.0;
float red=1.0, blue=1.0, green=1.0;
int margc;
char ** margv;

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //保存当前模型视图矩阵。
    glPushMatrix();

    glRotatef(angle,0.0,1.0,0.0);
    glColor3f(red,green,blue);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);
    glEnd();

    // 弹出堆栈
    glPopMatrix();

    // 交换缓冲区
    glutSwapBuffers();

    // 让angle自动增加。
    angle++;
}

void processSpecialKeys(int key, int x, int y)
{

    switch(key)
    {
    case GLUT_KEY_F1 :
        red = 1.0;
        green = 0.0;
        blue = 0.0;
        break;
    case GLUT_KEY_F2 :
        red = 0.0;
        green = 1.0;
        blue = 0.0;
        break;
    case GLUT_KEY_F3 :
        red = 0.0;
        green = 0.0;
        blue = 1.0;
        break;
    }
}

void processNormalKeys(unsigned char key, int x, int y)
{

    if (key == 27)
        exit(0);
    else if (key=='r')
    {
        int mod = glutGetModifiers();
        if (mod == GLUT_ACTIVE_ALT)
            red = 0.0;
        else
            red = 1.0;
    }
}

void thread()
{
    glutInit(&margc, margv);

    // 在这里设置双缓冲区。
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("3D Tech- GLUT Tutorial");
    glutDisplayFunc(renderScene);

    // 这里让程序空闲时调用renderScene，
    glutIdleFunc(renderScene);
    glutSpecialFunc(processSpecialKeys);
    //glutReshapeFunc(changeSize);

    //开启深度测试。
    //glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    k1 k;
    char *x = "hello world\n";
    k.say(x);
    // 在这里设置双缓冲区。
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("3D Tech- GLUT Tutorial");
    glutDisplayFunc(renderScene);

    // 这里让程序空闲时调用renderScene，
    glutIdleFunc(renderScene);
    glutSpecialFunc(processSpecialKeys);
    //glutReshapeFunc(changeSize);

    //开启深度测试。
    //glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
