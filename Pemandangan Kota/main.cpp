#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

#define BLACK 0, 0, 0

double cameraAngle;
double cameraAngleDelta;

double rectAngle;

bool canDrawGrid;



void drawBuilding(int x1, int y1, int x2,int y2, int z){
    //back side
    int minZ = 0;
    glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);
	    glVertex3f(x2, y2, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);

	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);

	    glVertex3f(x2, y2, z);
	    glVertex3f(x2, y2, minZ);

	    glVertex3f(x2, y2, minZ);
	    glVertex3f(x1, y1, minZ);
	}glEnd();

	//left side
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);
	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x1+20, y1, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);

	    glVertex3f(x1, y1, z);
	    glVertex3f(x1+20, y1, z);

	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x1+20, y1, minZ);

	    glVertex3f(x1+20, y1, minZ);
	    glVertex3f(x1, y1, minZ);
	}glEnd();

	//front side
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);{
	    glVertex3f(x1+20, y1, minZ);
	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1+20, y1, minZ);
	    glVertex3f(x1+20, y1, z);

	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x2+20, y2, z);

	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);

	    glVertex3f(x2+20, y2, minZ);
	    glVertex3f(x1+20, y1, minZ);
	}glEnd();

	//right side
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);{
	    glVertex3f(x2, y2, minZ);
	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x2, y2, minZ);
	    glVertex3f(x2, y2, z);

	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);

	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);

	    glVertex3f(x2+20, y2, minZ);
	    glVertex3f(x2, y2, minZ);
	}glEnd();

	//roof
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_QUADS);{
	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x1+20, y1, z);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);

	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);

	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x1+20, y1, z);

	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x1, y1, z);
	}glEnd();
}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,0);	//color white
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	//instead of CONSTANT information, we will define a circular path.
	gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), 150,		0,0,0,		0,0,1);
	//NOTE: the camera still CONSTANTLY looks at the center
	// cameraAngle is in RADIAN, since you are using inside COS and SIN


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/




	//border
	glColor3f(1,1,1);
	glBegin(GL_LINES);{
	    glVertex3f(-100, -100, 0);
	    glVertex3f(-100, 100, 0);

	    glVertex3f(-100, 100, 0);
	    glVertex3f(100, 100, 0);

	    glVertex3f(100, 100, 0);
	    glVertex3f(100, -100, 0);

	    glVertex3f(100, -100, 0);
	    glVertex3f(-100, -100, 0);
	}glEnd();

	//garis tengah
    glColor3f(1,1,1);
    glBegin(GL_LINES);{
        glVertex3f(0,100,1);
	    glVertex3f(0,-100,1);
    }glEnd();

	//roads
	/*glColor3f(0,0,0);
	glBegin(GL_QUADS);{
	    glVertex3f(-100,-20,0);
	    glVertex3f(-100,20,0);
	    glVertex3f(100,20,0);
	    glVertex3f(100,-20,0);
	}glEnd();*/

	glColor3f(0,0,0);
	glBegin(GL_QUADS);{
	    glVertex3f(-20,100,1);
	    glVertex3f(20,100,1);
	    glVertex3f(20,-100,1);
	    glVertex3f(-20,-100,1);
	}glEnd();

	//land
	glColor3f(0,0.5,0);
	glBegin(GL_QUADS);{
	    glVertex3f(-100, -100, 0);
	    glVertex3f(-100, 100, 0);
	    glVertex3f(100, 100, 0);
	    glVertex3f(100, -100, 0);

	}glEnd();


    //top left buildings 1st row
    drawBuilding(-90, -90, -90, -70, 50);
    drawBuilding(-90, -60, -90, -40, 30);

    //top left buildings 2nd row
    drawBuilding(-60, -90, -60, -70, 60);
    drawBuilding(-55, -60, -55, -40, 40);

    //top middle 1nd row
    drawBuilding(-90, -30, -90, 30, 60);

    //top middle 2nd row
    drawBuilding(-60, -20, -60, 0, 60);
    drawBuilding(-60, 10, -60, 30, 40);

    //top right buildings 1st row
    drawBuilding(-90, 90, -90, 70, 70);
    drawBuilding(-90, 60, -90, 40, 50);

    //top right buildings 2nd row
    drawBuilding(-60, 90, -60, 75, 80);
    drawBuilding(-60, 70, -60, 35, 45);

    //middle left buildings
    drawBuilding(40, -90, 40, -70, 40);
    drawBuilding(40, -60, 40, -40, 50);

    //middle right buildings
    drawBuilding(30, 90, 30, 70, 30);
    drawBuilding(30, 60, 30, 40, 50);

    //bottom left buildings
    drawBuilding(70, -90, 70, -70, 30);
    drawBuilding(75, -60, 75, -40, 30);

    //bottom right buildings
    drawBuilding(70, 90, 70, 70, 90);
    drawBuilding(70, 65, 70, 40, 30);

    //bottom middle


	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!
	cameraAngle += cameraAngleDelta;

	rectAngle += 1;

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){
		case '1':
			cameraAngleDelta += .0002;
			break;
        case '2':
			cameraAngleDelta -= .0002;
			break;
		case '3':
			cameraAngleDelta = 0;
			break;
		default:
			break;
	}
}

void init(){
	//codes for initialization
	cameraAngle = 0;	//// init the cameraAngle
	cameraAngleDelta = 0;
	rectAngle = 0;
	canDrawGrid = true;

	//clear the screen
	glClearColor(BLACK, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Pemandangan Kota");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
