#include <bits/stdc++.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include<mmsystem.h>
#define ESCAPE 27
using namespace std;

char name3[]=" PROJECT:  3D CAR  RACING ";
int view=0;
int color=1;
static bool pause;
static int newspeed;
GLint window;
float mainCarx=0.3;
float mainCary=0;
float firstDividerx=.41;
float firstDividery=.75;
float secondDividerx=.59;
float secondDividery=.75;

float enemyLocationy=.75;
 float lavelTime=0;
 float templavelTime=0;
 int speed=60;
static int point=0;
int viewCarTime=0;

float randomRoadX[]={.29,.455,.625};
float randomRoadX2[2];
float LocationX=.29;
float LocationX2=.455;

int score=0;
bool clash=false;
bool night= false;
bool light= false;
//divider

float   dy1=.75,
 dy2=.75-.1,
 dy3=.75-.2,
 dy4=.75-.3,
 dy5=.75-.4,
 dy6=.75-.5,
 dy7=.75-.6,
 dy8=.75-.7;

//float runDivider=0;

float treeX=.0;
float treeY=.0;

//sun
float sunX=.20;
float sunY=.90;

//cloud

 float move_cloud = 0;
 float move_cloud2 = .30;

//tree

float
Tdy1=.75,
 Tdy2=.75-.1,
 Tdy3=.75-.2,
 Tdy4=.75-.3,
 Tdy5=.75-.4,
 Tdy6=.75-.5,
 Tdy7=.75-.6,
 Tdy8=.75-.7;



