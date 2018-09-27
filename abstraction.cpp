#include "project.h"

// set drawing color
void setColor(float r, float g, float b)
{
	// r,g,b supposed to be between 0 and 1
	glColor3f(r, g, b);
}

// set background color
void setBackgroundColor(float r, float g, float b)
{
	glClearColor(r, g, b, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}

// draw a pixel at x,y
void drawPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

// draw a line from (x1,y1) to (x2,y2)
void drawLine(int x1, int y1, int x2, int y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glEnd();
}

// draw a circle with radius r
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_LINE_LOOP);
	for (i = 0; i <= lineAmount; i++)
	{
		glVertex2f(
			x + (radius * cos(i * twicePi / lineAmount)),
			y + (radius * sin(i * twicePi / lineAmount)));
	}
	glEnd();
}

void clickHandler_internal(int btn,int state,int x,int y){
	int x_int, y_int;
	x_int = x;
	y_int = height - y;
	if(state==GLUT_DOWN and btn==GLUT_LEFT)
	{
		clickDown(x_int, y_int);
	}
	glFlush();
}

//intializing stuff
void draw_helper();

void init_window(string title, int argc, char ** argv)
{
	glutInit(&argc,argv);
	// TODO: Take window size from commandline args else set to fullscreen if possible
	glutInitWindowSize(width,height);
	glutCreateWindow(title.c_str());
	gluOrtho2D(0,width,0,height); //defined limits in which to draw
}

void run(){
	glutMouseFunc(clickHandler_internal);
	glutDisplayFunc(draw_helper);
	glutMainLoop();
}

void draw_helper(){
	draw(); glFlush();
}
