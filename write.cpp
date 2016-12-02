#include "write.h"

//declarations
int LIST_InsertHeadNode(Pixel_List_N **, int, int, int, int, int);
int ver2 = 0;

write::write(Pixel_List_N *head)
{

      QString filename = "out.txt";
      QFile file(filename);
      int arr[3][6] = {{1,2,43,6,7,4},{2,3,5,43,3,4},{6,7,2,1,63,24}};
      /*for(int p = 0; p < 3; p++){
          for(int q = 0; q < 6; q++){
              arr[height][width] = height + width;
          }
      }*/
      int height = 798, width = 12;
      int headarr[789][12];
      for(int y = 0; y < height; y++){
          for(int z = 0; z < width; z++){
              headarr[y][z] = y + z;
          }
      }
      if(file.open(QIODevice::WriteOnly | QIODevice::Text))
      {
          // We're going to streaming text to the file
          QTextStream stream( &file );
          for(int i = 0; i < height; i++){
              for(int j = 0; j < width; j++){
                  stream << headarr[i][j] << " ";
              }
              stream << endl;
              if((i+1) % 10 == 0){
                  stream << endl;
              }
          }
          file.close();
      }
      //qDebug() << "Writing finished";
  }
}