void drawStar();
void drawMoon();
void cloud();
void cloud2();
void drawSun(void);
void drawScore(void * font, char *s, int point, float x, float y);

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
void init(void)
{
/* select clearing (background) color */
glClearColor(0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(0.0,1,0.0,1);



}



void DrawTree(float x, float y)  //x=.10  y=.50
{
    glPushMatrix();

    //glRotatef(40, 1.0, 0.0, 0.0);
   glTranslatef(x, y, 0.0);

  glRotatef(-10, 1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)






    glPushMatrix();

    glColor3f(0.647059, .13,.15);
    glPushMatrix();
      glTranslatef(0, -.07, 0.0);
    glutSolidCube(.03);
    glPopMatrix();









    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
     glTranslatef(0,0, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)

  //  glColor3f(1.0, 0.0, 1.0);
    glutSolidCone(.05,.12,25,25);
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
     glTranslatef(0,-.04, 0.0);
    glRotatef(-90, 1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)

  //  glColor3f(1.0, 0.0, 1.0);
    glutSolidCone(.05,.08,25,25);
    glPopMatrix();




    glPopMatrix();


}



void drawLamp(float x, float y);
void dawRoad(void)
{

glBegin(GL_QUADS); //left side road

glColor3f(.8823529, .537254, .2588235);//(R,G,B)

glVertex3f(0, 0, 0.0);
glVertex3f(.25, 0.0, 0.0);
glVertex3f(.25, .77, 0.0);
glVertex3f(0, .77, 0.0);


glEnd();


//DrawTree(treeX,td);
//DrawTree(treeX+.04,Tdy3);
////DrawTree(treeX+.04,Tdy3);
//DrawTree(treeX+.01,Tdy1);
////DrawTree(treeX+.04,treeY+.30);
//DrawTree(treeX,treeY);

//DrawTree(treeX+.04,Tdy3);
//DrawTree(treeX+.93,Tdy3);

//glBegin(GL_LINES); //Left House Border.
//
//glColor3f(0.0, 0.0, 0.0);//(R,G,B)
//glVertex3f(0.0, 0.5, 0.0);
//glVertex3f(.25, 1, 0.0);
//
//
//glEnd();



//glBegin(GL_POLYGON); //Left House Window 1
//
//glColor3f(.0, .0, 0.0);//(R,G,B)
//
//glVertex3f(0.2, 0.8, 0.0);
//glVertex3f(0.2, .7, 0.0);
//glVertex3f(.23, .8, 0.0);
//glVertex3f(.23, .89, 0.0);
//
//
//
//glEnd();






glBegin(GL_QUADS); //Right side road

glColor3f(.8823529, .537254, .2588235);//(R,G,B)

glVertex3f(.76, 0, 0.0);
glVertex3f(1, 0.0, 0.0);
glVertex3f(1, .77, 0.0);
glVertex3f(.76, .77, 0.0);


glEnd();
//
//DrawTree(treeX+.04,Tdy3);
////DrawTree(treeX+.04,Tdy3);
//DrawTree(treeX+.01,Tdy1);
////DrawTree(treeX+.04,treeY+.30)
////DrawTree(treeX+.95,Tdy1);
//DrawTree(treeX+.95,Tdy3);
//DrawTree(treeX+.95,Tdy6);


glBegin(GL_POLYGON); //Main road

glColor3f(.25, .25, 0.25);//(R,G,B)

glVertex3f(0.0, 0.0, 0.0);
glVertex3f(1.0, 0, 0.0);
glVertex3f(.76, .76, 0.0);
glVertex3f(.25, .76, 0.0);

glEnd();

//first Road Mark


float
 x=firstDividerx;

glBegin(GL_QUADS);

glColor3f(1, 1, 1);//(R,G,B)
glVertex3f(x, dy1, 0.0);
glVertex3f(x+.005, dy1, 0.0);
glVertex3f(x+.005, dy1-0-0.02, 0.0);
glVertex3f(x, dy1-0-0.02, 0.0);


glVertex3f(x, dy2, 0.0);
glVertex3f(x+.005, dy2, 0.0);
glVertex3f(x+.005, dy2-0-0.02, 0.0);
glVertex3f(x, dy2-0-0.02, 0.0);




glVertex3f(x, dy3, 0.0);
glVertex3f(x+.005, dy3, 0.0);
glVertex3f(x+.005, dy3-0-0.02, 0.0);
glVertex3f(x, dy3-0-0.02, 0.0);




glVertex3f(x, dy4, 0.0);
glVertex3f(x+.005, dy4, 0.0);
glVertex3f(x+.005, dy4-0-0.02, 0.0);
glVertex3f(x, dy4-0-0.02, 0.0);


glVertex3f(x, dy5, 0.0);
glVertex3f(x+.005, dy5, 0.0);
glVertex3f(x+.005, dy5-0-0.02, 0.0);
glVertex3f(x, dy5-0-0.02, 0.0);




glVertex3f(x, dy6, 0.0);
glVertex3f(x+.005, dy6, 0.0);
glVertex3f(x+.005, dy6-0-0.02, 0.0);
glVertex3f(x, dy6-0-0.02, 0.0);



glVertex3f(x, dy7, 0.0);
glVertex3f(x+.005, dy7, 0.0);
glVertex3f(x+.005, dy7-0-0.02, 0.0);
glVertex3f(x, dy7-0-0.02, 0.0);




glVertex3f(x, dy8, 0.0);
glVertex3f(x+.005, dy8, 0.0);
glVertex3f(x+.005, dy8-0-0.02, 0.0);
glVertex3f(x, dy8-0-0.02, 0.0);




glEnd();



//Second Road Mark

 x=secondDividerx;


glBegin(GL_QUADS);

glColor3f(1, 1, 1);//(R,G,B)
glVertex3f(x, dy1, 0.0);
glVertex3f(x+.005, dy1, 0.0);
glVertex3f(x+.005, dy1-0-0.02, 0.0);
glVertex3f(x, dy1-0-0.02, 0.0);


glVertex3f(x, dy2, 0.0);
glVertex3f(x+.005, dy2, 0.0);
glVertex3f(x+.005, dy2-0-0.02, 0.0);
glVertex3f(x, dy2-0-0.02, 0.0);




glVertex3f(x, dy3, 0.0);
glVertex3f(x+.005, dy3, 0.0);
glVertex3f(x+.005, dy3-0-0.02, 0.0);
glVertex3f(x, dy3-0-0.02, 0.0);




glVertex3f(x, dy4, 0.0);
glVertex3f(x+.005, dy4, 0.0);
glVertex3f(x+.005, dy4-0-0.02, 0.0);
glVertex3f(x, dy4-0-0.02, 0.0);


glVertex3f(x, dy5, 0.0);
glVertex3f(x+.005, dy5, 0.0);
glVertex3f(x+.005, dy5-0-0.02, 0.0);
glVertex3f(x, dy5-0-0.02, 0.0);




glVertex3f(x, dy6, 0.0);
glVertex3f(x+.005, dy6, 0.0);
glVertex3f(x+.005, dy6-0-0.02, 0.0);
glVertex3f(x, dy6-0-0.02, 0.0);



glVertex3f(x, dy7, 0.0);
glVertex3f(x+.005, dy7, 0.0);
glVertex3f(x+.005, dy7-0-0.02, 0.0);
glVertex3f(x, dy7-0-0.02, 0.0);




glVertex3f(x, dy8, 0.0);
glVertex3f(x+.005, dy8, 0.0);
glVertex3f(x+.005, dy8-0-0.02, 0.0);
glVertex3f(x, dy8-0-0.02, 0.0);




glEnd();




}


void dawYourCar(int color)
{

//    sndPlaySound("GPHORSEpower.wav",SND_ASYNC);

    float colorx,colory,colorz;
    float bckColorx,bckColory,bckColorz;
    if(color==1)
    {
        bckColorx=0.1;
        bckColory=0.1;
        bckColorz=1.0;

        colorx=0.0,
        colory=0.0;
        colorz=1.0;
    }
        if(color==2)
    {
        bckColorx=0.1;
        bckColory=1.0;
        bckColorz=0.1;

        colorx=0.0,
        colory=1.0;
        colorz=0.0;
    }
            if(color==3)
    {
        bckColorx=1.0;
        bckColory=0.1;
        bckColorz=0.1;

        colorx=1.0,
        colory=0.0;
        colorz=0.0;
    }

    if(color==4)
    {
        bckColorx=0.0;
        bckColory=0.0;
        bckColorz=0.0;

        colorx=0.5,
        colory=0.5;
        colorz=0.5;
    }

 glPushMatrix();
glTranslatef(mainCarx, mainCary, 0.0); //Move forward 5 units

    float x=0, y=0;

glBegin(GL_POLYGON);//Body Back Create

    glColor3f(bckColorx, bckColory, bckColorz);//(R,G,B)

    glVertex3f(x-.01, y-.01, 0.0);
    glVertex3f(x+.09, y-.01, 0.0);
    glVertex3f(x+.09, y+.03, 0.0);
    glVertex3f(x-.01, y+.03, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Back Light Left

    glColor3f(1.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.01, 0.0);
    glVertex3f(x+.01, y+.01, 0.0);
    glVertex3f(x+.01, y+.02, 0.0);
    glVertex3f(x-.01, y+.02, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Back Light Right

    glColor3f(1.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.07, y+.01, 0.0);
    glVertex3f(x+.09, y+.01, 0.0);
    glVertex3f(x+.09, y+.02, 0.0);
    glVertex3f(x+.07, y+.02, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Wheel left up

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.07, 0.0);
    glVertex3f(x, y+.07, 0.0);
    glVertex3f(x, y+.09, 0.0);
    glVertex3f(x-.01, y+.09, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Wheel Right up

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.08, y+.07, 0.0);
    glVertex3f(x+.09, y+.07, 0.0);
    glVertex3f(x+.09, y+.09, 0.0);
    glVertex3f(x+.08, y+.09, 0.0);
glEnd();
glBegin(GL_POLYGON);//Body  Create

    glColor3f(colorx, colory, colorz);//(R,G,B)

    glVertex3f(x-.01, y+.03, 0.0);
    glVertex3f(x+.09, y+.03, 0.0);
    glVertex3f(x+.08, y+.13, 0.0);
    glVertex3f(x, y+.13, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Back Glass Create

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.015, y+.03, 0.0);
    glVertex3f(x+.065, y+.03, 0.0);
    glVertex3f(x+.065, y+.1, 0.0);
    glVertex3f(x+.015, y+.1, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Back left Glass Create

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x, y+.06, 0.0);
    glVertex3f(x+.008, y+.06, 0.0);
    glVertex3f(x+.008, y+.08, 0.0);
    glVertex3f(x, y+.08, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Back right Glass Create

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.07, y+.06, 0.0);
    glVertex3f(x+.078, y+.06, 0.0);
    glVertex3f(x+.078, y+.08, 0.0);
    glVertex3f(x+.07, y+.08, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Left looking Glass Create

    glColor3f(colorx, colory, colorz);//(R,G,B)

    glVertex3f(x-.014, y+.09, 0.0);
    glVertex3f(x, y+.09, 0.0);
    glVertex3f(x, y+.10, 0.0);
    glVertex3f(x-.014, y+.10, 0.0);

glEnd();

glBegin(GL_POLYGON);//Body Right looking Glass Create

    glColor3f(colorx, colory, colorz);//(R,G,B)

    glVertex3f(x+.08, y+.09, 0.0);
    glVertex3f(x+.094, y+.09, 0.0);
    glVertex3f(x+.094, y+.10, 0.0);
    glVertex3f(x+.08, y+.10, 0.0);

glEnd();



glBegin(GL_POLYGON);//Body Wheel left Down

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.02, 0.0);
    glVertex3f(x-.015, y+.02, 0.0);
    glVertex3f(x-.015, y+0.0, 0.0);
    glVertex3f(x-.01, y+0.0, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Wheel Right Down

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.09, y+.02, 0.0);
    glVertex3f(x+.09, y+0.0, 0.0);
    glVertex3f(x+.095, y+0.0, 0.0);
    glVertex3f(x+.095, y+.02, 0.0);
glEnd();



glPopMatrix();
}


void dawEnemyCar(void)
{
 glPushMatrix();
float dy=enemyLocationy;
glTranslatef(LocationX,dy-=.01 , 0.0); //Move forward 5 units
glRotatef(180, 1.0, 0.0, 0.0);
    float x=0, y=0;
glBegin(GL_POLYGON);//Bonutt create

glBegin(GL_POLYGON);//Bonutt create

    glColor3f(1.0, 0.0, 0.0);//(R,G,B)

     glVertex3f(x-.01, y+.09, 0.0);
     glVertex3f(x+.09, y+.09, 0.0);
     glVertex3f(x+.08, y+.13, 0.0);
     glVertex3f(x, y+.13, 0.0);

glEnd();




glBegin(GL_POLYGON);//Body Create

    glColor3f(1.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y-.01, 0.0);
    glVertex3f(x+.09, y-.01, 0.0);
    glVertex3f(x+.09, y+.09, 0.0);
    glVertex3f(x-.01, y+.09, 0.0);

glEnd();


glBegin(GL_POLYGON);//Body Wheel left up

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.09, 0.0);
    glVertex3f(x-.015, y+.09, 0.0);
    glVertex3f(x-.015, y+.07, 0.0);
    glVertex3f(x-.01, y+.07, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Wheel Right up

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.09, y+.09, 0.0);
    glVertex3f(x+.09, y+.07, 0.0);
    glVertex3f(x+.095, y+.07, 0.0);
    glVertex3f(x+.095, y+.09, 0.0);
glEnd();
glBegin(GL_POLYGON);//Body Wheel left Down

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.02, 0.0);
    glVertex3f(x-.015, y+.02, 0.0);
    glVertex3f(x-.015, y+0.0, 0.0);
    glVertex3f(x-.01, y+0.0, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Wheel Right Down

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.09, y+.02, 0.0);
    glVertex3f(x+.09, y+0.0, 0.0);
    glVertex3f(x+.095, y+0.0, 0.0);
    glVertex3f(x+.095, y+.02, 0.0);
glEnd();




glBegin(GL_POLYGON);//window Create

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x, y, 0.0);
    glVertex3f(x+.08, y, 0.0);
    glVertex3f(x+.08, y+.08, 0.0);
    glVertex3f(x, y+.08, 0.0);

glEnd();


glBegin(GL_POLYGON);//Roof Create

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.02, y+.02, 0.0);
glVertex3f(x+.06, y+.02, 0.0);
glVertex3f(x+.06, y+.06, 0.0);
glVertex3f(x+.02, y+.06, 0.0);

