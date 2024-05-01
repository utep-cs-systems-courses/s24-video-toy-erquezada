
#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "myDraws.h"
#include "led.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "buzzer.h"
#include "stateMachine.h"

void funnyFace()
{
  int posRow = 20;
  int posCol= 20;
  int i;
  //lentes
  fillRectangle(20,30,30,30,COLOR_BLACK);
  fillRectangle(80,30,30,30,COLOR_BLACK);
  //conector
  for(int i = 0;i<45;i++)
  {
    drawPixel(90+i,30,COLOR_BLACK);
    drawPixel(30+i,30,COLOR_BLACK);
    drawPixel(50+i,40,COLOR_BLACK);
  }
  //nouse
  posCol = 40;
  posRow = 90;
  for(int i = 0; i<30; i++)
  {
    drawPixel(posCol+i,posRow-i,COLOR_ORANGE);
    drawPixel(posCol+i,posRow,COLOR_ORANGE);
  }
  //mouth
  posCol = 30;
  posRow = 120;
  for(int i = 0; i<70; i++)
  {
    drawPixel(posCol+i,posRow,COLOR_ORANGE);
    drawPixel(posCol+i,posRow,COLOR_ORANGE);
  }

  for(int i = 0; i<5; i++)
  {
    drawPixel(posCol-i,posRow-i,COLOR_ORANGE);
    drawPixel(posCol+67+i,posRow-i,COLOR_ORANGE);
  }
    

}//method ends




void dayHouse()
{
  int change = globalCounter();
  int astroSize = 30; // Size of the sun (square)
   // Draw the background
   fillRectangle(0, 0, 150, 180, COLOR_SKY_BLUE);


   //draw astro
   fillRectangle(10,10,astroSize,astroSize,COLOR_YELLOW); 

  if (change % 2 == 0)
    {
     astroSize =15;
     fillRectangle(0, 0, 150, 180, COLOR_BLUE);
     fillRectangle(10,10,astroSize,astroSize,COLOR_WHITE);
    }
  // Draw the house
  fillRectangle(40, 90, 75, 75, COLOR_CHOCOLATE); // Body of the house
  fillRectangle(60, 130, 20, 30, COLOR_RED);      // Door
  fillRectangle(55, 100, 50, 20, COLOR_GREEN);    // Window 1
  // Draw the roof (I'm assuming you want to draw a triangle-like roof)
  int roofX1 = 40;
  int roofX2 = 115;
  int roofY = 90;
  for (int i = 0; i < 38; i++)
    {
      drawLine(roofX1 + i, roofY, 77, 50 + i, COLOR_BROWN);
      drawLine(roofX2 - i, roofY, 77, 50 + i, COLOR_BROWN);
    }
}


void drawLine(int x0, int y0, int x1, int y1, int color)
{
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = (x0 < x1) ? 1 : -1;
  int sy = (y0 < y1) ? 1 : -1;
  int err = dx - dy;

  while (1)
  {
    drawPixel(x0, y0, color);
    if (x0 == x1 && y0 == y1)
      break;
    int e2 = 2 * err;
    if (e2 > -dy)
    {
      err -= dy;
      x0 += sx;
    }
    if (e2 < dx)
    {
      err += dx;
      y0 += sy;
    }
  }
}


void mainScreen(){
  drawString5x7(10,10,"TAKE A BREAK :D",COLOR_BLACK,COLOR_WHITE);
  drawString5x7(10,50,"UNTIL THE SCREEN ",COLOR_DARK_GREEN,COLOR_WHITE);
  drawString5x7(10,80," IS TOTALLY RED :D",COLOR_DARK_GREEN,COLOR_WHITE);
  __delay_cycles(10000);
  int random1,random2;
  while(1){ ;
    random1 = rand()%100000000 ; // Generates a number in the range [0, 120]
    random2 = rand()%100000000; // Generates a number in the range [0, 120]
    fillRectangle(random1 ,random2,1,1,COLOR_RED);
  }
}



void drawCow() {
    clearScreen(COLOR_GREEN);
  
    // Draw a simple representation of a cow using basic shape   
    // Body
    fillRectangle(30, 50, 90, 30, COLOR_BROWN);
    
    // Head
    fillRectangle(50, 30, 20, 20, COLOR_WHITE);
    fillRectangle(50, 30, 5, 5, COLOR_BLACK);  // Eyes
    fillRectangle(65, 30, 5, 5, COLOR_BLACK);
    fillRectangle(55, 35, 10, 5, COLOR_BLACK); // Mouth
    
    // Legs
    fillRectangle(40, 80, 10, 20, COLOR_BLACK);
    fillRectangle(60, 80, 10, 20, COLOR_BLACK);
    fillRectangle(80, 80, 10, 20, COLOR_BLACK);
    fillRectangle(100, 80, 10, 20, COLOR_BLACK);
}
