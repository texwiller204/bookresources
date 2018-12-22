/*
   Cube Map Generator
   Created by Allen Sherrod
   Ultimate Game Engine Design and Architecture
*/


#include<iostream>
#include<TGA.h>

using namespace std;


int main(int args, char **arg)
{
   cout << "Cube Map Generator." << endl;
   cout << "Created by Allen Sherrod." << endl;
   cout << "Ultimate Game Engine Design and Architecture." << endl << endl;

   bool result = true;

   if(args < 7)
      {
         cout << "Not enough arguments defined." << endl;
         return 0;
      }

   if(arg[1] == NULL || arg[2] == NULL || arg[3] == NULL ||
      arg[4] == NULL || arg[5] == NULL || arg[6] == NULL ||
      arg[7] == NULL)
      {
         cout << "Error with one or more arugments!" << endl;
         return 0;
      }

   unsigned char *img1 = NULL, *img2 = NULL, *img3 = NULL,
                 *img4 = NULL, *img5 = NULL, *img6 = NULL;

   int w1 = 0, w2 = 0, w3 = 0, w4 = 0, w5 = 0, w6 = 0;
   int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0, h6 = 0;
   int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;

   img1 = LoadTGA(arg[1], w1, h1, c1);
   img2 = LoadTGA(arg[2], w2, h2, c2);
   img3 = LoadTGA(arg[3], w3, h3, c3);
   img4 = LoadTGA(arg[4], w4, h4, c4);
   img5 = LoadTGA(arg[5], w5, h5, c5);
   img6 = LoadTGA(arg[6], w6, h6, c6);

   if(img1 == NULL || img2 == NULL || img3 == NULL ||
      img4 == NULL || img5 == NULL || img6 == NULL)
      {
         cout << "One or more images not found." << endl;
         return 0;
      }

   if(w2 != w1 || w3 != w1 || w4 != w1 || w5 != w1 || w6 != w1)
      {
         cout << "Different width resolutions." << endl;
         result = false;
      }

   if(h2 != h1 || h3 != h1 || h4 != h1 || h5 != h1 || h6 != h1)
      {
         cout << "Different height resolutions." << endl;
         result = false;
      }

   if(c2 != c1 || c3 != c1 || c4 != c1 || c5 != c1 || c6 != c1)
      {
         cout << "Different components." << endl;
         result = false;
      }

   if(c1 != 3 && c1 != 4)
      {
         cout << "Not 24 or 32 bits in components." << endl;
         result = false;
      }

   FILE *fp = fopen(arg[7], "wb");

   if(fp == NULL)
      result = false;

   cout << "Images loaded." << endl;

   if(result != false)
      {
         int c = c1 * 8;

         fwrite(&w1, 1, sizeof(int), fp);
         fwrite(&h1, 1, sizeof(int), fp);
         fwrite(&c, 1, sizeof(int), fp);

         fwrite(img1, 1, w1 * h1 * c1, fp);
         fwrite(img2, 1, w1 * h1 * c1, fp);
         fwrite(img3, 1, w1 * h1 * c1, fp);
         fwrite(img4, 1, w1 * h1 * c1, fp);
         fwrite(img5, 1, w1 * h1 * c1, fp);
         fwrite(img6, 1, w1 * h1 * c1, fp);
      }
   else
      {
         cout << "ERROR" << endl;
      }

   fclose(fp);

   cout << "Cube Map Created." << endl;

   if(img1) delete[] img1;
   if(img2) delete[] img2;
   if(img3) delete[] img3;
   if(img4) delete[] img4;
   if(img5) delete[] img5;
   if(img6) delete[] img6;

   return 1;
}
