#include<reg51.h>

#define sevseg1 P0 //labelling port 0 as seven segment 1(sevsesg1)
#define sevseg2 P2 //labelling port 2 as seven segment 2(sevsesg2)


sbit Hred=P1^3;   // setting horizontal road red LED to port 1 pin 3
sbit Hyellow=P1^4;  // setting horizontal road yellow LED to port 1 pin 4
sbit Hgrn=P1^5;     // setting horizontal road green LED to port 1 pin 5

sbit Vred=P1^0;	   // setting vertical road red LED to port 1 pin 0
sbit Vyellow=P1^1;  // setting vertical road yellow LED to port 1 pin 1
sbit Vgrn=P1^2;	    // setting vertical road green LED to port 1 pin 2

sbit Hsen1=P3^0;    // setting horizontal road first sensor to port 3 pin 0
sbit Hsen2=P3^1;    // setting horizontal road second sensor to port 3 pin 1
sbit Hsen3=P3^2;    // setting horizontal road third sensor to port 3 pin 2

sbit Vsen1=P3^3;   // setting vertical road first sensor to port 3 pin 3
sbit Vsen2=P3^4;   // setting vertical road second sensor to port 3 pin 4
sbit Vsen3=P3^5;   // setting vertical road third sensor to port 3 pin 5


void delay(unsigned int timeCounter)  // this function is used as timer in program
{ while(timeCounter--); }

void display1(int c)  // this function used to dislay 1-9 digits on first seven seven segment(common anode display)
 {

  	 if(c==0)
	   sevseg1=0xff-0x3f;  // shows digit 0
   	else if(c==1) 
	   sevseg1=0xff-0x06;  // shows digit 1
    else if(c==2) 
	 sevseg1=0xff-0x5b;   // shows digit 2
    else if(c==3) 
	 sevseg1=0xff-0x4f;   // shows digit 3
    else if(c==4) 
	 sevseg1=0xff-0x66;   // shows digit 4
    else if(c==5) 
	 sevseg1=0xff-0x6d;   // shows digit 5
    else if(c==6) 
	 sevseg1=0xff-0x7d;   // shows digit 6
    else if(c==7) 
	 sevseg1=0xff-0x07;   // shows digit 7
    else if(c==8) 
	 sevseg1=0xff-0x7f;   // shows digit 8
    else if(c==9) 
	 sevseg1=0xff-0xef;   // shows digit 9	
 }

void display2(int c)   // this function used to dislay 1-9 digits on second seven seven segment(common anode display)
 {

  	 if(c==0)
	   sevseg2=0xff-0x3f;  // shows digit 0
   	else if(c==1) 
	   sevseg2=0xff-0x06;  // shows digit 1
    else if(c==2) 
	 sevseg2=0xff-0x5b;   // shows digit 2
    else if(c==3) 
	 sevseg2=0xff-0x4f;   // shows digit 3
    else if(c==4) 
	 sevseg2=0xff-0x66;   // shows digit 4
    else if(c==5) 
	 sevseg2=0xff-0x6d;  // shows digit 5
    else if(c==6) 
	 sevseg2=0xff-0x7d;   // shows digit 6
    else if(c==7) 
	 sevseg2=0xff-0x07;   // shows digit 7
    else if(c==8) 
	 sevseg2=0xff-0x7f;   // shows digit 8
    else if(c==9) 
	 sevseg2=0xff-0xef;   // shows digit 9	
 }