glEnd();

glBegin(GL_LINES);//Roof Right Down

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.06, y+.02, 0.0);
 glVertex3f(x+.08, y, 0.0);

glEnd();


glBegin(GL_LINES);//Roof Left Down

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.02, y+.02, 0.0);
 glVertex3f(x, y, 0.0);

glEnd();

glBegin(GL_LINES);//Roof Right UP

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.06, y+.06, 0.0);
 glVertex3f(x+.08, y+.08, 0.0);

glEnd();
glBegin(GL_LINES);//Roof Left UP
glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.02, y+.06, 0.0);
glVertex3f(x, y+.08, 0.0);

glEnd();

glPopMatrix();
}


void dawEnemyCar2(void)
{
 glPushMatrix();
float dy=enemyLocationy;
glTranslatef(LocationX2,dy-=.01 , 0.0); //Move forward 5 units
glRotatef(180, 1.0, 0.0, 0.0);
    float x=0, y=0;
glBegin(GL_POLYGON);//Bonutt create

glBegin(GL_POLYGON);//Bonutt create

    glColor3f(1.0, 0.0, 0.0);//(R,G,B)

     glVertex3f(x-.01, y+.09, 0.0);
     glVertex3f(x+.09, y+.09, 0.0);
     glVertex3f(x+.08, y+.13, 0.0);
     glVertex3f(x, y+.13, 0.0);

glEnd();




glBegin(GL_POLYGON);//Body Create

    glColor3f(1.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y-.01, 0.0);
    glVertex3f(x+.09, y-.01, 0.0);
    glVertex3f(x+.09, y+.09, 0.0);
    glVertex3f(x-.01, y+.09, 0.0);

glEnd();


glBegin(GL_POLYGON);//Body Wheel left up

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.09, 0.0);
    glVertex3f(x-.015, y+.09, 0.0);
    glVertex3f(x-.015, y+.07, 0.0);
    glVertex3f(x-.01, y+.07, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Wheel Right up

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.09, y+.09, 0.0);
    glVertex3f(x+.09, y+.07, 0.0);
    glVertex3f(x+.095, y+.07, 0.0);
    glVertex3f(x+.095, y+.09, 0.0);
