#include<stdio.h>
#include<GL/glut.h>
#include<windows.h>
#include<math.h>
#define SPEED 70.0
 //////////////////////////////////////// Declaration of global variables   /////////////////////////
float y=0,ang=0,i=0,k=0,n=0,u=0,ae=0,be=0;
GLint control_keyl,control_keyr;
float a=900,b=880,c=900,d=900,p,q=0,s,r=0;
int x=0;
int light=0;
//;;
//GLfloat red=0,blue=1,green=.3;
///;;;
float g=0;   // car  translate indicator
float w=0;    // car2  "     "
float m=.80,j=.50,o=.15;

int flags=0;
////////////////////////////// sea function to display river   ///////////////////////////////






void frontscreen();
void display();
void helpscreen();
void drawsting();
void car();
void fish1();
void fish2();
void bridge();
void sea();
void boat();
void poles();
void aeroplane();



void setFont();

void *currentfont;

void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
//glClearColor(0.556863,0.137255,0.419608,0);/*background for cover page*/meron
glClearColor(0.15,0.1,0.01,0);//old
//glClearColor(0.36,0.25,0.20,0);//brown
//glClearColor(0.87,0.58,0.98,0);//lite purple
//glClearColor(0.29,0.46,0.43,0);//coppergreen
//glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,1);
drawstring(600.0,1500.0,0.0,"THE OXFORD COLLEGE OF ENGINEERING ");
glColor3f(0.5,1.0,0);
drawstring(450,1350,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
glColor3f(0.22,0.69,0.87);
drawstring(450,1250,0.0,"COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT");
glColor3f(0.71,0.65,0.26);
drawstring(700,1150,0.0,"LABORATORY CODE : 17CSL68");
glColor3f(0.917647,0.917647,0.678431);
drawstring(600,1050,0.0,"COMPUTER GRAPHICS MINI PROJECT ON :" );
glColor3f(1,0,0);
drawstring(500,950,0.0,"GRAPHICAL REPRESENTATION OF BRIDGE SIMULATION ");
glColor3f(0,1,0.419608);
drawstring(200,800,0.0,"DONE BY:");
glColor3f(0,1,1);
drawstring(150,700,0.0,"SUMAIYA KHANUM S");
glColor3f(0.73,0.16,0.96);
drawstring(150,600,0.0,"SAHANA R K");
glColor3f(0.89,0.47,0.20);
drawstring(150,500,0.0,"VARSHA N");
glColor3f(0.6,0.7,0.98);
drawstring(150,400,0.0,"VEDIKA KABRA");
glColor3f(0,1,1);
drawstring(60,250,0.0,"SEM : 6B");
glColor3f(0,1,0.419608);
drawstring(1500,800,0.0,"GUIDED BY:");
glColor3f(0.85,0.53,0.10);
drawstring(1450,700,0.0,"PROF.FLORANCE G");
glColor3f(0.6,0.8,1);
drawstring(1450,600,0.0,"PROF.SENTHIL");
glColor3f(1,1,0);
drawstring(650,250,0.0,"PRESS 'ENTER' KEY TO SHOW HELP SCREEN");
glFlush();
}

void helpscreen()
{
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glClearColor(0,0,0,0);/*background for cover page*/
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,1,0);
drawstring(650,1500.0,0.0,"***********  HELP SCREEN  ***********");
glColor3f(1,0,0);
drawstring(150.0,1350.0,0.0,"--> Press 'e' to change the ship color to Red");
glColor3f(0,1,0);
drawstring(150.0,1250,0.0,"--> Press 'g' to change the ship color to Green");
glColor3f(0.36,0.25,0.20);
drawstring(150.0,1150.0,0.0,"--> Press 'b' to change the ship color to Brown");
glColor3f(0,1,1);
drawstring(150.0,1050.0,0.0,"--> Press 'c' to change the ship color to Cyan");
glColor3f(1,0,1);
drawstring(150.0,950.0,0.0,"--> Press 'm' to change the ship color to Magenta");
glColor3f(1,1,1);
drawstring(150.0,850.0,0.0,"--> Press 'w' to change the ship color to White");
glColor3f(0.658824,0.658824,0.658824);
drawstring(150.0,750.0,0.0,"--> Press 'y' to change the ship color to light Grey");
glColor3f(0.85,0.53,0.10);
drawstring(150.0,650.0,0.0,"--> Use Menu options to 'Start ,Stop & Quit' Animation");
glColor3f(0,0,1);
drawstring(150.0,550.0,0.0,"--> For  **HELP SCREEN**  PRESS Letter 'h'");
glColor3f(1,1,0);
drawstring(650,300.0,0.0,"*****PRESS 'ENTER' KEY TO START ANIMATION*****");
glFlush();
}
///////////////////draw circles/////////////
void Drawarc(float sa,float ea,float cx,float cy,float rd)
{
     float PI = 3.14;
     float step=1.0;
     float angle,x=700,y=800,centerX=cx,centerY=cy,radius=rd;
     glBegin(GL_POLYGON);
     for(angle=sa;angle<ea; angle+=step)
     {
     float rad ;
     rad = PI*angle/180;
     x  = centerX+radius*cos(rad);
     y  = centerY+radius*sin(rad);
     glVertex2f(x,y);
     }
     glEnd();
     glFlush();
}




