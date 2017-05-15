// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include <cmath>
#include <cstring>
#include <GL/glut.h>


// Global Variables (Only what you need!)
double screen_x = 1000;
double screen_y = 800;

double gX = 200;
double gY = 200;
double gDX = .17;
double gDY = .13;
const double WIDTH = 50;
const double HEIGHT = 50;
int lines = 32;

// 
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius, int lines_in)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<lines_in; i++)
	{
		double theta = (double)i/lines_in * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}

void DrawSpiral(double a,double b)
{
	double x, y;
	 
	double theta = 0;
	x = a+.2*pow(2.718281,(double).2*theta)*cos(theta);
	y = a+.2*pow(2.718281,(double).2*theta)*sin(theta);
	for (int i = 0; i < 5000; i++)
	{
		glBegin(GL_LINES);
		theta = 0.025*i;
		glVertex2f((GLfloat)x, (GLfloat)y);
		glVertex2f(a+.2*pow(2.718281, (double).2*theta)*cos(theta), a+.2*pow(2.718281, (double).2*theta)*sin(theta));
		 
		//glColor3f(r, g, b);
		x = a+.2*pow(2.718281, (double).2*theta)*cos(theta);
		y = a+.2*pow(2.718281, (double).2*theta)*sin(theta);
		  
		glEnd();
	}
 
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, char *string)
{
	void *font = GLUT_BITMAP_9_BY_15;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	
	int len, i;
	glRasterPos2d(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) 
	{
		glutBitmapCharacter(font, string[i]);
	}

    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
/*
	// Wall bouncing
	if (gX + WIDTH + gDX >= screen_x)
	{
		gDX = -gDX;
	}
	if (gX + gDX < 0)
	{
		gDX = -gDX;
	}
	if (gY + WIDTH + gDY >= screen_y)
	{
		gDY = -gDY;
	}
	if (gY + gDY < 0)
	{
		gDY = -gDY;
	}
	// Increment Rectangle Position
	gX += gDX;
	gY += gDY;
*/
	// Draw Circle
	glColor3d(0,0,1);
	DrawSpiral(250, 300);


	glutSwapBuffers();
	glutPostRedisplay(); // Force an animation
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
	switch (c) 
	{
		case 27: // escape character means to quit the program
			exit(0);
			break;
		case '1':
			lines = 64;
			break;
		case '2':
			lines = 128;
			break;
		case '3':
			lines = 3;
			break;
		case '4':
			lines = 4;
			break;
		case '5':
			lines = 5;
			break;
		case '6':
			lines = 6;
			break;
		case '7':
			lines = 7;
			break;
		case '8':
			lines = 8;
			break;
		case '9':
			lines = 16;
			break;
		case '0':
			lines = 32;
			break;

		default:
			return; // if we don't care, return without glutPostRedisplay()
	}

	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
	// Reset our global variables to the new width and height.
	screen_x = w;
	screen_y = h;

	// Set the pixel resolution of the final picture (Screen coordinates).
	glViewport(0, 0, w, h);

	// Set the projection mode to 2D orthographic, and set the world coordinates:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
	{
	}
	glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(50, 50);

	int fullscreen = 0;
	if (fullscreen) 
	{
		glutGameModeString("800x600:32");
		glutEnterGameMode();
	} 
	else 
	{
		glutCreateWindow("This appears in the title bar");
	}

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glColor3d(0,0,0); // forground color
	glClearColor(1, 1, 1, 0); // background color
	InitializeMyStuff();

	glutMainLoop();

	return 0;
}