glEnd();
glBegin(GL_POLYGON);//Body Wheel left Down

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x-.01, y+.02, 0.0);
    glVertex3f(x-.015, y+.02, 0.0);
    glVertex3f(x-.015, y+0.0, 0.0);
    glVertex3f(x-.01, y+0.0, 0.0);

glEnd();
glBegin(GL_POLYGON);//Body Wheel Right Down

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x+.09, y+.02, 0.0);
    glVertex3f(x+.09, y+0.0, 0.0);
    glVertex3f(x+.095, y+0.0, 0.0);
    glVertex3f(x+.095, y+.02, 0.0);
glEnd();




glBegin(GL_POLYGON);//window Create

    glColor3f(0.0, 0.0, 0.0);//(R,G,B)

    glVertex3f(x, y, 0.0);
    glVertex3f(x+.08, y, 0.0);
    glVertex3f(x+.08, y+.08, 0.0);
    glVertex3f(x, y+.08, 0.0);

glEnd();


glBegin(GL_POLYGON);//Roof Create

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.02, y+.02, 0.0);
glVertex3f(x+.06, y+.02, 0.0);
glVertex3f(x+.06, y+.06, 0.0);
glVertex3f(x+.02, y+.06, 0.0);

glEnd();

glBegin(GL_LINES);//Roof Right Down

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.06, y+.02, 0.0);
 glVertex3f(x+.08, y, 0.0);