////////////////////////////////////////////////////////
void aeroplane()
{
glPushMatrix();
glTranslatef(ae++,be++,0);
glPushMatrix();

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex2f(0.0,20.0);
glVertex2f(0.0,120.0);
glVertex2f(270.0,120.0);
glVertex2f(270.0,20.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0,0.0,0.0);
glVertex2f(270.0,120.0);
glVertex2f(320.0,110.0);
glVertex2f(360.0,95.0);
glVertex2f(390.0,75.0);
glVertex2f(270.0,75.0);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(270.0,121.0);
glVertex2f(321.0,111.0);
glVertex2f(351.0,96.0);
glVertex2f(391.0,76.0);
glVertex2f(270.0,76.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.419608,0.137255,0.556863);
glVertex2f(270.0,75.0);
glVertex2f(390.0,75.0);
glVertex2f(350.0,45.0);
glVertex2f(310.0,30.0);
glVertex2f(270.0,20.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.73,0.16,0.96);
glVertex2f(0.0,120.0);
glVertex2f(0.0,180.0);
glVertex2f(30.0,180.0);
glVertex2f(90.0,120.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.73,0.16,0.96);
glVertex2f(160.0,120.0);
glVertex2f(120.0,150.0);
glVertex2f(190.0,150.0);
glVertex2f(230.0,120.0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.73,0.16,0.96);
glVertex2f(150.0,75.0);
glVertex2f(210.0,75.0);
glVertex2f(178.0,5.0);
glVertex2f(120.0,5.0);
glEnd();

glPopMatrix();glPopMatrix();glPopMatrix();glPopMatrix();glPopMatrix();glPopMatrix();
}////////////////////////
void idle()
{


if(light==0 && (i>=30 && i<=520)) //value of i when first vehicle is near the traffic-signal
 {

	 i+=SPEED/5;
 }

if(light==0 && (i>530 && i<=800)) //value of i when second vehicle is near the traffic-signal
 {

	 i+=SPEED/10;

}

if(light==0 && (i>800 && i<=1020))// value of i when third vehicle is near the traffic signal
 {

	 i+=SPEED/10;
 }
/////to make the vehicle stop based on the abv condtion
if(light==0)
 {
	 i=i;
 }

else
 {
     light=1;
   i+=SPEED/10;
 }
if(i>1630)
	 i=0.0;
glutPostRedisplay();
}
////////////////////



////////////////////////////////////traffic light comes in one of strret light///////////////////



void traffic()
{
	int l;
if(light==1)
	  {

//for green light to display
glColor3f(0.0,0.0,0.0);
		Drawarc(0,360,1310,1390,7);//red light
		glColor3f(1.0,1.0,0.0);//yellow light
    Drawarc(0,360,1310,1360,7);

		glColor3f(0.0,0.7,0.0);
		 Drawarc(0,360,1310,1330,7);//green light
		}


	else
	  {

//for red light to display
		glColor3f(1.0,0.0,0.0);
		Drawarc(0,360,1310,1390,7);//red

	   glColor3f(1.0,1.0,0.0);//yellow
    Drawarc(0,360,1310,1360,7);

		glColor3f(0.0,0.0,0.0);
		 Drawarc(0,360,1310,1330,7);//green

	  }
	glPushMatrix();

}





