#ifndef STRUCT_H
#define STRUCT_H
#include<stdlib.h>
#include<QTCore>

#endif // STRUCT_H

typedef struct
{
 unsigned char* Data;
 char* name;
}myStruct;

typedef struct Layout
{
    int Frame_ct;
    int Height;
    int Width;
}Layout_N;

typedef struct loadPixel
{
   int R;
   int G;
   int B;
   int X;
   int Y;
   int CT;

   int getRval() const;
   int getGval() const;
   int getBval() const;
   int getXval() const;
   int getYval() const;
   int getCTval() const;

}Pixel_N;

//used for printing out the values of the pixels
int loadPixel::getRval() const
{
  return R;
}
int loadPixel::getGval() const
{
  return G;
}
int loadPixel::getBval() const
{
  return B;
}
int loadPixel::getXval() const
{
  return X;
}
int loadPixel::getYval() const
{
  return Y;
}
int loadPixel::getCTval() const
{
  return CT;
}


/* ADAPTED FROM http://stackoverflow.com/questions
 * /23279119/creating-and-understanding-linked-lists-of-
 * structs-in-c */


typedef struct Pixel_List
  {
   /* Next-node pointer */
   struct Pixel_List *next;              /* pointer to the next node in the list. */
    Pixel_N payload;          /* Data Payload (defined by coder) */

  }Pixel_List_N;




/*end of adapted from */