glEnd();


glBegin(GL_LINES);//Roof Left Down

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.02, y+.02, 0.0);
 glVertex3f(x, y, 0.0);

glEnd();

glBegin(GL_LINES);//Roof Right UP

glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.06, y+.06, 0.0);
 glVertex3f(x+.08, y+.08, 0.0);

glEnd();
glBegin(GL_LINES);//Roof Left UP
glColor3f(1.5, 0.0, 0.0);//(R,G,B)

glVertex3f(x+.02, y+.06, 0.0);
glVertex3f(x, y+.08, 0.0);

glEnd();

glPopMatrix();
}

void display_string(float x, float y, char *string, int font)
{
    int len,i;
	glColor3f(0,0,0);
	glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
    if(font==1)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
	if(font==2)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	if(font==3)
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
	if(font==4)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,string[i]);
	}

}
void display1(void)
{
	glClearColor(1.0,0.0,0.0,1.0);
	display_string(0.2,0.9,"American International University Bangladesh",1); //correct cordinate according to name
	display_string(0.2,0.8,name3,1);
	display_string(0.2,0.7,"HELP",2);
	display_string(0.2,0.6,"MOUSE :",2);
	display_string(0.2,0.5,"PRESS RIGHT BUTTON FOR MENU",3);
	display_string(0.2,0.4,"KEYBOARD :",2);
	display_string(0.2,0.3,"USE LEFT ARROW(<-) AND RIGHT ARROW(->),UP KEY ^ AND DOWN KEY  TO MOVE CAR ",3);
	display_string(0.2,0.25,"L TO LIGHTPOST LIGHT AND O TO OFF THE LIGHT",3);
	display_string(0.2,0.2,"ESCAPE TO EXIT SPACE BAR TO PAUSE ",3);
	display_string(0.2,0.15,"n & d to CHANGE ENVIRONMENT ",3);
    display_string(0.2,0.1,"c to SWEEP CAR COLOR",3);
	display_string(0.5,0.05,"PRESS --> g  TO ENTER THE RACE ",2);
	glutPostRedisplay();
	glutSwapBuffers();


}

void display2(void)
{
    drawScore(GLUT_BITMAP_TIMES_ROMAN_24, "SCORE :: ",point,0.3,0.8);

    display_string(0.3,0.6,"BETTER LUCK NEXT TIME ",2);


}
void nightMode(){

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


if(night==true && light==true)
glColor4f(.0, .0, 0.0, .3);
else if(night==true)
glColor4f(.0, .0, 0.0, .7);
else glColor4f(.0, .0, 0.0, 0);
glBegin(GL_QUADS);
glVertex3f(.0, .0, 0.0); // top left
glVertex3f(1.0, .0, 0.0); // bottom left
glVertex3f(1.0, 1.0, 0.0); // bottom right
glVertex3f(.0, 1.0, 0.0); // top right
glEnd();
if(night==true)
{
drawMoon();
drawStar();

}
else
{
cloud();
drawSun();
cloud2();
}


}
void drawCircle(GLfloat x, GLfloat y, GLfloat radius, string type)
{
int i;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * 3.1416;

glEnable(GL_LINE_SMOOTH);
glLineWidth(5.0);

glBegin(GL_LINES);
if(type=="sun")
glColor4f(1.0, 1.0, 0.0, 1.0);
else if(type=="star")
glColor3f(1.0, 1.0, 1.0);
else if(type=="black")
glColor3f(0.0, 0.0, 0.0);
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( x, y);
glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
}
glEnd();
}
void drawMoon(void)
{
    drawCircle(.80,.90,.05,"star");
    drawCircle(.750,.95,.08,"black");

}