//////////////////////////////////////////
void sea()
{
	     glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.8,0.90);//sea color
    glVertex2f(0.0,0.0);
    glVertex2f(2000.0,0.0);
    glVertex2f(2000.0,1600.0);//the sea frame
    glVertex2f(0.0,1600.0);
    glEnd();

    glPushMatrix();

               glTranslatef(0,q,0);
               glBegin(GL_LINES);
                      glColor3f(1.0,1.0,1.0);//loopd for the display of line
                            for(p=0;p<20000;p=p+55)
                                for(s=0;s<20000;s=s+55)
                                    glVertex2f(55.0+s,55.0+p);
                                    glVertex2f(160.0+s,55.0+p);
               glEnd();
    glPopMatrix();
}


////////////////////////////////////////  Bridge function  ////////////////////////////////////

void bridge()
{
	glBegin(GL_POLYGON);
		glColor3f(0.40,0.40,0.40);
		glVertex2f(0.0,900.0);
		glVertex2f(500.0,900.0);
		glVertex2f(500.0,1200.0);   //bridge top 1
		glVertex2f(0.0,1200.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(100.0,1030.0);
		glVertex2f(200.0,1030.0);
		glVertex2f(200.0,1040.0);   //strip1
		glVertex2f(100.0,1040.0);
    glEnd();


	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(300.0,1030.0);
		glVertex2f(400.0,1030.0);
		glVertex2f(400.0,1040.0);   //strip2
		glVertex2f(300.0,1040.0);
    glEnd();


	glBegin(GL_POLYGON);

		glColor3f(1.0,1.0,.0);
		glVertex2f(0.0,1170.0);
		glVertex2f(500.0,1170.0);
		glVertex2f(500.0,1175.0);   //yellow strip1
		glVertex2f(0.0,1175.0);
    glEnd();


	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(0.0,920.0);
		glVertex2f(500.0,920.0);
		glVertex2f(500.0,930.0);   //yellow strip2
		glVertex2f(0.0,930.0);
    glEnd();

	//   brige up

	glPushMatrix();
;


	glBegin(GL_POLYGON);
		glColor3f(0.46,0.46,0.46);
		glVertex2f(500.0,900.0);             //bridge top 2
		//up
		glVertex2f(900.0-k,900.0+n);
		glVertex2f(900.0-k,1200.0+n);
		//up
		glVertex2f(500.0,1200.0);
    glEnd();




	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(900.0-k,900.0+n);    //pole thread front
		glVertex2f(0.0,1400.0);
		glVertex2f(900.0-k,880.0+n);
	glEnd();


	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(30.0,1550.0);
		glVertex2f(900.0-k,1200.0+n);   //pole thread back
		glVertex2f(50.0,1550.0);
		glVertex2f(900.0-k,1203.0+n);
	glEnd();



	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(500.0,880.0);
		glVertex2f(900.0-k,880.0+n); //base1
		glVertex2f(900.0-k,900.0+n);
		glVertex2f(500.0,900.0);
	glEnd();


	glBegin(GL_POLYGON);
		glColor3f(0.46,0.46,0.46);
		glVertex2f(900.0+k,900.0+n);
		//up
		glVertex2f(1300.0,900.0);    // bridge top3
		glVertex2f(1300.0,1200.0);
		//up
		glVertex2f(900.0+k,1200.0+n);
      glEnd();


	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(900.0+k,880.0+n);
		glVertex2f(1300.0,880.0);	// base 2
		glVertex2f(1300.0,900.0);
		glVertex2f(900.0+k,900.0+n);/////
	glEnd();
glPopMatrix();




//		printf("i== %f\t k==%f\n",i,k);

	//============================
	glBegin(GL_POLYGON);
		glColor3f(0.40,0.40,0.40);
		glVertex2f(1300.0,900.0);
		glVertex2f(2000.0,900.0);  //bridge top 4
		glVertex2f(2000.0,1200.0);
		glVertex2f(1300.0,1200.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1300.0,1170.0);
		glVertex2f(2000.0,1170.0);
		glVertex2f(2000.0,1175.0);   //yellow strip3
		glVertex2f(1300.0,1175.0);
     glEnd();
	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1300.0,920.0);
		glVertex2f(2000.0,920.0);
		glVertex2f(2000.0,930.0);   // yellow strip4
		glVertex2f(1300.0,930.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1400.0,1030.0);
		glVertex2f(1500.0,1030.0);
		glVertex2f(1500.0,1040.0);   //strip3
		glVertex2f(1400.0,1040.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1600.0,1030.0);
		glVertex2f(1700.0,1030.0);
		glVertex2f(1700.0,1040.0);   //strip4
		glVertex2f(1600.0,1040.0);
    glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1800.0,1030.0);
		glVertex2f(1900.0,1030.0);
		glVertex2f(1900.0,1040.0);   //strip5
		glVertex2f(1800.0,1040.0);
    glEnd();


	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1725.0,1550.0);
		glVertex2f(900.0+k,1200.0+n);    //rite pole thread
		glVertex2f(1745.0,1550.0);
		glVertex2f(900.0+k,1200.0+n);
		glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.25,0.25,0.25);
		glVertex2f(200.0,800.0);   //6 point polygon 1
		glVertex2f(200.0,400.0);//700"
		glVertex2f(300.0,400.0);//"
		glVertex2f(300.0,800.0);
		glVertex2f(350.0,880.0);
		glVertex2f(150.0,880.0);
		glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0.0,880.0);
		glVertex2f(500.0,880.0);   //base3
		glVertex2f(500.0,900.0);
		glVertex2f(0.0,900.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,0.0);    //base4
		glVertex2f(1300.0,880.0);
		glVertex2f(2000.0,880.0);
		glVertex2f(2000.0,900.0);
		glVertex2f(1300.0,900.0);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(0.25,0.25,0.25);
		glVertex2f(1500.0,800.0);
		glVertex2f(1500.0,400.0);
		glVertex2f(1600.0,400.0);  //6 point polygon2
		glVertex2f(1600.0,800.0);
		glVertex2f(1650.0,880.0);
		glVertex2f(1450.0,880.0);
	glEnd();


	}


  float v;

	void fish1()
{
	glColor3f(1,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(300,300);
	glVertex2f(310,280);
	glVertex2f(320,270);
	glVertex2f(330,280);
	glVertex2f(335,290);
	glVertex2f(340,300);
	glVertex2f(330,320);
	glVertex2f(320,330);
	glVertex2f(310,320);
	glEnd();

	glColor3f(0.419608,0.137255,0.556863); //tail
	glBegin(GL_POLYGON);
	glVertex2f(340,300);
	glVertex2f(350,270);
	glVertex2f(345,300);
	glVertex2f(350,330);
	glEnd();

	glColor3f(1,1,1); //mouth
	glBegin(GL_LINES);
	glVertex2f(300,300);
	glVertex2f(310,300);
	glEnd();
	glColor3f(0,0,0); //fish eye
	glBegin(GL_POLYGON);
	for(v=0;v<2*3.14;v+=0.5)
	glVertex2f(308+2*cos(v),308+2*sin(v));
	glEnd();

}




void fish2()
{    float h;

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(150+95,310-10);
	glVertex2f(120+95,340-20);
	glVertex2f(130+100,312-10);
	glVertex2f(120+95,300-30);
	glEnd();


	glColor3f(1,0.8,0);
	glBegin(GL_POLYGON);
	glVertex2f(300-60,300);
	glVertex2f(310-60,280);
	glVertex2f(320-60,270);
	glVertex2f(330-60,280);
	glVertex2f(335-60,290);
	glVertex2f(340-60,300);
	glVertex2f(330-60,320);
	glVertex2f(320-60,330);
	glVertex2f(310-60,320);
	glEnd();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(280,280+20);
	glVertex2f(270,280+20);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	for(v=0;v<2*3.14;v+=0.5)
	glVertex2f(270+2*cos(v),308+2*sin(v));

	glEnd();



}

//////////////////////////////////////////  Boat function  ///////////////////////////////

void boat()
{
	glPushMatrix();
  glTranslatef(0,y,0);
    glPushMatrix();

    glBegin(GL_POLYGON);
        glColor3f(0.419608,0.137255,0.556863);
        glVertex2f(780.0,550.0);
		glVertex2f(780.0,250.0);
		glVertex2f(900.0,070.0);
		glVertex2f(1020.0,250.0);     ///ship  1st outline
		glVertex2f(1020.0,550.0);
		glVertex2f(900.0,730.0);
		glEnd();

		glBegin(GL_POLYGON);
        glColor3f(m,j,o);
        glVertex2f(800.0,550.0);
		glVertex2f(800.0,250.0);
		glVertex2f(900.0,100.0);
		glVertex2f(1000.0,250.0);     ///ship  2nd outline
		glVertex2f(1000.0,550.0);
		glVertex2f(900.0,700.0);
		glEnd();

		glBegin(GL_LINES);
        glColor3f(0.917647,0.917647,0.678431);
        glVertex2f(820.0,550.0);
		glVertex2f(820.0,250.0);
        glVertex2f(820.0,250.0);
        glVertex2f(900.0,120.0);
        glVertex2f(900.0,120.0);
		glVertex2f(980.0,250.0);     ///ship grills
		glVertex2f(980.0,250.0);
		glVertex2f(980.0,550.0);
		glVertex2f(980.0,550.0);
		glVertex2f(900.0,680.0);     ///ship grills
		glVertex2f(900.0,680.0);
		glVertex2f(820.0,550.0);
		glEnd();

glBegin(GL_POLYGON);
        glColor3f(0.917647,0.917647,0.678431);
        glVertex2f(840.0,535.0);
		glVertex2f(960.0,535.0);
		glVertex2f(960.0,260.0);
		//glVertex2f(950.0,560.0);
		glVertex2f(840.0,260.0);     ///ship small box
		glEnd();

		glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(870.0,480.0);
        glVertex2f(930.0,320.0);
        glVertex2f(930.0,480.0);
        glVertex2f(870.0,320.0);   ///ship design box
		glEnd();

		glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        glVertex2f(870.0,280.0);
		glVertex2f(930.0,280.0);
		glVertex2f(930.0,310.0);
		glVertex2f(870.0,310.0);
		glVertex2f(870.0,280.0);     ///ship  very tiny  box
		glEnd();


    glPopMatrix();
glPopMatrix();




}




////////////////////////////////////////////    car function   //////////////////////////////////




void car2()
{
glPushMatrix();


glTranslatef(w,0,0);
//;;
	glPushMatrix();
	glTranslatef(1820.0,1030.0,0.0);
	glutSolidSphere(1.0,200,200);
	glPopMatrix();
///;;
	glBegin(GL_POLYGON);                  //  car
		glColor3f(0.03,0.8,0.9);//top color
		glVertex2f(1800.0,1050.0);
		glVertex2f(1950.0,1050.0);
		glVertex2f(1950.0,1150.0);
		glVertex2f(1800.0,1150.0);
	glEnd();


	glBegin(GL_POLYGON);                  //  car
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1770.0,1030.0);
		glVertex2f(1800.0,1050.0);
		glVertex2f(1800.0,1150.0);
		glVertex2f(1770.0,1130.0);
	glEnd();


	glBegin(GL_POLYGON);                  //  car
		glColor3f(0.03,0.16,1.96);
		glVertex2f(1770.0,1030.0);
		glVertex2f(1930.0,1030.0);
		glVertex2f(1950.0,1050.0);
		glVertex2f(1800.0,1050.0);
	glEnd();


    glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1820.0,1080.0);
		glVertex2f(1920.0,1080.0);
		glVertex2f(1920.0,1080.0);
		glVertex2f(1920.0,1110.0);
		glVertex2f(1920.0,1110.0);             //carrier
		glVertex2f(1820.0,1110.0);
		glVertex2f(1820.0,1110.0);
		glVertex2f(1820.0,1080.0);
		glVertex2f(1840.0,1080.0);
		glVertex2f(1840.0,1110.0);
		glVertex2f(1860.0,1080.0);
		glVertex2f(1860.0,1110.0);
		glVertex2f(1880.0,1080.0);
		glVertex2f(1880.0,1110.0);
		glVertex2f(1900.0,1080.0);
		glVertex2f(1900.0,1110.0);
	glEnd();


	glBegin(GL_LINES);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1780.0,1035.0);        //head lamp
		glVertex2f(1780.0,1045.0);
	glEnd();


	glBegin(GL_LINES);
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1780.0,1125.0);        //head lamp
		glVertex2f(1780.0,1135.0);
	glEnd();


	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1790.0,1055.0);        //horn grill
		glVertex2f(1790.0,1125.0);
		glEnd();


	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(1800.0,1040.0);        //side window
		glVertex2f(1928.0,1040.0);
		glEnd();

