/*
Clock_and_Calendar coded by Saifullah Talukder

Statement:

First, Given a specific month and year you have to show the calendar of
that month.
** You have to create a GUI that will show your calendar.
** You need to provide slots in your GUI so that the user can provide the
inputs.
** As the second part of this assignment, you have to show a clock that will
display the current time.
** You can show the clock using 7-segment displays (As shown in figure
below).
** You have to show hours, minutes and seconds in your clock.
** The time displayed in your clock must change as time passes by.
** You have to implement both the calendar and the clock in the same pro-
gram.

Note: The code for iGraphics.h is given in the previous directory.
*/

#include "iGraphics.h"

int i,j,k,m,Y,x,y,r,c=50,days,flag,idx1,idx2,H,h,mn,s,a=50,b=3;
char str[3],year[20],month[20],*ptr;

void drawTextBox()
{
	iSetColor(250, 50, 150);
	iRectangle(100, 50, 130, 30);
	iRectangle(300, 50, 130, 30);
	iSetColor(250, 150, 150);
	iText(100, 100, "Year",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 100, "Month",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(100,250,200);
	iText(110,60,year,GLUT_BITMAP_HELVETICA_18);
	iText(310,60,month,GLUT_BITMAP_HELVETICA_18);
}

int Getdays ()
{
    if (year[0]=='\0' || month[0]=='\0') return -1;
    else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
    else if (m==2) {
        if ((Y%100!=0 && Y%4==0) || Y%400==0) return 29;
        else return 28;
    }
    else if (m==4 || m==6 || m==9 || m==11) return 30;
    else return -1;
}

void printMonth ()
{
    iSetColor(220,100,15);
    switch (m) {
        case 13:
            iText (x,y+70,"January",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 14:
            iText (x,y+70,"February",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 3:
            iText (x,y+70,"March",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 4:
            iText (x,y+70,"April",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 5:
            iText (x,y+70,"May",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 6:
            iText (x,y+70,"June",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 7:
            iText (x,y+70,"July",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 8:
            iText (x,y+70,"August",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 9:
            iText (x,y+70,"September",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 10:
            iText (x,y+70,"October",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 11:
            iText (x,y+70,"November",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
        case 12:
            iText (x,y+70,"December",GLUT_BITMAP_TIMES_ROMAN_24);
            break;
    }
    iText (x+120,y+70,year,GLUT_BITMAP_TIMES_ROMAN_24);
}

void print0 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p-b, q-a, b, a);
    iFilledRectangle(p-b, q-2*a-b, b, a);
    iFilledRectangle(p, q-2*(a+b), a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
    iFilledRectangle(p+a, q-a, b, a);
}

void print1 (int p, int q)
{
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p+a, q-2*a-b, b, a);
}

void print2 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p-b, q-2*a-b, b, a);
    iFilledRectangle(p, q-2*(a+b), a, b);
}

void print3 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
    iFilledRectangle(p, q-2*(a+b), a, b);
}

void print4 (int p, int q)
{
    iFilledRectangle(p-b, q-a, b, a);
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
}

void print5 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p-b, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
    iFilledRectangle(p, q-2*(a+b), a, b);
}

void print6 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p-b, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p-b, q-2*a-b, b, a);
    iFilledRectangle(p, q-2*(a+b), a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
}

void print7 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p+a, q-2*a-b, b, a);
}

void print8 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p-b, q-a, b, a);
    iFilledRectangle(p-b, q-2*a-b, b, a);
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p, q-2*(a+b), a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
}

void print9 (int p, int q)
{
    iFilledRectangle(p, q, a, b);
    iFilledRectangle(p-b, q-a, b, a);
    iFilledRectangle(p+a, q-a, b, a);
    iFilledRectangle(p, q-a-b, a, b);
    iFilledRectangle(p, q-2*(a+b), a, b);
    iFilledRectangle(p+a, q-2*a-b, b, a);
}

void printDigit (int p,int q,int r)
{
    switch (r) {
        case 0:
            print0(p,q);
            break;
        case 1:
            print1(p,q);
            break;
        case 2:
            print2(p,q);
            break;
        case 3:
            print3(p,q);
            break;
        case 4:
            print4(p,q);
            break;
        case 5:
            print5(p,q);
            break;
        case 6:
            print6(p,q);
            break;
        case 7:
            print7(p,q);
            break;
        case 8:
            print8(p,q);
            break;
        case 9:
            print9(p,q);
            break;
    }
}

void printColon (int p, int q)
{
    iFilledRectangle(p, q-a, b, a/2);
    iFilledRectangle(p, q-2*a-b, b, a/2);
}

void iDraw() {
	iClear();
	drawTextBox();
	iSetColor(200, 200, 200);
	x=500,y=400;

	H=h%12;
	if (H==0) H=12;
    printDigit(x,y,H/10);
    printDigit(x+64,y,H%10);
    printColon(x+130,y);

    printDigit(x+150,y,mn/10);
    printDigit(x+214,y,mn%10);
    printColon(x+280,y);

    printDigit(x+300,y,s/10);
    printDigit(x+364,y,s%10);

    iSetColor(75,135,160);
    if (h>=12) iText(x+430,y-13,"PM",GLUT_BITMAP_TIMES_ROMAN_24);
    else iText(x+430,y-13,"AM",GLUT_BITMAP_TIMES_ROMAN_24);

	if (flag==3) {
	    x=100,y=400;
	    if (days==-1) {
	        iSetColor(250,0,0);
            iText(x,y,"Warning!",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,250,0);
            iText(x,y-40,"Your input is invalid!",GLUT_BITMAP_TIMES_ROMAN_24);
            iSetColor(0,0,250);
            iText(x,y-80,"Please, enter a valid input.",GLUT_BITMAP_TIMES_ROMAN_24);
	    }
	    else {
            printMonth ();
            iSetColor(50, 50, 250);

            iLine(x,y,x+7*c,y);
            iLine(x,y-c,x+7*c,y-c);
            iLine(x,y-2*c,x+7*c,y-2*c);
            iLine(x,y-3*c,x+7*c,y-3*c);
            iLine(x,y-4*c,x+7*c,y-4*c);
            iLine(x,y-5*c,x+7*c,y-5*c);
            iLine(x,y,x,y-5*c);
            iLine(x+c,y,x+c,y-5*c);
            iLine(x+2*c,y,x+2*c,y-5*c);
            iLine(x+3*c,y,x+3*c,y-5*c);
            iLine(x+4*c,y,x+4*c,y-5*c);
            iLine(x+5*c,y,x+5*c,y-5*c);
            iLine(x+6*c,y,x+6*c,y-5*c);
            iLine(x+7*c,y,x+7*c,y-5*c);

            iSetColor(20, 200, 0);
            iText(x+10,y+15,"SAT");
            iText(x+c+10,y+15,"SUN");
            iText(x+2*c+10,y+15,"MON");
            iText(x+3*c+10,y+15,"TUE");
            iText(x+4*c+10,y+15,"WED");
            iText(x+5*c+10,y+15,"THU");
            iText(x+6*c+10,y+15,"FRI");

            iSetColor(20, 200, 200);
            for (i=0;i<days;i++) {
                if (i<9) {
                    str[0]='0'+i+1;
                    str[1]='\0';
                }
                else {
                    str[0]='0'+(i+1)/10;
                    str[1]='0'+(i+1)%10;
                    str[2]='\0';
                }
                iText(x+((i+r)%7)*c+10,y-30-(((i+r)/7)%5)*c,str);
            }
	    }
	}

    iSetColor(200, 20, 10);
    iText(100,20,"Click any of the boxes to activate it, press enter to see output, r to reset.",GLUT_BITMAP_TIMES_ROMAN_24);
}

void iMouseMove(int mx, int my) {
	///printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (mx>=100 && mx<=200 && my>=50 && my<=80 && flag!=1) {
			flag=1;
		}
		else if (mx>=300 && mx<=400 && my>=50 && my<=80 && flag!=2) {
            flag=2;
		}
	}
}