void drawStar(void)
{
    //drawCircle(.10,.9,.001,"star");
    glBegin(GL_POINTS);

glColor3f(1.0, 1.0, 1.0);
   glVertex3f(.10, .910, 0.0);
   glVertex3f(.20, .920, 0.0);
   glVertex3f(.40, .930, 0.0);
   glVertex3f(.50, .9390, 0.0);
   glVertex3f(.20, .8790, 0.0);
   glVertex3f(.50, .8890, 0.0);
   glVertex3f(.550, .8590, 0.0);
   glVertex3f(.880, .7990, 0.0);
   glVertex3f(.9970, .8690, 0.0);
   glVertex3f(.760, .890, 0.0);
   glVertex3f(.870, .990, 0.0);
   glVertex3f(.90, .790, 0.0);
   glVertex3f(.450, .890, 0.0);
   glVertex3f(.1780, .9930, 0.0);
   glVertex3f(.14560, .8920, 0.0);
   glVertex3f(.19870, .86910, 0.0);
   glVertex3f(.6750, .810, 0.0);
   glVertex3f(.560, .830, 0.0);
   glVertex3f(.3450, .820, 0.0);
   glVertex3f(.64560, .870, 0.0);
   glVertex3f(.7810, .80, 0.0);




   glVertex3f(.10, .810, 0.0);
   //glVertex3f(.20, .720, 0.0);
   glVertex3f(.40, .7530, 0.0);
   glVertex3f(.50, .78390, 0.0);
   glVertex3f(.20, .9790, 0.0);
   glVertex3f(.50, .76890, 0.0);
   glVertex3f(.550, .78590, 0.0);
   glVertex3f(.880, .7990, 0.0);
   glVertex3f(.9970, .768690, 0.0);
   glVertex3f(.760, .79890, 0.0);
   glVertex3f(.870, .7990, 0.0);
   glVertex3f(.90, .790, 0.0);
   glVertex3f(.450, .7890, 0.0);
   glVertex3f(.1780, .79930, 0.0);
   glVertex3f(.14560, .78920, 0.0);
   glVertex3f(.19870, .786910, 0.0);
   glVertex3f(.6750, .7810, 0.0);
   glVertex3f(.560, .7830, 0.0);
   glVertex3f(.3450, .7820, 0.0);
   glVertex3f(.64560, .7870, 0.0);
   glVertex3f(.7810, .780, 0.0);

    glEnd();
}




//draw_score_function
void drawScore(void * font, char *s, int point, float x, float y){
     glRasterPos2f(x, y);
	 glColor3f(1.0, 1.0, 1.0);

     for (int i = 0; i < strlen (s); i++)
          glutBitmapCharacter (font, s[i]);
     int temp = point;
     int countArr=0;
     int pointArr[5];
     while(temp > 9)
     {
        pointArr[countArr] = temp%10;
        temp /= 10;
        countArr++;
     }
     pointArr[countArr] = temp%10;
     countArr++;
     for(int i = countArr; i>=0; i--){
        glutBitmapCharacter(font,48+ (pointArr[i]));
     }
}


void DrawBackGround()
{
    glBegin(GL_POLYGON);//Body Back Create
if(night==false)
    glColor3f(0.196078, 0.6, 0.8);//(R,G,B)
else if (night==true)
    glColor3f(0, 0, 0);

    glVertex3f(0, 0, 0.0);
    glVertex3f(2, 0, 0.0);
    glVertex3f(2, 2, 0.0);
    glVertex3f(0, 2, 0.0);

glEnd();

}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
int i;
int triangleAmount = 1000;
GLfloat twicePi = 2.0f * 3.1416;

glEnable(GL_LINE_SMOOTH);
glLineWidth(5.0);

glBegin(GL_LINES);
glColor4f(1.0, 1.0, 0.0, 1.0);
for(i = 0; i <= triangleAmount; i++)
{
glVertex2f( x, y);
glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
}
glEnd();
}


void drawSun(void)
{
    if(night==false)
    drawCircle(sunX,sunY,.05);
}

void cloud(){
    ///right cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.0+move_cloud,0.875,0.35);
    glutSolidSphere(.06,20,5);
    glPopMatrix();

    ///bottom cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.08+move_cloud,0.85,0.35);

    glutSolidSphere(.07,20,5);
    glPopMatrix();


    ///above cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.08+move_cloud,0.9,0.35);

    glutSolidSphere(.07,20,5);
    glPopMatrix();

    ///left cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.15+move_cloud,0.85,0.35);

    glutSolidSphere(0.06,20,5); //(GLdouble radius,GLint slices, GLint stacks);
    glPopMatrix();

}

void cloud2(){

    ///right cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.0+move_cloud2,0.855,0.35);
    glutSolidSphere(.06,20,5);
    glPopMatrix();

    ///bottom cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.08+move_cloud2,0.83,0.35);

    glutSolidSphere(.07,20,5);
    glPopMatrix();


    ///above cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.08+move_cloud2,0.85,0.35);

    glutSolidSphere(.06,20,5);
    glPopMatrix();

    ///left cloud
    glPushMatrix();
    glColor3f(.90,.90,.90);
    glTranslatef(0.15+move_cloud2,0.830,0.35);

    glutSolidSphere(0.05,20,5); //(GLdouble radius,GLint slices, GLint stacks);
    glPopMatrix();
}