glPopMatrix();
}

/////////////////////////////////////////////////// Pole Function  ///////////////////////////////

void poles()
{
	glBegin(GL_POLYGON);                 //  left pole behind
		glColor3f(0.0,0.0,0.0);
		glVertex2f(30.0,1200.0);
		glVertex2f(50.0,1200.0);
		glVertex2f(50.0,1550.0);
		glVertex2f(30.0,1550.0);
	glEnd();



	glBegin(GL_POLYGON);                  //  right pole behind
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1725.0,1200.0);
		glVertex2f(1745.0,1200.0);
		glVertex2f(1745.0,1550.0);
		glVertex2f(1725.0,1550.0);
	glEnd();


  glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1750.0,1400.0);
		glVertex2f(900.0+k,900.0+n);    //right pole thread front
		glVertex2f(1770.0,1400.0);
		glVertex2f(900.0+k,880.0+n);
		glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(900.0-k,900.0+n);    //pole thread front
		glVertex2f(0.0,1400.0);
		glVertex2f(900.0-k,880.0+n);
	glEnd();



	glBegin(GL_POLYGON);                  //  left pole front
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0.0,900.0);
		glVertex2f(20.0,900.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(0.0,1400.0);
	glEnd();



	glBegin(GL_POLYGON);                  //  right pole front
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1750.0,900.0);
		glVertex2f(1770.0,900.0);
		glVertex2f(1770.0,1400.0);
		glVertex2f(1750.0,1400.0);
	glEnd();




	////////////////////////street light//////
		glBegin(GL_POLYGON);                 // street light behind 1 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(150.0,1200.0);
		glVertex2f(160.0,1200.0);
		glVertex2f(160.0,1300.0);
		glVertex2f(150.0,1300.0);
	glEnd();

	glBegin(GL_POLYGON);                 // street light behind 1 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(165.0,1300.0);
		glVertex2f(145.0,1300.0);
		glVertex2f(145.0,1325.0);
		glVertex2f(165.0,1325.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light behind 2 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1800.0,1200.0);
		glVertex2f(1810.0,1200.0);
		glVertex2f(1810.0,1300.0);
		glVertex2f(1800.0,1300.0);
	glEnd();

	glBegin(GL_POLYGON);                  // traffic light behind 2 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1815.0,1300.0);
		glVertex2f(1795.0,1300.0);
		glVertex2f(1795.0,1325.0);
		glVertex2f(1815.0,1325.0);
	glEnd();



	glBegin(GL_POLYGON);                  // traffic light behind 3 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1300.0,1200.0);
		glVertex2f(1310.0,1200.0);
		glVertex2f(1310.0,1300.0);
		glVertex2f(1300.0,1300.0);
	glEnd();

	glBegin(GL_POLYGON);                  // traffic light behind 3 head
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1325.0,1280.0);
		glVertex2f(1285.0,1280.0);
		glVertex2f(1285.0,1400.0);
		glVertex2f(1325.0,1400.0);

	glEnd();



	glBegin(GL_POLYGON);                  // street light behind 3 head
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1315.0,1300.0);
		glVertex2f(1295.0,1300.0);
		glVertex2f(1295.0,1250.0);
		glVertex2f(1315.0,1250.0);
	glEnd();


	glBegin(GL_POLYGON);                  // street light behind 4 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(490.0,1200.0);
		glVertex2f(500.0,1200.0);
		glVertex2f(500.0,1300.0);
		glVertex2f(490.0,1300.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light behind 4 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(505.0,1300.0);
		glVertex2f(485.0,1300.0);
		glVertex2f(485.0,1325.0);
		glVertex2f(505.0,1325.0);
	glEnd();

  	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1750.0,1400.0);
		glVertex2f(900.0+k,900.0+n);    //right pole thread front
		glVertex2f(1770.0,1400.0);
		glVertex2f(900.0+k,880.0+n);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(900.0-k,900.0+n);    //pole thread front
		glVertex2f(0.0,1400.0);
		glVertex2f(900.0-k,880.0+n);
	glEnd();

	glBegin(GL_POLYGON);                  //  left pole front
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0.0,900.0);
		glVertex2f(20.0,900.0);
		glVertex2f(20.0,1400.0);
		glVertex2f(0.0,1400.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  right pole front
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1750.0,900.0);
		glVertex2f(1770.0,900.0);
		glVertex2f(1770.0,1400.0);
		glVertex2f(1750.0,1400.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light front 1 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(250.0,900.0);
		glVertex2f(260.0,900.0);
		glVertex2f(260.0,1000.0);
		glVertex2f(250.0,1000.0);
	glEnd();

	glBegin(GL_POLYGON);                  // street light front 1 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(265.0,1000.0);
		glVertex2f(245.0,1000.0);
		glVertex2f(245.0,1025.0);
		glVertex2f(265.0,1025.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  street light front 2 tail
		glColor3f(0.0,0.0,0.0);
		glVertex2f(1550.0,900.0);
		glVertex2f(1560.0,900.0);
		glVertex2f(1560.0,1000.0);
		glVertex2f(1550.0,1000.0);
	glEnd();

	glBegin(GL_POLYGON);                  //  street light front 2 head
		glColor3f(1.0,1.0,0.0);
		glVertex2f(1565.0,1000.0);
		glVertex2f(1545.0,1000.0);
		glVertex2f(1545.0,1025.0);
		glVertex2f(1565.0,1025.0);
	glEnd();






	////////////////////
}


/////////////////////////////// display function  ///////////////////////////

void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

traffic();
   sea();
   bridge();
   boat();
   car2();
   fish1();
   fish2();
   poles();
    aeroplane();
	traffic();


		glFlush();


}