void main()
{ int yellowH,grnH,yellowV,grnV,i,j; //variables to carry time data 


  while(1) // start block, alway keep looping itself 
   {
	yellowH=2; yellowV=2;
	
//-----------------------------------------Section 1(start)------------------------------------------------

	if(Hsen1==1&&Hsen2==1&&Hsen3==1) // all horizontal road sensor are OFF
	  {grnH=3; }
	else if(Hsen1==0&&Hsen2==1&&Hsen3==1)  // horizontal road first sensor are ON
	  {grnH=5; }
	else if(Hsen1==0&&Hsen2==0&&Hsen3==1)  // horizontal road first and second sensor are ON
	  {grnH=7; }
	else if(Hsen1==0&&Hsen2==0&&Hsen3==0)   // horizontal road first,second, third sensor are ON
	  {grnH=9; }

	if(Vsen1==1&&Vsen2==1&&Vsen3==1)  // all vertical road sensor are OFF
	  {grnV=3; }
	else if(Vsen1==0&&Vsen2==1&&Vsen3==1)  // vertical road first sensor are ON
	  {grnV=5; }
	else if(Vsen1==0&&Vsen2==0&&Vsen3==1)    // vertical road first and second sensor are ON
	  {grnV=7; }
	else if(Vsen1==0&&Vsen2==0&&Vsen3==0)    // vertical road first,second, third sensor are ON
	  {grnV=9; }

   Hred=1; Hyellow=1; Hgrn=1;  // swiching vertical road red, yellow, green LED off
   Vred=1; Vyellow=1; Vgrn=1;  // switching horizontal road red, yellow, green LED off

   i=grnV+yellowV;
   j=grnV;
   Hred=0;  //switching horizontal road red LED ON
   Vgrn=0;  //switching vertical road green LED ON
   while(j>=1) 
    {  
	  display1(i);
	  display2(j);
	  i--; j--;
	  delay(60000);
	  delay(60000);
	  delay(60000);

	}
   Vgrn=1; // switching horizontal road red LED OFF
   Vyellow=0;  // switching vertical road yellow LED ON
   j=yellowV;
   while(j>=1)
    {  
	  display1(i);
	  display2(j);
	  i--;	j--;
	  delay(60000);
	  delay(60000);
	  delay(60000);
	}
   Hred=1; // switching horizontal road red LED OFF
   Vyellow=1;  // switching Vertical road yellow LED OFF

//--------------------------------Setion-1(End)------------------------------------------------


// -------------------------------------Section-2(start)---------------------------------------
       if(Hsen1==1&&Hsen2==1&&Hsen3==1)  // all horizontal road sensor are OFF
	  {grnH=3; }
	else if(Hsen1==0&&Hsen2==1&&Hsen3==1)  // horizontal road first sensor are ON
	  {grnH=5; }
	else if(Hsen1==0&&Hsen2==0&&Hsen3==1)  // horizontal road first and second sensor are ON
	  {grnH=7; }
	else if(Hsen1==0&&Hsen2==0&&Hsen3==0)   // horizontal road first,second, third sensor are ON
	  {grnH=9; }

	if(Vsen1==1&&Vsen2==1&&Vsen3==1)    // all vertical road sensor are OFF
	  {grnV=3; }
	else if(Vsen1==0&&Vsen2==1&&Vsen3==1)   // vertical road first sensor are ON
	  {grnV=5; }
	else if(Vsen1==0&&Vsen2==0&&Vsen3==1)   // vertical road first and second sensor are ON
	  {grnV=7; }
	else if(Vsen1==0&&Vsen2==0&&Vsen3==0)    // vertical road first,second, third sensor are ON
	  {grnV=9; }



   i=grnH+yellowH;
   j=grnH;
   Vred=0;  //switching vertical road red LED ON
   Hgrn=0;  //switching horizontal road green LED ON
   while(j>=1)
    {  
	  display2(i);
	  display1(j);
	  i--;	j--;
	  delay(60000);
	  delay(60000);
	  delay(60000);
	}
   Hgrn=1; //switching horizontal road green LED OFF
   Hyellow=0;  //switching horizonatl road yellow LED ON
   j=yellowH;
   while(j>=1)
    {  
	  display2(i);
	  display1(j);
	  i--;	j--;
	  delay(60000);
	  delay(60000);
	  delay(60000);
	}
   Vred=1; //swtiching Vertical road red LED OFF
   Hyellow=1;  //switching horizontal road yellow LED OFF
//------------------------section-2(end)------------------------------------------------   
}}