void drawLamp( float x, float y)
{
    glPushMatrix();
     glTranslatef(x,y-.2,0);
glColor3f(0.647059, .13,.15);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(.01,0,0);
    glVertex3f(.01,.10,0);
    glVertex3f(0,0.10,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(.00,.10,0);
    glVertex3f(.07,.10,0);
    glVertex3f(.07,.11,0);
    glVertex3f(0.00,0.11,0);
    glEnd();


    drawCircle(.07,.07,.01);

    glBegin(GL_POLYGON);

glColor3f(0.647059, .13,.15);
    glVertex3f(.07,.11,0);
    glVertex3f(.04,.07,0);
    glVertex3f(.10,.07,0);
    glEnd();


    glPopMatrix();

}


void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
if(view==0)
{
init();
display1();
}
else if(view==1)
{


glPushMatrix();
glRotatef(40, 1.0, 0.0, 0.0); //Rotate about the the vector (1, 2, 3)
DrawBackGround();
dawRoad();
dawYourCar(color);
dawEnemyCar();
dawEnemyCar2();

DrawTree(treeX+.04,Tdy3);
//DrawTree(treeX+.04,Tdy3);
DrawTree(treeX+.01,Tdy1);
//DrawTree(treeX+.04,treeY+.30)
//DrawTree(treeX+.95,Tdy1);
DrawTree(treeX+.95,Tdy3);
DrawTree(treeX+.95,Tdy6);

////DrawTree(treeX,treeY+.60);
//DrawTree(treeX+.04,Tdy1);
////DrawTree(treeX+.04,Tdy3);
//DrawTree(treeX+.01,Tdy3);
////DrawTree(treeX+.04,treeY+.30);
////DrawTree(treeX,treeY);
//
//DrawTree(treeX+.95,Tdy1);
////DrawTree(treeX+.04,Tdy3);
////DrawTree(treeX+.93,Tdy3);

glPopMatrix();

glPushMatrix();
//score = score + 10;
   glColor3f(1,1,1);
   //string v="Score::  "+int_to_str(score);
 //  glTranslatef(-3.2,1.7, 0.0);
        drawScore(GLUT_BITMAP_TIMES_ROMAN_24, "Score :: ",point,0.8,0.8);

    glPopMatrix();

if(clash==true){

            PlaySound(TEXT("Sound Of Tires .wav"),NULL,SND_SYNC);

       cout<<"..........................GAME OVER..................\n "<<"\n";
	          view=2;
	          display2();
            glutPostRedisplay();
}

nightMode();


drawLamp(.23,dy1);
//drawLamp(.23,dy3);
//drawLamp(.23,dy6);
//glRotatef(-90, 0.0, 1.0, 0.0); //Rotate about the the vector (1, 2, 3)

//glPushMatrix();

//glRotatef(-90, 1.0, .0, 0.0); //Rotate about the the vector (1, 2, 3)
//drawLamp(.73);
//glPopMatrix();

//sndPlaySound("GPHORSEpower.wav",SND_ASYNC);

}
else if(view==2)
{
       display2();
}
glFlush();
}


void myMenu(int id)
{


	if(id==3)
	{

		glutPostRedisplay();
	}


       if(id==1)
	{
        night=false;
	glutPostRedisplay();
	}

	if(id==2)
	{
	 night=true;
  glutPostRedisplay();
       }
}
void colorMenu(int id)
{


    if(id==1)
    {
        color=1;
    }
    if(id==2)
    {
        color=2;
    }
    if(id==3)
    {
        color=3;
    }

    if(id==4)
    {
        color=4;
    }
}


void Specialkey(int key, int x, int y)//allow to use navigation key for movement of car
{
    //cout<<key<<"\n"<<x<<"\n"<<y<<"\n";
switch(key)
{
case GLUT_KEY_UP:
    if (mainCary>=.55) break;
    else  mainCary=mainCary+.01;
             break;
case GLUT_KEY_DOWN:
    if (mainCary<=0) mainCary=0;
    else
    mainCary=mainCary-.01;
             break;
case GLUT_KEY_LEFT:
    if (mainCarx<.445) mainCarx=.285;
    else
    mainCarx=mainCarx-.17;
             break;
case GLUT_KEY_RIGHT:
     if (mainCarx>.445) mainCarx=.625;
    else
    mainCarx=mainCarx+.17;
             break;



}

//glutPostRe()display();
}


void make_randomRoadX2(float x){
    int n=2;
    for (int i =0;i<2;i++)
    {

    if(randomRoadX[n]!=x)
        randomRoadX2[i]=randomRoadX[n];

    n--;
    }
}