void mydisplay(void)
{
    if(flags==0)
frontscreen();
if(flags==1)
	helpscreen();
if(flags==2)
    display();
    glutSwapBuffers();

}

/////////////////////////////////   function to animate bridge stripes   //////////////////////////////

void animate()
{
	q=q-0.5;
	y=y+0.5; //0.2

    a=a+0.5; ///


	i+=0.5;
	if((i>=135) && (i<=439))
	{	k=k+0.45; //0.1 "
		n=n+0.45;
		light=0;
	}
	if(i>=1200 && !(k<=0 && n<=0))
	{
		k=k-0.45;
		n=n-0.45;
		light=0;
	}

	if(k<=0)
    {
      		//g-=0.5;
g-=1.5;
light=1;
//w-=0.5;

}

if(k<=2)
{

    w-=1.5;
    light=1;
//TO MOVE CAR

}




	glutPostRedisplay();
}





void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,2000.0,0.0,1600.0);
}



/////////////////////////////////// Menu function  ///////////////////////

void main_menu(int ch)
{
	switch(ch)
	{
	case 1:glutIdleFunc(NULL);
		   break;

	case 2:glutIdleFunc(animate);
	break;

	case 3:exit(0);
	}

}


/////////////////////////////////   K/B function for changing boat color  //////////////////
void control()
{
 GLint control_keyl;
	if(control_keyl!='l'||control_keyr!='r')
	{
	if(control_keyl=='l')
      a=a+6;
	if(control_keyr=='r')
	 b=b-6;
	}

}



