//
//  main.cpp
//  TetsuoAPP
//
//  Created by mathieu diawara on 19/06/2016.
//  Copyright © 2016 mathieu8g. All rights reserved.
//


#include <iostream>
#include <Eigen/Dense> //relevant to Eigen calcul "Usefull for rrapid matrix calcul but bad for conversion casting"
#include <glm.hpp> // relevant to glm calcul "Usefull fior conversion casting on uniform variables"
#include <glbinding_api.h> //relevant to multi-context and perfomrance of OpenGl value
// include <SDL.h> //----------<//Better for 2D and depreciated for MacOsx Architecture running on 64 bit
#include <GLUT/glut.h> //Display Window For OpenGL and Control camera Joystick
#include <OpenGL/gl.h>
#include <OpenGL/glu.h> //link for Glu



using namespace std;
using namespace Eigen;



void displayCB(void)		/* function called whenever redisplay needed */
{
    glClear(GL_COLOR_BUFFER_BIT);		/* clear the display */
    glColor3f(1.0, 1.0, 1.0);		/* set current color to white */
    glBegin(GL_POLYGON);			/* draw filled triangle */
    glVertex2i(200,125);			/* specify each vertex of triangle */
    glVertex2i(100,375);
    glVertex2i(300,375);
    glEnd();				/* OpenGL draws the filled triangle */
    glFlush();				/* Complete any pending operations */
}

void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
    if( key == 'q' ) exit(0);
}
    
    


int main(int argc, const char * argv[]) {

    int win;
    glutInit(&argc, const_cast<char**>(argv)); //__Attention à la constante en initialisation pour Xcode !
    //glutInit(&argc, argv);		/* initialize GLUT system */
    
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400,500);		/* width=400pixels height=500pixels */
    win = glutCreateWindow("Triangle");	/* create window */
    
    /* from this point on the current window is win */
    
    glClearColor(0.0,0.0,0.0,0.0);	/* set background to black */
    gluOrtho2D(0,400,0,500);		/* how object is mapped to window */
    glutDisplayFunc(displayCB);		/* set window's display callback */
    glutKeyboardFunc(keyCB);		/* set window's key callback */
    
    glutMainLoop();			/* start processing events... */
    
    /* execution never reaches this point */
    
    return 0;
}