void update(int value) {
//
//treeX=-0.01;
//if(treeX>-0.03)treeX=0;
//cout<<treeX<<"\n"<<treeY;

if(view==1)
{

move_cloud+=.002;
move_cloud2+=.001;
if(move_cloud>1)  move_cloud=-0.2;
if(move_cloud2>1)  move_cloud2=-0.2;
lavelTime+=.2;
if(speed<=15) speed=15;
else if(lavelTime>=templavelTime+5)
{  dawEnemyCar();
    templavelTime=lavelTime;
    speed=speed-5;
//    shuffle(*randomRoadX, 3);

}



if(dy1<0)  dy1=.77;
dy1-=.02;
if(dy2<0)  dy2=.77;
dy2-=.02;
if(dy3<0)  dy3=.77;
dy3-=.02;
if(dy4<0)  dy4=.77;
dy4-=.02;
if(dy5<0)  dy5=.77;
dy5-=.02;
if(dy6<0)  dy6=.77;
dy6-=.02;
if(dy7<0)  dy7=.77;
dy7-=.02;
if(dy8<0)  dy8=.77;
dy8-=.02;




if(Tdy1<.3)  Tdy1=.77;
Tdy1-=.005;
if(Tdy2<.3)  Tdy2=.77;
dy2-=.005;
if(Tdy3<.3)  Tdy3=.77;
Tdy3-=.005;
if(Tdy4<.3)  Tdy4=.77;
Tdy4-=.005;
if(Tdy5<.3)  Tdy5=.77;
Tdy5-=.02;
if(Tdy6<.3)  Tdy6=.77;
Tdy6-=.005;
if(Tdy7<.3)  Tdy7=.77;
Tdy7-=.005;
if(Tdy8<0.3)  Tdy8=.77;
Tdy8-=.02;






point++;
if(mainCary>= enemyLocationy-.28 && mainCary<= enemyLocationy-.001 )
{

    if(mainCarx>=LocationX-.03 && mainCarx<=LocationX+.03  )
  clash=true;
    if(mainCarx>=LocationX2-.03 && mainCarx<=LocationX2+.03)
  clash=true;

}

     viewCarTime+=1;
    // cout<< viewCarTime<<"\n";
     //cout<< enemyLocationy<<"\n";
     //cout<< mainCary<<"\n";
//lavelTime+=.2;

enemyLocationy-=.01;
if(enemyLocationy<0) enemyLocationy=.75;


if(viewCarTime%76==0){

    LocationX= randomRoadX[rand()% 3];

    make_randomRoadX2(LocationX);
    LocationX2= randomRoadX2[rand()% 2];
}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds

	//cout<<speed<<"\n";
	glutTimerFunc(speed, update, 0);

}
}
void NormalKey(GLubyte key, GLint x, GLint y)
{
   switch(key){
     case ESCAPE : cout<<"escape pressed. exit.\n";
      cout<<"GAME OVER..................\n YOUR SCORE::::  "<<point<<"\n";
	               exit(0);
                    break;
     case ' ':
         //system("pause>null");

       if(pause!=true)
         {
            newspeed=speed;
            speed=10000;
            pause=true;
            break;
         }
        else if(pause==true)
        {
            speed=newspeed;
            glutTimerFunc(speed, update, 0);
            pause=false;
            break;
        }

    case 'g':
          PlaySound(TEXT("CarDoor+OpenClose.wav"),NULL,SND_SYNC);
                    view=1;
                   display();

                   glutPostRedisplay();
                   glutTimerFunc(speed, update, 0);
                 //  sndPlaySound("GPHORSEpower.wav",SND_ASYNC);
                  PlaySound("GPHORSEpower.wav",NULL,SND_LOOP | SND_ASYNC);


                   break;

         case 'c':

         if(color<4){color++;}
         else color=1;
         break;

     case 'n':
    night=true;
         break;

     case 'd':
         night=false;
         break;

     case 'l':
         light=true;
         break;
     case 'o':
         light=false;
         break;


         //case 'h':
    //sndPlaySound("CarDoor+OpenClose.wav" ,SND_ASYNC);
// PlaySound("GPHORSEpower.wav",NULL,SND_LOOP | SND_ASYNC);

      //  break;
   }

}
int main(int argc, char** argv)
{
cout<<"\n\n\n  ---------------------- Hey !!! Ready for a -->  RIDE  -------- Starting the ENGINE :) "<<endl;
PlaySound(TEXT("carstartgarage.wav"),NULL,SND_SYNC);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(800, 700);
glutInitWindowPosition(300, 0);
glutCreateWindow("");
init();
glutDisplayFunc(display);

glutKeyboardFunc(NormalKey);
glutSpecialFunc(Specialkey);
glutTimerFunc(speed, update, 0); //Add a timer
system("CLS");

int submenu=glutCreateMenu(colorMenu);
  glutAddMenuEntry("blue", 1);
	glutAddMenuEntry("red", 3);
	glutAddMenuEntry("green",2);
	/*glutAddMenuEntry("black",9);
	glutAddMenuEntry("yellow",10);*/
	glutAddMenuEntry("grey",4);
  glutCreateMenu(myMenu);

	//glutAddMenuEntry("fog effect",3);
    glutAddSubMenu("car colors",submenu);
	glutAddMenuEntry("daymode",1);
	glutAddMenuEntry("Night mode",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
//sndPlaySound("GPHORSEpower.wav",SND_ASYNC);


glutMainLoop();


return 0;
}