void iKeyboard(unsigned char key) {
    if (key =='\r') {
        Y=strtoll(year,&ptr,10);
        m=strtoll(month,&ptr,10);

        days=Getdays();
        if (m==1 || m==2) {
            m+=12;
            Y-=1;
        }
        k=Y%100;
        j=Y/100;
        r=((1+(13*(m+1))/5+k+k/4+j/4+5*j)%7+7)%7;

        flag=3;
    }
    else if (key=='r') {
        year[0]='\0';
        month[0]='\0';
        idx1=0;
        idx2=0;
        flag=0;
    }

	if (flag==1) {
        if (key!='\b') {
            year[idx1]=key;
            year[++idx1]='\0';
        }
        else if (idx1>0) year[--idx1]='\0';
	}

	if (flag==2) {
        if (key!='\b') {
            month[idx2]=key;
            month[++idx2]='\0';
        }
        else if (idx2>0) month[--idx2]='\0';
	}
}

void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
}

void GetTime ()
{
    time_t mytime;
    struct tm *current_time;
    time (&mytime);
    current_time=localtime(&mytime);

    h=current_time->tm_hour;
    mn=current_time->tm_min;
    s=current_time->tm_sec;
}

void UpdateTime ()
{
    s++;
    mn+=s/60;
    s%=60;
    h+=mn/60;
    mn%=60;
    h%=24;
}

int main()
{
    GetTime();
    iSetTimer(1000,UpdateTime);
	iInitialize(1024, 576, "Clock_and_Calendar");
	return 0;
}