//;;

///;;
void keyboard( unsigned char key, int x, int y )
{

switch(key)
{
	case 13:
		if(flags==1)
		{
			flags=2;
			mydisplay();
		}
		if(flags==0) //ascii of 'enter' key is 13
		{
	flags=1;
	mydisplay();
		}

	break;
	case 'l':control_keyl=key;
		p=0;q=0;r=1;
	break;
	case 'r':control_keyr=key;
		p=0;q=0;r=1;
	break;
	case 's':mydisplay();
	break;
	case 'h':flags=1;
	mydisplay();
		break;

    case 'e':m=1.0,j=0.0,o=0.0;
			 glutPostRedisplay();
			 break;

    case 'g':m=0.0,j=1.0,o=0.0;
		     glutPostRedisplay();
          	 break;

	case 'b':m=.80,j=.50,o=0.15;
             glutPostRedisplay();
             break;

	case 'w':m=1.0,j=1.0,o=1.0;
		     glutPostRedisplay();
			 break;

	case 'm':m=1.0,j=.0,o=1.0;
			 glutPostRedisplay();
			 break;

	case 'c':m=.0,j=1.0,o=1.0;
			 glutPostRedisplay();
			 break;

	case 'y':m=.75,j=0.75,o=.75;
			 glutPostRedisplay();
			 break;
	case 'R':light=0;
		break;
	case 'G':light=1;
		break;
      default:break;

    };
}



int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(2000,1600);
	glutInitWindowPosition(0,0);
	glutCreateWindow("BRIDGE");

	glutCreateMenu(main_menu);
	glutAddMenuEntry("Start Animation",2);
	glutAddMenuEntry("Stop Animation",1);


	glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(keyboard);


	glutDisplayFunc(mydisplay);
	myinit();
	glClearColor (1.0, 1.0, 0.0, 1.0);
	glutMainLoop();
        return 0;

}





////////////////////////////////////  The End  :D     ///////////////////////////


