#ifndef STRUCT_H
#define STRUCT_H
#include<stdlib.h>

#endif // STRUCT_H

typedef struct {
 unsigned char* Data;
 char* name;
 } myStruct;

typedef struct Layout{
    int Frame_ct;
    int Height;
    int Width;
}Layout_N;

typedef struct Pixel{
   int R;
   int G;
   int B;
   int X;
   int Y;
   int CT;
}Pixel_N;

/* ADAPTED FROM http://stackoverflow.com/questions
 * /23279119/creating-and-understanding-linked-lists-of-
 * structs-in-c */

typedef struct Pixel_List
   {
   /* Next-node pointer */
   struct Pixel_List *next;              /* pointer to the next node in the list. */
     Pixel_N payload;          /* Data Payload (defined by coder) */

   }Pixel_List_N;


int LIST_InsertHeadNode(
      Pixel_List_N **IO_head,
        int        RED,
        int        GREEN,
        int        BLUE,
        int        X_VAL,
        int        Y_VAL,
        int         CT
           )
        {
        int rCode=0;
        Pixel_List_N *newNode;
        newNode = (Pixel_List_N *)malloc(sizeof *newNode) ;
        /* Allocate memory for new node (with its payload). */
        //newNode=malloc(sizeof *newNode);
        if(NULL == newNode)
           {
           rCode=ENOMEM;   /* ENOMEM is defined in errno.h */
           fprintf(stderr, "malloc() failed.\n");
           goto CLEANUP;
        }

      /* Initialize the new node's payload. */
        newNode->payload.R = RED;
        newNode->payload.G = GREEN;
        newNode->payload.B = BLUE;
        newNode->payload.X = X_VAL;
        newNode->payload.Y = Y_VAL;
        newNode->payload.CT = CT;


      //newNode->payload.hours = I__hours;
      //newNode->payload.workordernum = I__workordernum;

      /* Link this node into the list as the new head node. */
      newNode->next = *IO_head;
      *IO_head = newNode;

   CLEANUP:

      return(rCode);
      }

int* PrintPixels(Pixel_List_N *head){
   int rCode=0;
   Pixel_List_N *cur = head;
   int nodeCnt=0;
   int r[1000];

   while(cur)
      {
      ++nodeCnt;
      r[cur->payload.CT] = cur->payload.R;
      //printf("r %d %d", cur->payload.CT, r[cur->payload.CT]);
      printf("R:%d, G:%d, B:%d, X:%d, Y:%d Frame_CT:%d\n",
            cur->payload.R,
            cur->payload.G,
            cur->payload.B,
            cur->payload.X,
            cur->payload.Y,
            cur->payload.CT
            );
       cur=cur->next;
       }

   // printf("%d nodes printed.\n", nodeCnt);

   return r;
   }

int getR(Pixel_List_N *head){
   int rCode=0;
   Pixel_List_N *cur = head;
   int nodeCnt=0;
   int r[1000];

   while(cur)
      {
      ++nodeCnt;

      r[nodeCnt] = cur->payload.R;
      printf("r %d %d", nodeCnt, r[nodeCnt]);
           // cur->payload.G,
         //   cur->payload.B,
         //   cur->payload.X,
         //   cur->payload.Y,
         //   cur->payload.CT

       cur=cur->next;
       }

   // printf("%d nodes printed.\n", nodeCnt);
    //return(*r);
   return(rCode);
   }
/*end of adapted from */
